echo ======================start build======================
echo startTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2% 
cd C:\jenkins\workspace\test 
rd /s /q build 
mkdir build 
cd build 
cmake .. -G "Visual Studio 16 2019" -A x64
devenv.com C:\jenkins\workspace\test\build\testMultiDLL.sln /Build "Debug|x64" > C:\jenkins\workspace\test\VS_build.log
call C:\jenkins\workspace\test\bin\Debug\testMultiDLL.exe 
echo endTime: %date:~0,4%/%date:~5,2%/%date:~8,2% %time:~0,2%:%time:~3,2%:%time:~6,2%
echo ======================end build======================