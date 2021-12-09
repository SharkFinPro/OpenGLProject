#include "Object.h"

Object::Object(const std::shared_ptr<VAO>& vao, Transform transform, const std::shared_ptr<Texture>& texture, std::shared_ptr<Texture>  specularMap, float shininess)
    : RawObject(vao, transform, texture), specularMap(std::move(specularMap)), shininess(shininess)
{}

void Object::render() const
{
    // Lighting data
    ShaderProgram::setUniform("material.diffuse", 0);
    ShaderProgram::setUniform("material.specular", 1);
    ShaderProgram::setUniform("material.shininess",  shininess);

    specularMap->bind(1);

    RawObject::render();
}