cmake_minimum_required(VERSION 3.2) # версия смейк
project(proj) # project name

file(GLOB
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

add_executable(proj ${SRC_CPP}) # compile exe

target_link_libraries(${PROJECT_NAME}
    opengl32
    glfw3
    gdi32
)
