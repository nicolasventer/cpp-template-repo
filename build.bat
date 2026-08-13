@echo off
cmake --build build %*
if errorlevel 1 exit /b %errorlevel%

copy /Y "build\math.exe" "."
