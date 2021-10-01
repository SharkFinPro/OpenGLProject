#include "Window.h"

#include <stdexcept>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char *name) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, name, nullptr, nullptr);

    if (window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
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
    float currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
}

void Window::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
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

float Window::getDeltaTime() const
{
    return deltaTime;
}