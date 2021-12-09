#include "LightingScene.h"

#include "../helpers/FileIO.h"

LightingScene::LightingScene(std::shared_ptr<RenderEngine> engine)
        : renderEngine(std::move(engine))
{
    /* Load Shaders */
    renderEngine->loadShader(0, "assets/shaders/specularMap.vert", "assets/shaders/specularMap.frag");

    /* Create Lighting */
    lightSource = std::make_shared<LightSource>(glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.2f, 0.5f, 1.0f);
    renderEngine->loadLightSource(lightSource);

    /* Load Objects */
    cubeVAO = helpers::loadModel("assets/objects/cube.obj");

    /* Create Graphics */
    Transform cubeTransform = {glm::vec3(-1.5f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.5f};
    Material cubeMaterial = { 0.2f, 0.5f, 0.5f, 32.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
    auto cubeTexture = std::make_shared<Texture>("assets/images/container.png");
    auto cubeSpecularMap = std::make_shared<Texture>("assets/images/container_specular.png");
    cube = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial, cubeTexture, cubeSpecularMap);
    renderEngine->loadObject(cube, 0);
}