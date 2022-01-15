#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// uncomment to disable asserts
// #define NDEBUG
#include <cassert>

#include <window.h>
#include <config.h>
#include <solstd.h>

void debug_point(const char* msg)
{
    #ifdef SOLAR_DEBUG
        std::cout << msg << std::endl;
    #endif
}

int main()
{
    // ! don't delete
    int initialized = glfwInit();
    if (initialized == GLFW_FALSE)
    {
        debug_point("GLFW wasn't initialized");
        exit(EXIT_FAILURE);
    }

    // use NEW keyword for now
    SolarEngine::Window *window = new SolarEngine::Window(M_WIDTH, M_HEIGHT, "Main Window", false);
    debug_point("Main Window was created");
    while(window->renderFrame());
    delete window;

    // for windows users xDDDD
    getchar();
}
