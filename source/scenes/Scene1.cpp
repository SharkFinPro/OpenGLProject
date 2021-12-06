#include "Scene1.h"
#include "cube.h"
#include <cmath>

Scene1::Scene1(std::shared_ptr<RenderEngine> engine)
    : renderEngine(std::move(engine))
{
    // Load Shaders
    renderEngine->loadShader(0, "assets/shaders/cube/cube.vert", "assets/shaders/cube/cube.frag");
    renderEngine->loadShader(1, "assets/shaders/light objects/light.vert", "assets/shaders/light objects/light.frag");

    /* Create Graphics */
    cubeVAO = std::make_shared<VAO>(true, false);
    cubeVAO->loadVBO(cubeVertices, sizeof(cubeVertices), 36);
    cubeVAO->addAttribute(0, 3, 6, 0);
    cubeVAO->addAttribute(1, 3, 6, 3);

    Transform cubeTransform = {glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f};
    Material cubeMaterial = { 0.4f, 0.75f, 0.5f, 32.0f, glm::vec3(0.9f, 0.5f, 0.75f)};
    cube = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial);
    cubeTransform.position = glm::vec3(-3.0f, 1.0f, 0.0f);
    cubeMaterial.color = glm::vec3(0.2f, 0.5f, 0.75f);
    cube2 = std::make_shared<Object>(cubeVAO, cubeTransform, cubeMaterial);

    Transform lightCubeTransform = {glm::vec3(1.2f, 1.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.2f};
    Material lightCubeMaterial = { 0.4f, 0.75f, 1.0f, 0.0f, glm::vec3(1.0f, 1.0f, 1.0f)};
    lightCube = std::make_shared<LightSource>(cubeVAO, lightCubeTransform, lightCubeMaterial);

    // Load Objects
    renderEngine->loadObject(cube, 0);
    renderEngine->loadObject(cube2, 0);
    renderEngine->loadLight(lightCube, 1);
}

void Scene1::update()
{
    pos += 0.05f;

    cube->move(glm::vec3(0.0f, std::sin(pos) * 2 - cube->getTransform().position.y, 0.0f));
}