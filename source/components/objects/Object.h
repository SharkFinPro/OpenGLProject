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
    std::shared_ptr<Texture> specularMap;

public:
    Object(const std::shared_ptr<VAO>& vao, Transform transform, Material material, const std::shared_ptr<Texture>& texture = nullptr, std::shared_ptr<Texture>  specularMap = nullptr);

    [[nodiscard]] Material getLightMaterial() const;

    void render() const override;
};


#endif //OPENGLPROJECT_OBJECT_H
