#ifndef OPENGLPROJECT_LIGHTOBJECT_H
#define OPENGLPROJECT_LIGHTOBJECT_H

#include "LightMaterial.h"
#include "../Object.h"
#include <glm/vec3.hpp>
#include <memory>

class LightObject : public Object {
private:
    LightMaterial material{};

    glm::vec3 position;
    glm::vec3 color;

public:
    LightObject(std::shared_ptr<VAO> vao, LightMaterial lightMaterial, glm::vec3 lightPosition, glm::vec3 lightColor);

    [[nodiscard]] glm::vec3 getPosition() const;
    [[nodiscard]] glm::vec3 getColor() const;
};


#endif //OPENGLPROJECT_LIGHTOBJECT_H
