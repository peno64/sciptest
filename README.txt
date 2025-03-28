scip test/demo program.
The c batch file compiles the program with the Microsoft Visual C++ compiler and links it with the scip library.
Change the scip environment variable in the batch file to the scip path
To run the program the path environment variable must be changed to include the scip bin folder

Build scip yourself (windows):

-Boost
https://www.boost.org/
	download boost_x_y_z.zip 
	unzip to \boost
	cd \boost
	bootstrap.bat
	b2 install

-scip
https://scipopt.org/#download
	download scipoptsuite-x.y.z.tgz
	unzip
  cd \scipoptsuite-x.y.z
	md build
	cd build
	cmake .. -DCMAKE_INSTALL_PREFIX=install -DSOPLEX_DIR=..\soplex -DPAPILO_DIR=..\papilo -DBOOST_ROOT=\boost -DZLIB=OFF -DREADLINE=OFF -DTBB=OFF -DIPOPT=OFF -DGMP=OFF
	cmake --build . --config Release

  This does generate some errors but only for tests that are not really needed
  scip is build and seems to work

  Note that ipopt should also be included but here it is not.
  it's complex to make this possible
