#ifndef OPENGLPROJECT_RAWOBJECT_H
#define OPENGLPROJECT_RAWOBJECT_H

#include "raw/VAO.h"
#include "textures/Texture.h"
#include <glm/vec3.hpp>
#include <memory>

class RawObject {
private:
    glm::vec3 position;

    std::shared_ptr<VAO> vao;
    std::shared_ptr<Texture> texture;

public:
    RawObject(glm::vec3 position, std::shared_ptr<VAO> vao, std::shared_ptr<Texture> texture = {});

    void render() const;

    [[nodiscard]] glm::vec3 getPosition() const;
};


#endif //OPENGLPROJECT_RAWOBJECT_H
