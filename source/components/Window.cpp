#include "Window.h"

#include <stdexcept>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
}

Window::Window(int windowWidth, int windowHeight, const char *name) {
    width = windowWidth;
    height = windowHeight;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Learn OpenGL", nullptr, nullptr);

    if (window == nullptr)
    {

        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::update()
{
    // Check & call events & swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::processInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}