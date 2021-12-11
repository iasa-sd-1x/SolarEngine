cmake_minimum_required(VERSION 3.2)
project(SolarEngine)

file(GLOB
    INCLUDE_H "include/*.h"
    SRC_CPP "src/*.cpp"
)

include_directories(${PROJECT_NAME}
    include/
    external/include/
)
link_directories(
    lib/
    external/lib/
)

add_executable(${PROJECT_NAME} 
    ${SRC_CPP}
    ${INCLUDE_H}
)
target_link_libraries(${PROJECT_NAME}
    opengl32
    glfw3
    gdi32
)
