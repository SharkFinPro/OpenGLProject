#ifndef OPENGLPROJECT_LIGHTINGSCENE_H
#define OPENGLPROJECT_LIGHTINGSCENE_H

#include <source/RenderEngine.h>

class LightingScene {
private:
    std::shared_ptr<Engine::RenderEngine> renderEngine;

    std::shared_ptr<Engine::VAO> cubeVAO;

    std::shared_ptr<Engine::Object> cube;

    std::shared_ptr<Engine::LightSource> lightSource;

public:
    explicit LightingScene(std::shared_ptr<Engine::RenderEngine> engine);
};


#endif //OPENGLPROJECT_LIGHTINGSCENE_H
