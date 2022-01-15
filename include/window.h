#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

namespace SolarEngine
{
    class Window
    {
        private:
            GLFWwindow* window;
            int height;
            int width;
            const char* title;
            bool fullscreen;

        public:
            Window(int height, int width, const char* title, bool fullscreen);

            ~Window();

            GLFWwindow* getWindow();
            int getHeight();
            int getWidth();
            const char* getTitle();
            bool isFullscreen();

            bool renderFrame();

            void closeWindow()
            {
                
            }
    };
}

#endif // WINDOW_H