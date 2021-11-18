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