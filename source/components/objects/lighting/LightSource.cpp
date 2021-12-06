#include "LightSource.h"

LightSource::LightSource(const std::shared_ptr<VAO>& vao, Material material, glm::vec3 lightPosition)
    : Object(material, vao, lightPosition)
{

}