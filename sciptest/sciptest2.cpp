#include <scip/scip.h>
#include <scip/scipdefplugins.h>

int sciptest2()
{
    {
        SCIP_RETCODE ret;
        SCIP *scip = nullptr;
        SCIP_VAR *var = nullptr;
        SCIP_EXPR *expr = nullptr;
        SCIP_CONS *cons = nullptr;
        SCIP_SOL *sol = nullptr;
        int nvars = 0;
        SCIP_VAR **allvars = nullptr;
        int ncons = 0;
        SCIP_CONS **allcons = nullptr;
        ret = SCIPcreate(&scip);
        ret = SCIPincludeDefaultPlugins(scip);
        ret = SCIPcreateProbBasic(scip, "scip");
        ret = SCIPcreateVarBasic(scip, &var, "x_8083_15907", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[0]);
        ret = SCIPcreateVarBasic(scip, &var, "RC_8083_x_8885_15907", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[1]);
        ret = SCIPcreateVarBasic(scip, &var, "RC_8083_x_8885_22247", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[2]);
        ret = SCIPcreateVarBasic(scip, &var, "RC_8083_x_8885_16735", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[3]);
        {
            double vals[3] =
            {
                0.891,
                -0.009,
                -0.009,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885IngAmountRecipe15907Min", 3, vars, vals, 0, 1E+20);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[0]);
        {
            double vals[3] =
            {
                0.09,
                -0.81,
                -0.81,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885IngAmountRecipe15907Max", 3, vars, vals, -1E+20, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[1]);
        {
            double vals[3] =
            {
                0.054,
                -0.846,
                -0.846,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[2],
                allvars[1],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885IngAmountRecipe22247Max", 3, vars, vals, -1E+20, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[2]);
        {
            double vals[3] =
            {
                0.0891000000000001,
                -0.8109,
                -0.8109,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[3],
                allvars[1],
                allvars[2],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885IngAmountRecipe16735Max", 3, vars, vals, -1E+20, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[3]);
        {
            double vals[3] =
            {
                -0.0099,
                -0.0099,
                -0.0099,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885InternalMainSumAbsolute1Max", 3, vars, vals, -1E+20, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[4]);
        {
            double vals[3] =
            {
                -0.29,
                -0.127,
                -0.354,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC_8083_RC8885NutrOnProduct751Max", 3, vars, vals, -1E+20, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[5]);
        {
            double vals[4] =
            {
                3.64963503649635,
                3.64963503649635,
                1.66666666666667,
                1.53846153846154,
            };
            SCIP_VAR *vars[4] =
            {
                allvars[0],
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC8083NutrOnProduct304", 4, vars, vals, 0.001, 99);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[6]);
        {
            double vals[4] =
            {
                0.045,
                0.045,
                0.125,
                0.021,
            };
            SCIP_VAR *vars[4] =
            {
                allvars[0],
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC8083NutrOnProduct517", 4, vars, vals, -1E+20, 0.99);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[7]);
        {
            double vals[4] =
            {
                1,
                0.9,
                0.9,
                0.9,
            };
            SCIP_VAR *vars[4] =
            {
                allvars[0],
                allvars[1],
                allvars[2],
                allvars[3],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "RC8083Total", 4, vars, vals, 1, 1);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[8]);
        ret = SCIPcreateVarBasic(scip, &var, "Consumption_Site_11_x_15907", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[4]);
        ret = SCIPchgVarLb(scip, allvars[4], 0);
        ret = SCIPchgVarUb(scip, allvars[4], 1E+20);
        {
            double vals[2] =
            {
                -1,
                100000,
            };
            SCIP_VAR *vars[2] =
            {
                allvars[4],
                allvars[0],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "Consumption1_Site_11_x_15907", 2, vars, vals, 0, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[9]);
        ret = SCIPcreateVarBasic(scip, &var, "Market_Site_11_x_15907", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[5]);
        ret = SCIPchgVarLb(scip, allvars[5], 0);
        ret = SCIPchgVarUb(scip, allvars[5], 1E+20);
        ret = SCIPcreateVarBasic(scip, &var, "Stock_Site_11_x_15907", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[6]);
        ret = SCIPchgVarLb(scip, allvars[6], 0);
        ret = SCIPchgVarUb(scip, allvars[6], 0);
        {
            double vals[3] =
            {
                -1,
                -1,
                1,
            };
            SCIP_VAR *vars[3] =
            {
                allvars[5],
                allvars[6],
                allvars[4],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "Consumption2_Site_11_x_15907", 3, vars, vals, 0, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[10]);
        ret = SCIPchgVarObj(scip, allvars[1], 681744.31);
        ret = SCIPchgVarObj(scip, allvars[2], 36305.91);
        ret = SCIPchgVarObj(scip, allvars[3], 26220935);
        ret = SCIPchgVarObj(scip, allvars[6], 6.050985);
        ret = SCIPchgVarObj(scip, allvars[5], 6.8174431);
        ret = SCIPsetObjsense(scip, (SCIP_OBJSENSE)1);
        ret = SCIPwriteOrigProblem(scip, "c:\\temp\\LPSolve1.mps", NULL, 0);
        ret = SCIPwriteOrigProblem(scip, "c:\\temp\\LPSolve1.lp", NULL, 0);
        ret = SCIPsolve(scip);
        {
            SCIP_STATUS status = SCIPgetStatus(scip);
            status = status;
        }
        sol = SCIPgetBestSol(scip);
        {
            double x = SCIPgetSolVal(scip, sol, allvars[0]);
            x = x;
        }
        {
            double x = SCIPgetSolVal(scip, sol, allvars[1]);
            x = x;
        }
        {
            double x = SCIPgetSolVal(scip, sol, allvars[2]);
            x = x;
        }
        {
            double x = SCIPgetSolVal(scip, sol, allvars[3]);
            x = x;
        }
        {
            double obj = SCIPgetDualbound(scip);
            obj = obj;
        }

        ret = SCIPfreeTransform(scip);
        ret = SCIPenableReoptimization(scip, 0);
        ret = SCIPfreeReoptSolve(scip);

        ret = SCIPcreateVarBasic(scip, &var, "Objective", 0, 1E+20, 0, (SCIP_VARTYPE)3);
        if ((nvars % 100) == 0)
        {
            if (nvars == 0)
                allvars = (SCIP_VAR **)malloc(100 * sizeof(*allvars));
            else
                allvars = (SCIP_VAR **)realloc(allvars, (nvars + 100) * sizeof(*allvars));
        }
        allvars[nvars++] = var;
        ret = SCIPaddVar(scip, allvars[7]);
        {
            double vals[6] =
            {
                681744.31,
                36305.91,
                26220935,
                6.050985,
                6.8174431,
                -1,
            };
            SCIP_VAR *vars[6] =
            {
                allvars[1],
                allvars[2],
                allvars[3],
                allvars[6],
                allvars[5],
                allvars[7],
            };
            ret = SCIPcreateConsBasicLinear(scip, &cons, "Objective", 6, vars, vals, 0, 0);
        }
        if ((ncons % 100) == 0)
        {
            if (ncons == 0)
                allcons = (SCIP_CONS **)malloc(100 * sizeof(*allcons));
            else
                allcons = (SCIP_CONS **)realloc(allcons, (ncons + 100) * sizeof(*allcons));
        }
        allcons[ncons++] = cons;
        ret = SCIPaddCons(scip, allcons[11]);
        ret = SCIPchgVarLb(scip, allvars[6], 0);
        ret = SCIPchgVarUb(scip, allvars[6], 500);
        ret = SCIPwriteOrigProblem(scip, "c:\\temp\\LPSolve2.mps", NULL, 0);
        ret = SCIPwriteOrigProblem(scip, "c:\\temp\\LPSolve2.lp", NULL, 0);

        ret = SCIPsolve(scip);
        {
            SCIP_STATUS status = SCIPgetStatus(scip);
            status = status;
        }
        ret = SCIPreleaseCons(scip, &allcons[0]);
        ret = SCIPreleaseCons(scip, &allcons[1]);
        ret = SCIPreleaseCons(scip, &allcons[2]);
        ret = SCIPreleaseCons(scip, &allcons[3]);
        ret = SCIPreleaseCons(scip, &allcons[4]);
        ret = SCIPreleaseCons(scip, &allcons[5]);
        ret = SCIPreleaseCons(scip, &allcons[6]);
        ret = SCIPreleaseCons(scip, &allcons[7]);
        ret = SCIPreleaseCons(scip, &allcons[8]);
        ret = SCIPreleaseCons(scip, &allcons[9]);
        ret = SCIPreleaseCons(scip, &allcons[10]);
        ret = SCIPreleaseCons(scip, &allcons[11]);
        ret = SCIPreleaseVar(scip, &allvars[0]);
        ret = SCIPreleaseVar(scip, &allvars[1]);
        ret = SCIPreleaseVar(scip, &allvars[2]);
        ret = SCIPreleaseVar(scip, &allvars[3]);
        ret = SCIPreleaseVar(scip, &allvars[4]);
        ret = SCIPreleaseVar(scip, &allvars[5]);
        ret = SCIPreleaseVar(scip, &allvars[6]);
        ret = SCIPreleaseVar(scip, &allvars[7]);
        ret = SCIPfree(&scip);
        if (allvars != NULL) free(allvars);
        if (allcons != NULL) free(allcons);
    }

    return 0;
}