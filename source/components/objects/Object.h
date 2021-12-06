#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "raw/VAO.h"
#include <glm/vec3.hpp>
#include <memory>

struct Material {
    float ambient;
    float diffuse;
    float specular;
    float shininess;
    glm::vec3 color;
};

class Object : public RawObject {
private:
    Material material;

public:
    Object(Material lightMaterial, const std::shared_ptr<VAO>& vao, glm::vec3 position);

    [[nodiscard]] Material getLightMaterial() const;

    void render() const;
};


#endif //OPENGLPROJECT_OBJECT_H
