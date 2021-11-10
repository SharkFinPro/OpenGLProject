#ifndef OPENGLPROJECT_LIGHTOBJECT_H
#define OPENGLPROJECT_LIGHTOBJECT_H

#include "LightMaterial.h"

class LightObject {
private:
    LightMaterial material{};

public:
    explicit LightObject(LightMaterial lightMaterial);
    ~LightObject();
};


#endif //OPENGLPROJECT_LIGHTOBJECT_H
