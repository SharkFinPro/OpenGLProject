#include "Object.h"

Object::Object(LightMaterial lightMaterial, const std::shared_ptr<VAO>& vao, glm::vec3 position, glm::vec3 color)
    : RawObject(position, vao), lightMaterial(lightMaterial), color(color)
{

}

LightMaterial Object::getLightMaterial() const
{
    return lightMaterial;
}

glm::vec3 Object::getColor() const
{
    return color;
}

void Object::render() const
{
    // Lighting data
    glm::vec3 diffuse = color * lightMaterial.diffuse;
    glm::vec3 ambient = diffuse * lightMaterial.ambient;
    ShaderProgram::setUniform("material.ambient", ambient.x, ambient.y, ambient.z);
    ShaderProgram::setUniform("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
    ShaderProgram::setUniform("material.specular",  lightMaterial.specular, lightMaterial.specular, lightMaterial.specular);
    ShaderProgram::setUniform("material.shininess",  lightMaterial.shininess);

    RawObject::render();
}