#ifndef OPENGLPROJECT_LIGHTSOURCE_H
#define OPENGLPROJECT_LIGHTSOURCE_H

#include "../Object.h"

class LightSource : public Object {
public:
    LightSource(const std::shared_ptr<VAO>& vao, Material material, glm::vec3 lightPosition);
};


#endif //OPENGLPROJECT_LIGHTSOURCE_H
