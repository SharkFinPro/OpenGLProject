#ifndef OPENGLPROJECT_RAWOBJECT_H
#define OPENGLPROJECT_RAWOBJECT_H

#include "raw/VAO.h"
#include "textures/Texture.h"
#include <memory>

class RawObject {
private:
    std::shared_ptr<VAO> vao;
    std::shared_ptr<Texture> texture;

public:
    explicit RawObject(std::shared_ptr<VAO> vao, std::shared_ptr<Texture> texture = {});

    void render() const;
};


#endif //OPENGLPROJECT_RAWOBJECT_H
