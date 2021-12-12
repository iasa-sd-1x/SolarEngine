@echo off
cd ../out/build/
if not exist harpy.exe (
    echo Can't find any harpy.exe file... 
    goto end
) else (
    start harpy
    echo Starting harpy.exe...
)
:end