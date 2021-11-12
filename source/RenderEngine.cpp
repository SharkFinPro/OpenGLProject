#include "RenderEngine.h"

#include <stdexcept>

RenderEngine::RenderEngine()
{
    /* Initialize GLFW */
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    /* Create Window */
    window = new Window(800, 600, "Learn OpenGL", false);
    window->makeCurrentContext();

    /* Load GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");

    /* Camera */
    camera = new Camera(glm::vec3(0.0f, 0.0f, -5.0f));
}

RenderEngine::~RenderEngine()
{
    delete window;
    delete camera;
}

bool RenderEngine::windowShouldClose()
{
    return window->shouldClose();
}

void RenderEngine::updateWindow()
{
    window->update();
}

void RenderEngine::render(Object* object, ShaderProgram* shaderProgram)
{
    // set objects shader to use
    shaderProgram->use();

    // load uniforms
    shaderProgram->setUniform("lightColor", 1.0f, 1.0f, 1.0f);
    shaderProgram->setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

    // load light info
    shaderProgram->setUniform("light.position",  lightPosition.x, lightPosition.y, lightPosition.z);
    shaderProgram->setUniform("light.ambient",  0.4f, 0.4f, 0.4f);
    shaderProgram->setUniform("light.diffuse",  0.75f, 0.75f, 0.75f);
    shaderProgram->setUniform("light.specular",  1.0f, 1.0f, 1.0f);

    // load object matrices
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

    // render
    object->render(shaderProgram);
}
#include <iostream>
void RenderEngine::renderLight(Object *object, ShaderProgram *shaderProgram)
{
    shaderProgram->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, lightPosition);
    model = glm::scale(model, glm::vec3(0.2f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

    object->render(shaderProgram);
}

void RenderEngine::processInput()
{
    window->processInput();
    camera->processInput(window);
}