#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "lighting/LightMaterial.h"
#include "raw/VAO.h"
#include <memory>

class Object : public RawObject {
private:
    LightMaterial lightMaterial;
    std::shared_ptr<VAO> vao;

public:
    Object(LightMaterial lightMaterial, std::shared_ptr<VAO> vao);

    void render(std::shared_ptr<ShaderProgram> shaderProgram) const;
};


#endif //OPENGLPROJECT_OBJECT_H
