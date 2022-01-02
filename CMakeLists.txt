cmake_minimum_required(VERSION 3.2)
project(SolarEngine VERSION 0.0.1)

file(GLOB
    INCLUDE_H "include/*.h"
    SRC_CPP "src/*.cpp"
)

# Main window resolution
# Меняет разрешение главного окна (test)
set(M_WIDTH 1280)
set(M_HEIGHT 720)


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
        pthread
        dl 
    )
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME}
        opengl32
        glfw3
        gdi32
    )
endif (UNIX)
