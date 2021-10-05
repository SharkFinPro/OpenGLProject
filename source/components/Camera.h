#ifndef OPENGLPROJECT_CAMERA_H
#define OPENGLPROJECT_CAMERA_H

#include "Window.h"
#include <glm/glm.hpp>

class Camera {
private:
    glm::vec3 position;
    glm::vec3 direction;

    float speed = 2.5f;

public:
    Camera();

    [[nodiscard]] glm::mat4 getViewMatrix();

    void processInput(Window* window);
};


#endif //OPENGLPROJECT_CAMERA_H
