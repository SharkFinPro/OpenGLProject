#ifndef OPENGLPROJECT_WINDOW_H
#define OPENGLPROJECT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window;
    int width;
    int height;

public:
    Window(int width, int height, const char* name);

    bool shouldClose();

    void update();

    void processInput();

    Window();
};


#endif //OPENGLPROJECT_WINDOW_H
