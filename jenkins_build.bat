echo ======================start build======================
echo startTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2% 
cd %WORKSPACE%\test 
rd /s /q build 
mkdir build 
cd build 
cmake .. -G "Visual Studio 16 2019" -A x64
devenv.com %WORKSPACE%\test\build\testMultiDLL.sln /Build "Debug|x64" > %WORKSPACE%\test\VS_build.log
call %WORKSPACE%\test\bin\Debug\testMultiDLL.exe 
echo endTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2%
echo ======================end build======================