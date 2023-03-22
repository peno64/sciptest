@echo off
set scip=C:\SCIPOptSuite 8.0.3
cl /EHsc /I "%scip%\include" "%scip%\lib\libscip.lib" sciptest.cpp
