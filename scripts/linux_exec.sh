#!/bin/bash
BUILD=../build/
PROJ_NAME=SolarEngine
EXEC="$BUILD""$PROJ_NAME".bin

# CMake configuration
rm "$BUILD"CMakeCache.txt
cmake -G "Unix Makefiles" -S .. -B "$BUILD"

# Makefile exec + making an exec binary
cd "$BUILD"
make
chmod +x "$PROJ_NAME"

# Check for binary
if [ -f "$EXEC" ]; then
    echo "Can't find any $PROJ_NAME binary file..."     
else 
    # Check if return code is equal to 0 (Success?)
    echo "... $PROJ_NAME ..."
    cd "$BUILD"
    ./"${PROJ_NAME}"
    exit_code=$?
    if [ ${exit_code} -ne 0 ]; then
        echo "ERROR? Return code is ${exit_code}";
        exit 1
    else 
        echo "DONE! Return code is 0"
    fi
fi