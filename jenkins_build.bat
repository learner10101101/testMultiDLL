echo ======================start build======================
echo startTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2% 
cd %WORKSPACE% 
rd /s /q build 
mkdir build 
cd build 
cmake .. -G "Visual Studio 16 2019" -A x64
devenv.com %WORKSPACE%\build\testMultiDLL.sln /Build "Debug|x64" > %WORKSPACE%\VS_build.log
call %WORKSPACE%\bin\Debug\testMultiDLL.exe 
echo endTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2%
echo ======================end build======================