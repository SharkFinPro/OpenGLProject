#include "LightSource.h"
#include "../../ShaderProgram.h"

namespace Engine {
    LightSource::LightSource(glm::vec3 position, glm::vec3 color, float ambient, float diffuse, float specular)
        : position(position), color(color), ambient(ambient), diffuse(diffuse), specular(specular)
    {}

    void LightSource::load() const
    {
        ShaderProgram::setUniform("light.position", position);
        ShaderProgram::setUniform("light.color", color);
        ShaderProgram::setUniform("light.ambient", ambient);
        ShaderProgram::setUniform("light.diffuse", diffuse);
        ShaderProgram::setUniform("light.specular", specular);
    }
}