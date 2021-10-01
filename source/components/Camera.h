#ifndef OPENGLPROJECT_CAMERA_H
#define OPENGLPROJECT_CAMERA_H

#include "Window.h"
#include <glm/glm.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 direction;

    float speed = 2.5f;
    float pitch = -0.0f;
    float yaw = -90;

public:
    Camera(float speed, glm::vec3 position, glm::vec3 up);

    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getFront() const;
    [[nodiscard]] glm::vec3 getUp() const;

    void processInput(Window* window);
};


#endif //OPENGLPROJECT_CAMERA_H
