#include "Object.h"

Object::Object(LightMaterial lightMaterial, std::shared_ptr<VAO> vao)
    : RawObject(vao), lightMaterial(lightMaterial), vao(vao)
{

}

void Object::render(std::shared_ptr<ShaderProgram> shaderProgram) const
{
    // Set uniforms
    glm::vec3 c = glm::vec3(1.0f, 0.5f, 0.31f);
    glm::vec3 diffuse = c * lightMaterial.diffuse;
    glm::vec3 ambient = diffuse * lightMaterial.ambient;
    shaderProgram->setUniform("material.ambient", ambient.x, ambient.y, ambient.z);
    shaderProgram->setUniform("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
    shaderProgram->setUniform("material.specular",  lightMaterial.specular, lightMaterial.specular, lightMaterial.specular);
    shaderProgram->setUniform("material.shininess",  lightMaterial.shininess);

    // Draw the VAO
    vao->draw();
}