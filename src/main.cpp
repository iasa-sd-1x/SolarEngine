#include <GLFW/glfw3.h>
#include <config.h>
#include <iostream>

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
    glfw_log("Main Window was successfully created");
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
