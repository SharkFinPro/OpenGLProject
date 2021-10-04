#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -5.0f);
    front = glm::vec3(0.0f, 0.0f, 1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    front.x = sin(yaw) * 1.25f;
    front.y = sin(pitch);

    return glm::lookAt(position, position + front, up);
}

void Camera::processInput(Window *window)
{
    float cameraSpeed = speed * window->getDeltaTime();


    // Position Change
    if (window->keyDown(GLFW_KEY_KP_8))
    {
        position.z += cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_KP_2))
    {
        position.z -= cameraSpeed;
    }

    if (window->keyDown(GLFW_KEY_KP_4))
    {
        position.x += cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_KP_6))
    {
        position.x -= cameraSpeed;
    }

    if (window->keyDown(GLFW_KEY_KP_1))
    {
        position.y += cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_KP_3))
    {
        position.y -= cameraSpeed;
    }

    // yaw
    if (window->keyDown(GLFW_KEY_RIGHT))
    {
        yaw -= cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_LEFT))
    {
        yaw += cameraSpeed;
    }
    // pitch
    if (window->keyDown(GLFW_KEY_UP))
    {
        pitch += cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_DOWN))
    {
        pitch -= cameraSpeed;
    }
    // roll
    if (window->keyDown(GLFW_KEY_Q))
    {
        roll += cameraSpeed;
    }
    if (window->keyDown(GLFW_KEY_E))
    {
        roll -= cameraSpeed;
    }
}