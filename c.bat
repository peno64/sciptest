@echo off
set scip=C:\SCIPOptSuite 8.0.3
cl /EHsc /I "%scip%\include" "%scip%\lib\libscip.lib" main.cpp sciptest1.cpp sciptest2.cpp
