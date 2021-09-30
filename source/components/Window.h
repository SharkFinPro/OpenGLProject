#ifndef OPENGLPROJECT_WINDOW_H
#define OPENGLPROJECT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
    GLFWwindow* window;

public:
    Window(int width, int height, const char* name);
    ~Window();

    [[nodiscard]] bool shouldClose() const;
    void update();
    void processInput();
    void makeCurrentContext();

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    [[nodiscard]] bool keyDown(int key) const;
};


#endif //OPENGLPROJECT_WINDOW_H
