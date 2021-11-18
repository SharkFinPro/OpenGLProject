#ifndef OPENGLPROJECT_LIGHTSOURCE_H
#define OPENGLPROJECT_LIGHTSOURCE_H

#include "../Object.h"

class LightSource : public Object {
public:
    LightSource(std::shared_ptr<VAO> vao, LightMaterial lightMaterial, glm::vec3 lightPosition, glm::vec3 lightColor);
};


#endif //OPENGLPROJECT_LIGHTSOURCE_H
