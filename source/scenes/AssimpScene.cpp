#include "AssimpScene.h"

#include "../helpers/FileIO.h"

AssimpScene::AssimpScene(std::shared_ptr<RenderEngine> engine)
        : renderEngine(std::move(engine))
{
   // Load Shaders
    renderEngine->loadShader(0, "assets/shaders/cube/cube.vert", "assets/shaders/cube/cube.frag");
    renderEngine->loadShader(1, "assets/shaders/light objects/light.vert", "assets/shaders/light objects/light.frag");

    /* Create Graphics */
    cubeVAO = helpers::loadModel("assets/objects/cube.obj");

    LightMaterial cubeMaterial = { 0.4f, 0.75f, 0.5f, 32.0f};
    cube = std::make_shared<Object>(cubeMaterial, cubeVAO, glm::vec3(0, 0, 0), glm::vec3(0.9f, 0.5f, 0.75f));
    cube2 = std::make_shared<Object>(cubeMaterial, cubeVAO, glm::vec3(-3, 1, 0), glm::vec3(0.2f, 0.5f, 0.75f));

    LightMaterial lightCubeMaterial = { 0.4f, 0.75f, 1.0f, 0.0f};
    lightCube = std::make_shared<LightSource>(cubeVAO, lightCubeMaterial, glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f));

    // Load Objects
    renderEngine->loadObject(cube, 0);
    renderEngine->loadObject(cube2, 0);
    renderEngine->loadLight(lightCube, 1);
}

void AssimpScene::update()
{}