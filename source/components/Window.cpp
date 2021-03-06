#include "Window.h"
#include <stdexcept>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
}

namespace Engine {
    Window::Window(int width, int height, const char *name, bool fullscreen)
        : deltaTime(0.0f), lastTime(0.0f), mouseX(0), mouseY(0), lastMouseX(0), lastMouseY(0)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (fullscreen)
        {
            GLFWmonitor *monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode *mode = glfwGetVideoMode(monitor);
            window = glfwCreateWindow(mode->width, mode->height, name, monitor, nullptr);
        }
        else
            window = glfwCreateWindow(width, height, name, nullptr, nullptr);

        if (window == nullptr)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        glfwGetCursorPos(window, &mouseX, &mouseY);
        lastMouseX = mouseX;
        lastMouseY = mouseY;
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(window);
    }

    void Window::update()
    {
        // Check & call events & swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        // Get new deltatime
        auto currentTime = static_cast<float>(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Get new mouse position
        lastMouseX = mouseX;
        lastMouseY = mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);
    }

    void Window::processInput()
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void Window::makeCurrentContext()
    {
        glfwMakeContextCurrent(window);
    }

    int Window::getWidth() const
    {
        int width;
        glfwGetWindowSize(window, &width, nullptr);
        return width;
    }

    int Window::getHeight() const
    {
        int height;
        glfwGetWindowSize(window, nullptr, &height);
        return height;
    }

    bool Window::keyDown(int key) const
    {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }

    bool Window::buttonDown(int button) const
    {
        return glfwGetMouseButton(window, button) == GLFW_PRESS;
    }

    float Window::getDeltaTime() const
    {
        return deltaTime;
    }

    void Window::getCursorPos(double &xpos, double &ypos) const
    {
        xpos = mouseX;
        ypos = mouseY;
    }

    void Window::getLastCursorPos(double &xpos, double &ypos) const
    {
        xpos = lastMouseX;
        ypos = lastMouseY;
    }
}