#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -5.0f);
    direction = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::getViewMatrix()
{
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

    if (window->buttonDown(GLFW_MOUSE_BUTTON_RIGHT))
    {
        direction.x += static_cast<float>(deltaMX) / (speed * 50);
        direction.y += static_cast<float>(deltaMY) / (speed * 50);
    }

    if (window->keyDown(GLFW_KEY_W))
    {
        position += cameraSpeed * glm::normalize(direction);
    }
    if (window->keyDown(GLFW_KEY_S))
    {
        position -= cameraSpeed * glm::normalize(direction);
    }
}