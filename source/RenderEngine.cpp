#include "RenderEngine.h"
#include <stdexcept>

RenderEngine::RenderEngine(bool fullscreen)
{
    /* Initialize GLFW */
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    /* Create Window */
    window = std::make_shared<Window>(800, 600, "3D Rendering Engine", fullscreen);
    window->makeCurrentContext();

    /* Load GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");

    glEnable(GL_DEPTH_TEST);

    /* Camera */
    camera = std::make_unique<Camera>(glm::vec3(0.0f, 0.0f, -5.0f));

    /* Shader Manager */
    shaderManager = std::make_unique<ShaderManager>();
}

RenderEngine::~RenderEngine()
{
    glfwTerminate();
}

void RenderEngine::loadLightData(const std::shared_ptr<ShaderProgram>& shaderProgram) const
{
    glm::vec3 lightPosition = lights.front().first->getPosition();
    glm::vec3 lightColor = lights.front().first->getColor();
    shaderProgram->setUniform("light.position",  lightPosition.x, lightPosition.y, lightPosition.z);
    shaderProgram->setUniform("light.color", lightColor.x, lightColor.y, lightColor.z);

    shaderProgram->setUniform("light.ambient",  0.4f, 0.4f, 0.4f);
    shaderProgram->setUniform("light.diffuse",  0.75f, 0.75f, 0.75f);
    shaderProgram->setUniform("light.specular",  1.0f, 1.0f, 1.0f);
}

void RenderEngine::renderObject(const std::shared_ptr<Object>& object, int shaderKey) const
{
    // set objects shader to use
    auto shaderProgram = shaderManager->getShader(shaderKey);
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

void RenderEngine::renderLight(const std::shared_ptr<LightObject>& object, int shaderKey) const
{
    auto shaderProgram = shaderManager->getShader(shaderKey);

    shaderProgram->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, object->getPosition());
    model = glm::scale(model, glm::vec3(0.2f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

    object->render(shaderProgram);
}

void RenderEngine::render()
{
    while (!window->shouldClose())
    {
        // Input
        window->processInput();
        camera->processInput(window);

        // Clear canvas
        glClearColor(skyColor.x, skyColor.y, skyColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render
        for (auto &object : objects)
            renderObject(object.first, object.second);

        for (auto &light : lights)
            renderLight(light.first, light.second);

        // Update window
        window->update();
    }
}

void RenderEngine::loadShader(int key, const char *vertexShader, const char *fragmentShader)
{
    shaderManager->loadShader(key, vertexShader, fragmentShader);
}

void RenderEngine::loadObject(const std::shared_ptr<Object>& object, int shaderKey)
{
    objects.emplace_back(std::make_pair(object, shaderKey));
}

void RenderEngine::loadLight(const std::shared_ptr<LightObject>& object, int shaderKey)
{
    lights.emplace_back(std::make_pair(object, shaderKey));
}