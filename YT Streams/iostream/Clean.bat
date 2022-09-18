@echo off

echo Cleaning...

1>nul 2>nul rd /S /Q .\bin
1>nul 2>nul rd /S /Q .\bin-int

1>nul 2>nul del /F /S /Q *.vcxproj
1>nul 2>nul del /F /S /Q *.vcxproj.user
1>nul 2>nul del /F /S /Q *.vcxproj.filters
1>nul 2>nul del /F /S /Q *.sln
1>nul 2>nul del /F /S /Q Makefile

echo Done.