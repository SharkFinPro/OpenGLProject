#include "LightingScene.h"

#include "../helpers/FileIO.h"

LightingScene::LightingScene(std::shared_ptr<RenderEngine> engine)
        : renderEngine(std::move(engine))
{
    // Load Shaders
    renderEngine->loadShader(0, "assets/shaders/light maps/shader.vert", "assets/shaders/light maps/shader.frag");
    renderEngine->loadShader(1, "assets/shaders/light objects/light.vert", "assets/shaders/light objects/light.frag");

    /* Create Graphics */
    cubeVAO = helpers::loadModel("assets/objects/cube2.obj");

    Transform cubeTransform = {glm::vec3(-1.5f, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.5f};
    Material cubeMaterial = { 0.2f, 0.5f, 0.5f, 32.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
    auto cubeTexture = std::make_shared<Texture>("assets/images/container", "png");
    cube = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial, cubeTexture);

    Transform lightCubeTransform = {glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.3f};
    Material lightCubeMaterial = { 0.2f, 0.5f, 1.0f, 0.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
    lightCube = std::make_shared<LightSource>(cubeVAO, lightCubeTransform, lightCubeMaterial);

    // Load Objects
    renderEngine->loadObject(cube, 0);
    renderEngine->loadLight(lightCube, 1);
}

void LightingScene::update()
{}