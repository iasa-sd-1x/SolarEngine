#!/bin/bash
BUILD=../build/
PROJ_NAME=SolarEngine
EXEC="$BUILD""$PROJ_NAME".bin

# CMake configuration label
label_cmake_conf() {
    rm "$BUILD"CMakeCache.txt
    cmake -G "Unix Makefiles" -S .. -B "$BUILD"
}

# Makefile exec label + making an exec binary
label_make() {
    cd "$BUILD"
    make
    chmod +x "$PROJ_NAME"
}

# Running a binary label
label_exec_bin() {
    cd "$BUILD"
    ./"$PROJ_NAME"
}

# Check for Makefile
if [ -f "$BUILD"Makefile ]; then
    echo "Makefile already exists (Predicting that CMake was already configured)"
    read -p 'Would you like to update CMake Configuration? (Makefile will be rewritten) [Y/n]: '
    echo 
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        label_cmake_conf
    fi
else
    label_cmake_conf
fi

label_make

# Check for binary
if [ -f "$EXEC" ]; then
    echo "Can't find any $PROJ_NAME binary file..."     
else 
    read -p 'Would you like to run a compiled binary? [Y/n]: '
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo "Starting $PROJ_NAME binary..."
        label_exec_bin
    fi
fi