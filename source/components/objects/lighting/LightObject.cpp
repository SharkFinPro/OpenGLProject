#include "LightObject.h"

LightObject::LightObject(std::shared_ptr<VAO> vao, LightMaterial lightMaterial, glm::vec3 lightPosition, glm::vec3 lightColor)
    : Object(lightMaterial, vao), material(lightMaterial), position(lightPosition), color(lightColor)
{

}

glm::vec3 LightObject::getPosition() const
{
    return position;
}

glm::vec3 LightObject::getColor() const
{
    return color;
}