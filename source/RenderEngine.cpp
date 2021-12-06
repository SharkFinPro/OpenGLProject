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

void RenderEngine::loadLightData() const
{
    std::shared_ptr<LightSource> light = lights.front().first;
    Material material = light->getLightMaterial();

    ShaderProgram::setUniform("light.position",  light->getPosition());
    ShaderProgram::setUniform("light.color", material.color);
    ShaderProgram::setUniform("light.ambient",  glm::vec3(material.ambient));
    ShaderProgram::setUniform("light.diffuse",  glm::vec3(material.diffuse));
    ShaderProgram::setUniform("light.specular",  glm::vec3(material.specular));
}

void RenderEngine::renderObject(const std::shared_ptr<Object>& object, int shaderKey) const
{
    // Set objects shader to use
    auto shaderProgram = shaderManager->getShader(shaderKey);
    shaderProgram->use();

    // Load uniforms
    loadLightData();
    ShaderProgram::setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

    // Load object matrices
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, object->getPosition());
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    ShaderProgram::setUniform("model", model);
    ShaderProgram::setUniform("view", camera->getViewMatrix());
    ShaderProgram::setUniform("projection", projection);

    // Render
    object->render();
}

void RenderEngine::renderLight(const std::shared_ptr<LightSource>& object, int shaderKey) const
{
    auto shaderProgram = shaderManager->getShader(shaderKey);

    shaderProgram->use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, object->getPosition());
    model = glm::scale(model, glm::vec3(0.2f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    ShaderProgram::setUniform("model", model);
    ShaderProgram::setUniform("view", camera->getViewMatrix());
    ShaderProgram::setUniform("projection", projection);

    object->render();
}

void RenderEngine::render()
{
    if (window->shouldClose())
    {
        closing = true;
        return;
    }

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

void RenderEngine::loadShader(int key, const char *vertexShader, const char *fragmentShader)
{
    shaderManager->loadShader(key, vertexShader, fragmentShader);
}

void RenderEngine::loadObject(const std::shared_ptr<Object>& object, int shaderKey)
{
    objects.emplace_back(std::make_pair(object, shaderKey));
}

void RenderEngine::loadLight(const std::shared_ptr<LightSource>& object, int shaderKey)
{
    lights.emplace_back(std::make_pair(object, shaderKey));
}

bool RenderEngine::shouldClose() const
{
    return closing;
}