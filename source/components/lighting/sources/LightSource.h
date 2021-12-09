#ifndef OPENGLPROJECT_LIGHTSOURCE_H
#define OPENGLPROJECT_LIGHTSOURCE_H

#include <glm/vec3.hpp>

class LightSource {
private:
    glm::vec3 position;
    glm::vec3 color;
    float ambient;
    float diffuse;
    float specular;

public:
    explicit LightSource(glm::vec3 position, glm::vec3 color, float ambient, float diffuse, float specular);

    void load() const;
};


#endif //OPENGLPROJECT_LIGHTSOURCE_H
