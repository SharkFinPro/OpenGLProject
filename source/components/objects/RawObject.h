#ifndef OPENGLPROJECT_RAWOBJECT_H
#define OPENGLPROJECT_RAWOBJECT_H

#include "raw/VAO.h"
#include "textures/Texture.h"
#include <glm/vec3.hpp>
#include <memory>

struct Transform {
    glm::vec3 position;
    glm::vec3 rotation;
    float scale;
};

class RawObject {
private:
    Transform transform;

    std::shared_ptr<VAO> vao;
    std::shared_ptr<Texture> texture;

public:
    RawObject(std::shared_ptr<VAO> vao, Transform transform, std::shared_ptr<Texture> texture = {});

    virtual void render() const;

    [[nodiscard]] Transform getTransform() const;

    void move(glm::vec3 change);
};


#endif //OPENGLPROJECT_RAWOBJECT_H
