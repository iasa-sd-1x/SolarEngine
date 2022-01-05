cmake_minimum_required(VERSION 3.2)

file(READ ProjectProperties.json ProjectProperties)
string(JSON project_actual_name GET ${ProjectProperties} project_name)
string(JSON project_actual_ver GET ${ProjectProperties} project_version)

project(${project_actual_name} VERSION ${project_actual_ver})


set(CMAKE_CXX_STANDARD 11)

file(GLOB
    INCLUDE_H "include/*.h"
    SRC_CPP "src/*.cpp"
)

# Main window resolution
# Меняет разрешение главного окна (test)
set(M_WIDTH 1280)
set(M_HEIGHT 720)

set(GCC_COMPILE_FLAGS "-DGLEW_STATIC")
add_definitions(${GCC_COMPILE_FLAGS})

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
