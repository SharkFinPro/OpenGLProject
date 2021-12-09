#ifndef OPENGLPROJECT_LIGHTINGSCENE_H
#define OPENGLPROJECT_LIGHTINGSCENE_H

#include "../RenderEngine.h"

class LightingScene {
private:
    std::shared_ptr<RenderEngine> renderEngine;

    std::shared_ptr<VAO> cubeVAO;

    std::shared_ptr<Object> cube;

    std::shared_ptr<LightSource> lightSource;

public:
    explicit LightingScene(std::shared_ptr<RenderEngine> engine);
};


#endif //OPENGLPROJECT_LIGHTINGSCENE_H
