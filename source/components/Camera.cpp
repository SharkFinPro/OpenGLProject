#include "Camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -5.0f);
    direction = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    //
    return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::processInput(Window* window)
{
    float cameraSpeed = speed * window->getDeltaTime();

    double mx, my, omx, omy;
    window->getCursorPos(mx, my);
    window->getLastCursorPos(omx, omy);

    double deltaMX = mx - omx;
    double deltaMY = my - omy;

    /*if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        direction.x += deltaMX;
        direction.y += deltaMY;
    }*/


    // Position Change
    if (window->keyDown(GLFW_KEY_KP_8))
    {
        position.z += cameraSpeed * glm::normalize(direction).z;
    }
    if (window->keyDown(GLFW_KEY_KP_2))
    {
        position.z -= cameraSpeed * glm::normalize(direction).z;
    }

    if (window->keyDown(GLFW_KEY_KP_4))
    {
        position.x += cameraSpeed * glm::normalize(direction).x;
    }
    if (window->keyDown(GLFW_KEY_KP_6))
    {
        position.x -= cameraSpeed * glm::normalize(direction).x;
    }

    if (window->keyDown(GLFW_KEY_KP_1))
    {
        position.y += cameraSpeed * glm::normalize(direction).y;
    }
    if (window->keyDown(GLFW_KEY_KP_3))
    {
        position.y -= cameraSpeed * glm::normalize(direction).y;
    }
}