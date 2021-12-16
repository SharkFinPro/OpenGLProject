#ifndef OPENGLPROJECT_CAMERA_H
#define OPENGLPROJECT_CAMERA_H

#include "Window.h"
#include <glm/glm.hpp>
#include <memory>

namespace Engine {
    class Camera {
    private:
        glm::vec3 position{};
        glm::vec3 direction = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 pDirection = glm::vec3(0.0f);

        float speed = 5.0f;
        float pitch = 0.0f;
        float yaw = 90.0f;

    public:
        explicit Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f));

        [[nodiscard]] glm::mat4 getViewMatrix() const;

        [[nodiscard]] glm::vec3 getPosition() const;

        void setSpeed(float cameraSpeed);

        void processInput(const std::shared_ptr<Window> &window);
    };
}

#endif //OPENGLPROJECT_CAMERA_H