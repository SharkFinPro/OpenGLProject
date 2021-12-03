#ifndef OPENGLPROJECT_SCENE1_H
#define OPENGLPROJECT_SCENE1_H

#include "../RenderEngine.h"

class Scene1 {
private:
    std::shared_ptr<RenderEngine> renderEngine;

    std::shared_ptr<VAO> cubeVAO;

    std::shared_ptr<Object> cube;
    std::shared_ptr<Object> cube2;

    std::shared_ptr<LightSource> lightCube;

public:
    explicit Scene1(std::shared_ptr<RenderEngine> engine);

    void update();
};


#endif //OPENGLPROJECT_SCENE1_H
