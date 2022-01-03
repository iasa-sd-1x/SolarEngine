#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <config.h>
#include <solstd.h>


void glew_log(std::string message)
{
    std::cout << "GLEW Log: " << message << std::endl;
}

void glfw_log(std::string message)
{
	std::cout << "GLFW Log: " << message << std::endl;
}

int main()
{
    glfw_log("Started initializing GLFW");
    if (!glfwInit())
    { 
        glfw_log("Failed to initialize GLFW. Stopping..."); 
        exit(EXIT_FAILURE);
    }
    glfw_log("GLFW was successfully initialized");
    GLFWwindow* window = glfwCreateWindow(M_WIDTH, M_HEIGHT, "Hello, World!", NULL, NULL);
    glfw_log("Started creating Main Window");
    if (window == NULL)
    {
	glfw_log("Failed to create Main Window. Stopping...");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Подключение OpenGL OpenES, инициализация GLEW
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        glew_log("GLEW Init error");
        exit(EXIT_FAILURE);
    }
    else glew_log("GLEW was successfully initialized");
    glew_log(fstring("GLEW version: %s", glGetString(GL_VERSION)));

    glfw_log(fstring("Main Window was successfully created: \nWindow Width -> %d\nWindow Height -> %d", M_WIDTH, M_HEIGHT));
    glfwSwapInterval(1);
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfw_log("Destroying Main Window. Terminating GLFW...");
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
