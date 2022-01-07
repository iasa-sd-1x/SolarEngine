@echo off

set build=../build/
set proj_name=SolarEngine
set exec=%build%%proj_name%.bin

:: configure func
:Configure

cmake -G "MinGW Makefiles" -S .. -B %build%
echo CMake was successfully configured with MinGW


:: build func
:Build

cd %build%
mingw32-make
echo Successfully built %proj_name%.exe


:: run func
:Run 

cd %build%
if not exist %proj_name%.exe (
    echo Can't find any %proj_name%.exe file... 
    goto end
) else (
    start %proj_name%
    echo Starting %proj_name%.exe...
)



:end
