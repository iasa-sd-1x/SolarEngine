#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// uncomment to disable asserts
// #define NDEBUG
#include <cassert>

#include <config.h>
#include <solstd.h>

// To be rewritten
class GLFW
{
public:
    GLFWwindow *window;
    const int width = M_WIDTH;
    const int height = M_HEIGHT;

    GLFW()
    {
        if (!glfwInit())
        { 
            exit(EXIT_FAILURE);
        }
    }

    void createWindow(int width, int height, const char* title)
    {
        try 
        {
            window = glfwCreateWindow(width, height, title, NULL, NULL);
            if (window == NULL)
            {
                glfwTerminate();
                throw sol_exception("Window is NULL");
            }
        } 
        catch (const sol_exception &e)
        {
            std::cout << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        if (glewInit() != GLEW_OK)
        {
            exit(EXIT_FAILURE);
        }

        glfwSwapInterval(1);

        while (!glfwWindowShouldClose(window))
        {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    ~GLFW()
    {
        assert(window != NULL);
        glfwDestroyWindow(window);
    }
};

int main()
{
    std::cout << PROJECT_VERSION << std::endl;
    std::cout << PROJECT_NAME << std::endl;

    GLFW glfw;
    glfw.createWindow(M_WIDTH, M_HEIGHT, "Main Window 1");

    exit(EXIT_SUCCESS);
}




