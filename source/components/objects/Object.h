#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "lighting/LightMaterial.h"
#include "indices/VAO.h"

class Object : public RawObject {
private:
    LightMaterial lightMaterial;

public:
    Object(LightMaterial lightMaterial, VAO* vao);

    void render() const;
};

/*class Object {
private:
    VAO* vao;
    Texture* texture;

    LightMaterial lightMaterial;

public:
    Object(LightMaterial lightMaterial, VAO* vao, Texture* texture = nullptr);
    ~Object();

    void render(ShaderProgram* shaderProgram) const;
};*/


#endif //OPENGLPROJECT_OBJECT_H
