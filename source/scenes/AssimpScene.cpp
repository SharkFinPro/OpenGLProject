#include "AssimpScene.h"

#include "../helpers/FileIO.h"

AssimpScene::AssimpScene(std::shared_ptr<RenderEngine> engine)
        : renderEngine(std::move(engine))
{
    // Load Shaders
    renderEngine->loadShader(0, "assets/shaders/cube/cube.vert", "assets/shaders/cube/cube.frag");
    renderEngine->loadShader(1, "assets/shaders/cube/texturedCube.vert", "assets/shaders/cube/texturedCube.frag");
    renderEngine->loadShader(2, "assets/shaders/light objects/light.vert", "assets/shaders/light objects/light.frag");

    /* Create Graphics */
    cubeVAO = helpers::loadModel("assets/objects/cube.obj");

    Transform cubeTransform = {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.75f};
    Material cubeMaterial = { 0.4f, 0.75f, 0.5f, 32.0f, glm::vec3(0.9f, 0.5f, 0.75f)};
    auto cubeTexture = std::make_shared<Texture>("assets/images/wall.jpg");
    cube = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial, cubeTexture);
    cubeTransform.position = glm::vec3(-3.0f, 1.0f, 0.0f);
    cubeMaterial.color = glm::vec3(0.2f, 0.5f, 0.75f);
    cube2 = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial);

    Transform lightCubeTransform = {glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f};
    Material lightCubeMaterial = { 0.4f, 0.75f, 1.0f, 0.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
    lightCube = std::make_shared<LightSource>(cubeVAO, lightCubeTransform, lightCubeMaterial);

    // Load Objects
    renderEngine->loadObject(cube, 1);
    renderEngine->loadObject(cube2, 0);
    renderEngine->loadLight(lightCube, 2);
}

void AssimpScene::update()
{}