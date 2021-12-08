#include "Object.h"

Object::Object(const std::shared_ptr<VAO>& vao, Transform transform, Material material, const std::shared_ptr<Texture>& texture, std::shared_ptr<Texture>  specularMap)
    : RawObject(vao, transform, texture), material(material), specularMap(std::move(specularMap))
{}

Material Object::getLightMaterial() const
{
    return material;
}

void Object::render() const
{
    // Lighting data
    ShaderProgram::setUniform("material.diffuse", 0);
    if (specularMap)
    {
        ShaderProgram::setUniform("material.specular", 1);
        specularMap->bind(1);
    }
    else
        ShaderProgram::setUniform("material.specular",  material.specular, material.specular, material.specular);
    ShaderProgram::setUniform("material.shininess",  material.shininess);

    RawObject::render();
}