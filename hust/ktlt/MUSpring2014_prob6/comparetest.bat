@echo off
for /l %%i in (1, 1, 100) do (
	copy %%i.inp LIS.inp
	LIS.exe
	fc LIS.out %%i.out
	if errorlevel 1 goto :eof
	echo Test %%i correct
)