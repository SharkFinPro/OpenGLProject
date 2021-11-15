#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "lighting/LightMaterial.h"
#include "raw/VAO.h"

class Object : public RawObject {
private:
    LightMaterial lightMaterial;

    VAO* vao;

public:
    Object(LightMaterial lightMaterial, VAO* vao);

    //void render() const;
    void render(const ShaderProgram* shaderProgram) const;
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
