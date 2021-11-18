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
    std::shared_ptr<VAO> vao;

public:
    Object(LightMaterial lightMaterial, const std::shared_ptr<VAO>& vao, glm::vec3 position);

    void render(std::shared_ptr<ShaderProgram> shaderProgram) const;

    [[nodiscard]] LightMaterial getLightMaterial() const;
};


#endif //OPENGLPROJECT_OBJECT_H
