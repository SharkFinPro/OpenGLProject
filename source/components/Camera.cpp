#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include <math.h>

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, -5.0f);
    direction = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + glm::normalize(direction), glm::vec3(0.0f, 1.0f, 0.0f));
}
#include <iostream>
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
        // direction x/y are in radians
        // direction z is either - or +, actual value doesn't matter it just flips the camera

        // update direction x/y based off mouse movement
        direction.x += static_cast<float>(deltaMX) / (speed * 50) * direction.z; // change +/- of input if camera is looking at +/- z axis
//        direction.y += static_cast<float>(deltaMY) / (speed * 50);

        // constrain direction x between -360 and 360, resetting to 0 whenever going over
        if (direction.x * (360/3.14) > 360)
        {
            direction.x -= 360 * (3.14/360);
        }
        if (direction.x * (360/3.14) < -360)
        {
            direction.x += 360 * (3.14/360);
        }

        // flip camera on z axis
        if ((direction.x * (360/3.14) < -90 || direction.x * (360/3.14) > 90) && direction.z == 1)
        {
            direction.z = -1;
            direction.x *= -1;
        } else if ((direction.x * (360/3.14) > -90 && direction.x * (360/3.14) < 90) && direction.z == -1)
        {
            direction.z = 1;
            direction.x *= -1;
        }

        // print out direction x (in degrees), direction y (in radians), and direction z
        std::cout << "dir x: " << direction.x * (360/3.14) << " | dir y: " << direction.y << " | dir z: " << direction.z << std::endl;
    }

    if (window->keyDown(GLFW_KEY_P))
    {
        direction.z *= -1;
        direction.x *= -1;
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