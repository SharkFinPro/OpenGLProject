#ifndef OPENGLPROJECT_LIGHTSOURCE_H
#define OPENGLPROJECT_LIGHTSOURCE_H

#include "../Object.h"

class LightSource : public Object {
public:
    LightSource(const std::shared_ptr<VAO>& vao, Transform transform, Material material);
};


#endif //OPENGLPROJECT_LIGHTSOURCE_H
