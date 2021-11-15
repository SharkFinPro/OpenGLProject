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

    glEnable(GL_DEPTH_TEST);

    /* Camera */
    camera = new Camera(glm::vec3(0.0f, 0.0f, -5.0f));

    /* Shader Manager */
    shaderManager = new ShaderManager();
}

RenderEngine::~RenderEngine()
{
    delete window;
    delete camera;

    glfwTerminate();
}

bool RenderEngine::windowShouldClose()
{
    return window->shouldClose();
}

void RenderEngine::updateWindow()
{
    window->update();
}

void RenderEngine::loadLightData(const ShaderProgram* shaderProgram) const
{
    shaderProgram->setUniform("light.position",  lightPosition.x, lightPosition.y, lightPosition.z);
    shaderProgram->setUniform("light.color", lightColor.x, lightColor.y, lightColor.z);

    shaderProgram->setUniform("light.ambient",  0.4f, 0.4f, 0.4f);
    shaderProgram->setUniform("light.diffuse",  0.75f, 0.75f, 0.75f);
    shaderProgram->setUniform("light.specular",  1.0f, 1.0f, 1.0f);
}

void RenderEngine::render(Object* object, int shaderKey)
{
    // set objects shader to use
    const ShaderProgram* shaderProgram = shaderManager->getShader(shaderKey);
    shaderProgram->use();

    // Load uniforms
    loadLightData(shaderProgram);
    shaderProgram->setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

    // load object matrices
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

    // render
    object->render(shaderProgram);
}

void RenderEngine::renderLight(Object *object, int shaderKey)
{
    const ShaderProgram* shaderProgram = shaderManager->getShader(shaderKey);

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

void RenderEngine::loadShader(int key, const char *vertexShader, const char *fragmentShader)
{
    shaderManager->loadShader(key, vertexShader, fragmentShader);
}