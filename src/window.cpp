#include <GLFW/glfw3.h>

#include <iostream>

#include <window.h>

namespace SolarEngine
{
    Window::Window(int width, int height, const char* title, bool fullscreen) :
        height(height),
        width(width),
        title(title),
        fullscreen(fullscreen)
    {
        window = glfwCreateWindow(
            width, 
            height, 
            title, 
            fullscreen ? glfwGetPrimaryMonitor() : NULL, 
            NULL
        );
        
        /*
        The swap interval indicates how many frames to wait until swapping the buffers, commonly known as vsync. 
        By default, the swap interval is zero, meaning buffer swapping will occur immediately. 
        On fast machines, many of those frames will never be seen, as the screen is still only 
        updated typically 60-75 times per second, so this wastes a lot of CPU and GPU cycles.

        This can also occur a Screen tearing
        https://en.wikipedia.org/wiki/Screen_tearing
        */
        glfwSwapInterval(1);
    }

    bool Window::renderFrame()
    {   
        glfwSwapBuffers(window);
        glfwPollEvents();
        return !glfwWindowShouldClose(window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
    }
}