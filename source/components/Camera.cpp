#include "Camera.h"

Camera::Camera(float speed, glm::vec3 position, glm::vec3 up)
{
    this->speed = speed;
    this->position = position;
    this->up = up;

    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    //front = glm::normalize(direction);
    front = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3 Camera::getPosition() const
{
    return position;
}

glm::vec3 Camera::getFront() const
{
    return front;
}

glm::vec3 Camera::getUp() const
{
    return up;
}

void Camera::processInput(Window *window)
{
    float cameraSpeed = speed * window->getDeltaTime();
    if (window->keyDown(GLFW_KEY_W))
    {
        position += cameraSpeed * front;
    }
    if (window->keyDown(GLFW_KEY_S))
    {
        position -= cameraSpeed * front;
    }
    if (window->keyDown(GLFW_KEY_A))
    {
        position -= cameraSpeed * glm::normalize(glm::cross(front, up));
    }
    if (window->keyDown(GLFW_KEY_D))
    {
        position += cameraSpeed * glm::normalize(glm::cross(front, up));
    }
}