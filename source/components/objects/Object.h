#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "raw/VAO.h"
#include <glm/vec3.hpp>
#include <memory>

struct LightMaterial {
    float ambient;
    float diffuse;
    float specular;
    float shininess;
};

class Object : public RawObject {
private:
    LightMaterial lightMaterial;
    glm::vec3 color;

public:
    Object(LightMaterial lightMaterial, const std::shared_ptr<VAO>& vao, glm::vec3 position, glm::vec3 color);

    [[nodiscard]] LightMaterial getLightMaterial() const;

    [[nodiscard]] glm::vec3 getColor() const;

    void render() const;
};


#endif //OPENGLPROJECT_OBJECT_H
