@echo off
cd ../build/
if not exist SolarEngine.exe (
    echo Can't find any SolarEngine.exe file... 
    goto end
) else (
    start SolarEngine
    echo Starting SolarEngine.exe...
)
:end