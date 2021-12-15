#include "LightingScene.h"

#include <source/helpers/FileIO.h>

LightingScene::LightingScene(std::shared_ptr<Engine::RenderEngine> engine)
        : renderEngine(std::move(engine))
{
    /* Create Window */
    renderEngine->createWindow(800, 600, "3D Rendering Engine", true);

    /* Create Camera */
    renderEngine->createCamera(glm::vec3(0.0f, 0.0f, -5.0f));

    /* Load Shaders */
    renderEngine->loadShader(0, "assets/shaders/specularMap.vert", "assets/shaders/specularMap.frag");

    /* Create Lighting */
    lightSource = std::make_shared<Engine::LightSource>(glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.2f, 0.5f, 1.0f);
    renderEngine->loadLightSource(lightSource);

    renderEngine->setSkyColor(glm::vec3(0.2f));

    /* Load Objects */
    cubeVAO = Engine::helpers::loadModel("assets/objects/cube.obj");

    /* Create Graphics */
    Engine::Transform cubeTransform = {glm::vec3(-1.5f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.5f};
    auto cubeTexture = std::make_shared<Engine::Texture>("assets/images/container.png");
    auto cubeSpecularMap = std::make_shared<Engine::Texture>("assets/images/container_specular.png");
    cube = std::make_shared<Engine::Object>(cubeVAO, cubeTransform, cubeTexture, cubeSpecularMap, 32.0f);
    renderEngine->loadObject(cube, 0);
}