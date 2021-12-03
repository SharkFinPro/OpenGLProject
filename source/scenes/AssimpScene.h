#ifndef OPENGLPROJECT_ASSIMPSCENE_H
#define OPENGLPROJECT_ASSIMPSCENE_H

#include "../RenderEngine.h"

class AssimpScene {
private:
    std::shared_ptr<RenderEngine> renderEngine;

    std::shared_ptr<VAO> cubeVAO;

    std::shared_ptr<Object> cube;
    std::shared_ptr<Object> cube2;

    std::shared_ptr<LightSource> lightCube;

public:
    explicit AssimpScene(std::shared_ptr<RenderEngine> engine);

    void update();
};


#endif //OPENGLPROJECT_ASSIMPSCENE_H
