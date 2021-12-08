#ifndef OPENGLPROJECT_LIGHTINGSCENE_H
#define OPENGLPROJECT_LIGHTINGSCENE_H

#include "../RenderEngine.h"

class LightingScene {
private:
    std::shared_ptr<RenderEngine> renderEngine;

    std::shared_ptr<VAO> cubeVAO;

    std::shared_ptr<Object> cube;

    std::shared_ptr<LightSource> lightCube;

public:
    explicit LightingScene(std::shared_ptr<RenderEngine> engine);

    void update();
};


#endif //OPENGLPROJECT_LIGHTINGSCENE_H
