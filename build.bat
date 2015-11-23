@echo off
setlocal
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" amd64
pushd output
cl /Zi /MD /DTERM_STU=1 /DTERM_INAL=1^
 ../source/main.cpp ^
 /link /subsystem:Console /out:term.exe
popd