#include "LightSource.h"

#include "../../ShaderProgram.h"

LightSource::LightSource(glm::vec3 position, glm::vec3 color, float ambient, float diffuse, float specular)
    : position(position), color(color), ambient(glm::vec3(ambient)), diffuse(glm::vec3(diffuse)), specular(glm::vec3(specular))
{}

void LightSource::load() const
{
    ShaderProgram::setUniform("light.position",  position);
    ShaderProgram::setUniform("light.color", color);
    ShaderProgram::setUniform("light.ambient",  ambient);
    ShaderProgram::setUniform("light.diffuse",  diffuse);
    ShaderProgram::setUniform("light.specular",  specular);
}

