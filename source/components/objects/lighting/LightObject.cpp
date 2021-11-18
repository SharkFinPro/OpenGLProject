#include "LightObject.h"

LightObject::LightObject(std::shared_ptr<VAO> vao, LightMaterial lightMaterial, glm::vec3 lightPosition, glm::vec3 lightColor)
    : Object(lightMaterial, vao, lightPosition), color(lightColor)
{

}

glm::vec3 LightObject::getColor() const
{
    return color;
}