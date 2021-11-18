#include "LightSource.h"

LightSource::LightSource(std::shared_ptr<VAO> vao, LightMaterial lightMaterial, glm::vec3 lightPosition, glm::vec3 lightColor)
    : Object(lightMaterial, vao, lightPosition, lightColor)
{

}