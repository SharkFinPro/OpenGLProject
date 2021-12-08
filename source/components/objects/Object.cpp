#include "Object.h"

Object::Object(const std::shared_ptr<VAO>& vao, Transform transform, Material material, const std::shared_ptr<Texture>& texture)
    : RawObject(vao, transform, texture), material(material)
{}

Material Object::getLightMaterial() const
{
    return material;
}

void Object::render() const
{
    // Lighting data
    ShaderProgram::setUniform("material.diffuse", 0);
    ShaderProgram::setUniform("material.specular",  material.specular, material.specular, material.specular);
    ShaderProgram::setUniform("material.shininess",  material.shininess);

    RawObject::render();
}