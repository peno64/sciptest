#include <iostream>
#include <scip/scip.h>
#include <scip/scipdefplugins.h>

SCIP_RETCODE execmain(int argc, const char **argv)
{
	SCIP *scip = nullptr;

	// This program needs the scip libraries and binaries. They can be downloaded from https://www.scipopt.org/index.php#download (precompiled packages)
	// Make sure that the bin folder is in the path and change the project properies
	//   C/C++, Additional include directories
	//   Linker, Additional library directories

	//See https://scipopt.org/doc/html/group__GlobalProblemMethods.php
	
	SCIP_CALL(SCIPcreate(&scip));  //Creating the SCIP environment

	/* include default plugins */
	SCIP_CALL(SCIPincludeDefaultPlugins(scip));

	//Creating the SCIP Problem.
	SCIP_CALL(SCIPcreateProbBasic(scip, "SCIP_test"));

	SCIP_CALL(SCIPsetObjsense(scip, SCIP_OBJSENSE_MAXIMIZE));

	SCIP_VAR *x1 = nullptr;

	SCIP_CALL(SCIPcreateVarBasic(scip,
		&x1,                     // returns new index
		"x1",                      // name
		1.1,                      // lower bound
		SCIPinfinity(scip),       // upper bound
		3.0,                      // objective
		SCIP_VARTYPE_CONTINUOUS  /* SCIP_VARTYPE_INTEGER */));  // variable type


	SCIP_CALL(SCIPaddVar(scip, x1));  //Adding the first variable

	SCIP_VAR *x2 = nullptr;;

	SCIP_CALL(SCIPcreateVarBasic(scip,
		&x2,                     // returns new index
		"x2",                      // name
		0.0,                      // lower bound
		SCIPinfinity(scip),       // upper bound
		0.0,                      // objective
		SCIP_VARTYPE_CONTINUOUS));  // variable type

	SCIP_CALL(SCIPaddVar(scip, x2)); //Adding the second variable

	SCIP_CALL(SCIPaddVarObj(scip, x2, 2.0));

	SCIP_CONS *cons1 = nullptr;

	SCIP_CALL(SCIPcreateConsBasicLinear(scip,                 // SCIP pointer
		&cons1,               // pointer to SCIP constraint
		"cons1",              // name of the constraint
		0,                    // How many variables are you adding  now
		nullptr,              // an array of pointers to various variables
		nullptr,              // an array of values of the coefficients of the corresponding vars
		-SCIPinfinity(scip),  // LHS of the constraint
		4));                  // RHS of the constraint

	SCIP_CALL(SCIPaddCoefLinear(scip, cons1, x1, 1.0));     //Adding the variable x1 with A matrix coeffient of 1.0
	SCIP_CALL(SCIPaddCoefLinear(scip, cons1, x2, 1.0));     //Adding the variable x2 with A matrix coeffient of 1.0
	SCIP_CALL(SCIPaddCons(scip, cons1));

	SCIP_CONS *cons2 = nullptr;

	SCIP_CALL(SCIPcreateConsBasicLinear(scip,
		&cons2,
		"cons2",
		0,
		nullptr,
		nullptr,
		-SCIPinfinity(scip),
		5));

	SCIP_CALL(SCIPaddCoefLinear(scip, cons2, x1, 2.0));
	SCIP_CALL(SCIPaddCoefLinear(scip, cons2, x2, 1.0));
	SCIP_CALL(SCIPaddCons(scip, cons2));

	SCIP_CONS *cons3 = nullptr;

#if 0
	SCIP_CALL(SCIPcreateConsBasicLinear(scip,
		&cons3,
		"cons3",
		0,
		nullptr,
		nullptr,
		-SCIPinfinity(scip),
		-2.0));

	SCIP_CALL(SCIPaddCoefLinear(scip, cons3, x1, 1.0));
	SCIP_CALL(SCIPaddCoefLinear(scip, cons3, x2, -4.0));
#else
	// see https://scipopt.org/doc/html/group__CONSHDLRS.php#ga7b45524275d46ba74c01613381910901
	SCIP_VAR *px[] = { x1, x2 };
	double row[] = { -1.0, 4.0 };
	SCIP_CALL(SCIPcreateConsBasicLinear(scip,
		&cons3,
		"cons3",
		2,
		px,
		row,
		2.0,
		SCIPinfinity(scip)));
#endif
	SCIP_CALL(SCIPaddCons(scip, cons3));

	SCIP_CONS *cons4 = nullptr;;
	SCIP_EXPR *expr4;
	double b = 3.14;

	// https://scipopt.org/doc/html/group__PublicExprMethods.php#ga08ead2626a292a7bf86e7c9a5f09f4c8
	SCIP_CALL(SCIPcreateExprQuadratic(scip, &expr4, 0, nullptr, nullptr, 1, &x1, &x2, &b, NULL, NULL));

	// https://scipopt.org/doc/html/group__CONSHDLRS.php#ga97f2ccf48759b477a9c8cc2461c044e9
	SCIP_CALL(SCIPcreateConsBasicNonlinear(scip, &cons4, "cons4", expr4, -SCIPinfinity(scip), 9.6));

	SCIP_CALL(SCIPreleaseExpr(scip, &expr4));

	SCIP_CALL(SCIPaddCons(scip, cons4));

#if 1
	SCIP_CALL(SCIPsetBoolParam(scip, "lp/presolving", 0)); /* turns presolve off */
	SCIP_CALL(SCIPsetBoolParam(scip, "concurrent/presolvebefore", 0)); /* turns presolve off */
	SCIP_CALL(SCIPsetIntParam(scip, "presolving/maxrounds", 0)); /* turns presolve off */
#endif

	SCIP_CALL(SCIPsetRealParam(scip, "numerics/feastol", 1e-8));
	SCIP_CALL(SCIPsetRealParam(scip, "numerics/epsilon", 1e-8));
	SCIP_CALL(SCIPsetRealParam(scip, "numerics/dualfeastol", 1e-8));

	SCIP_CALL(SCIPsetRealParam(scip, "limits/gap", 1e-6));

	//Solving the problem
	SCIP_CALL(SCIPsolve(scip));

	SCIP_SOL *sol = nullptr;

	sol = SCIPgetBestSol(scip);

	std::cout << "x1: " << SCIPgetSolVal(scip, sol, x1) << " " << "x2: " << SCIPgetSolVal(scip, sol, x2) << "\n";

	int n = SCIPgetNOrigVars(scip);

	SCIP_VAR **vars;

	//vars = SCIPgetVars(scip);

	unsigned int isDualSolAvailable = SCIPisDualSolAvailable(scip, TRUE);

	double a;

	if (isDualSolAvailable)
	{
		double dualsolval;
		unsigned int boundconstraint;
		SCIPgetDualSolVal(scip, cons1, &dualsolval, &boundconstraint);
		SCIPgetDualSolVal(scip, cons2, &dualsolval, &boundconstraint);

		a = SCIPgetVarRedcost(scip, x1);
	}

	a = 3.14 * SCIPgetSolVal(scip, sol, x1) * SCIPgetSolVal(scip, sol, x2);

	//SCIPprintBestSol(scip, stdout, TRUE);

	SCIP_CALL((SCIPwriteOrigProblem(scip, "sciptest.lp", nullptr, FALSE)));
	SCIP_CALL((SCIPwriteOrigProblem(scip, "sciptest.mps", nullptr, FALSE)));

	SCIP_CALL((SCIPwriteTransProblem(scip, "sciptest2.lp", nullptr, FALSE)));

	//Scip releasing all the constraints
	SCIP_CALL(SCIPreleaseCons(scip, &cons1));
	SCIP_CALL(SCIPreleaseCons(scip, &cons2));
	SCIP_CALL(SCIPreleaseCons(scip, &cons3));
	SCIP_CALL(SCIPreleaseCons(scip, &cons4));

	//Freeing the variables
	SCIP_CALL(SCIPreleaseVar(scip, &x1));
	SCIP_CALL(SCIPreleaseVar(scip, &x2));

	SCIP_CALL(SCIPfree(&scip));

	return SCIP_OKAY;
}

int main(int argc, const char *argv[])
{
	return execmain(argc, argv) != SCIP_OKAY ? 1 : 0;
}