#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 pos)
{
    position = pos;
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + direction, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::vec3 Camera::getPosition()
{
    return position;
}
#include <iostream>
void Camera::processInput(Window* window)
{
    float cameraSpeed = speed * window->getDeltaTime();

    double mx, my, omx, omy;
    window->getCursorPos(mx, my);
    window->getLastCursorPos(omx, omy);

    auto deltaMX = static_cast<float>(mx - omx) / (static_cast<float>(window->getWidth()) / 800.0f);
    auto deltaMY = static_cast<float>(my - omy) / (static_cast<float>(window->getHeight()) / 600.0f);

    if (window->buttonDown(GLFW_MOUSE_BUTTON_RIGHT))
    {
        yaw += deltaMX;
        pitch -= deltaMY;
    }

    if (pitch > 89.0f)
        pitch = 89.0f;
    else if (pitch < -89.0f)
        pitch = -89.0f;

    direction.x = static_cast<float>(glm::cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
    direction.y = static_cast<float>(glm::sin(glm::radians(pitch)));
    direction.z = static_cast<float>(glm::sin(glm::radians(yaw)) * cos(glm::radians(pitch)));

    if (window->keyDown(GLFW_KEY_W))
        position += cameraSpeed * direction;
    if (window->keyDown(GLFW_KEY_S))
        position -= cameraSpeed * direction;
}