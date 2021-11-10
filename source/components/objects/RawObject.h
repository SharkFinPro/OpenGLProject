#ifndef OPENGLPROJECT_RAWOBJECT_H
#define OPENGLPROJECT_RAWOBJECT_H

#include "indices/VAO.h"
#include "textures/Texture.h"

class RawObject {
private:
    VAO* vao;
    Texture* texture;

public:
    explicit RawObject(VAO* vao, Texture* texture = nullptr);
    ~RawObject();

    void render() const;
};


#endif //OPENGLPROJECT_RAWOBJECT_H
