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
    std::shared_ptr<LightSource> light = lights.front().first;
    LightMaterial lightMaterial = light->getLightMaterial();

    shaderProgram->setUniform("light.position",  light->getPosition());
    shaderProgram->setUniform("light.color", light->getColor());
    shaderProgram->setUniform("light.ambient",  glm::vec3(lightMaterial.ambient));
    shaderProgram->setUniform("light.diffuse",  glm::vec3(lightMaterial.diffuse));
    shaderProgram->setUniform("light.specular",  glm::vec3(lightMaterial.specular));
}

void RenderEngine::renderObject(const std::shared_ptr<Object>& object, int shaderKey) const
{
    // set objects shader to use
    auto shaderProgram = shaderManager->getShader(shaderKey);
    shaderProgram->use();

    // Load uniforms
    loadLightData(shaderProgram);
    shaderProgram->setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

    // Lighting data
    LightMaterial lightMaterial = object->getLightMaterial();
    glm::vec3 diffuse = object->getColor() * lightMaterial.diffuse;
    glm::vec3 ambient = diffuse * lightMaterial.ambient;
    shaderProgram->setUniform("material.ambient", ambient.x, ambient.y, ambient.z);
    shaderProgram->setUniform("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
    shaderProgram->setUniform("material.specular",  lightMaterial.specular, lightMaterial.specular, lightMaterial.specular);
    shaderProgram->setUniform("material.shininess",  lightMaterial.shininess);

    // load object matrices
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, object->getPosition());
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

    // render
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

    shaderProgram->setUniform("model", model);
    shaderProgram->setUniform("view", camera->getViewMatrix());
    shaderProgram->setUniform("projection", projection);

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