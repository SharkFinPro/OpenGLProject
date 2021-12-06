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
    glm::vec3 diffuse = material.color * material.diffuse;
    glm::vec3 ambient = diffuse * material.ambient;
    ShaderProgram::setUniform("material.ambient", ambient.x, ambient.y, ambient.z);
    ShaderProgram::setUniform("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
    ShaderProgram::setUniform("material.specular",  material.specular, material.specular, material.specular);
    ShaderProgram::setUniform("material.shininess",  material.shininess);

    RawObject::render();
}