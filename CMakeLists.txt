cmake_minimum_required(VERSION 3.2)

# Getting variables from ProjectProperties.json
file(READ ProjectProperties.json ProjectProperties)
string(JSON project_actual_name GET ${ProjectProperties} project_name)
string(JSON project_actual_ver GET ${ProjectProperties} project_version)
message(STATUS "Building ${project_actual_name} ${project_actual_ver}")

# Get build information
string(JSON build_debug GET ${ProjectProperties} build debug-mode)
message(STATUS "SolarEngine DEBUG: ${build_debug}")

project(${project_actual_name} VERSION ${project_actual_ver})

# C11 -> C17 because of bug-fixes
# Don't change this!
set(CMAKE_CXX_STANDARD 17)

file(GLOB
    INCLUDE_H "include/*.h"
    SRC_CPP "src/*.cpp"
)

# To be changed
# Main window resolution
set(M_WIDTH 1280)
set(M_HEIGHT 720)

# Add compile definitions
set(GCC_COMPILE_DEFS "GLEW_STATIC") # static definitions
add_compile_definitions(${GCC_COMPILE_DEFS})
# IF build_debug IS ON then add SOLAR_DEBUG argument to gcc
if (${build_debug})
    add_compile_definitions("SOLAR_DEBUG")
endif(${build_debug})

include_directories(${PROJECT_NAME}
    ${CMAKE_CURRENT_BINARY_DIR}
    include/
    external/include/
)

link_directories(
    lib/
    external/lib/
)
    
add_executable(${PROJECT_NAME} 
    ${INCLUDE_H}
    ${SRC_CPP}
)

configure_file(include/config.h.in config.h)

if (UNIX)
    target_link_libraries(${PROJECT_NAME}
        glfw3
        GLEW
        GL
        pthread
        dl 
    )
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME}
        glfw3
        glew32s.lib
        opengl32
        gdi32
    )
endif (UNIX)