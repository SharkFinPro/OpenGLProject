#include "RenderEngine.h"
#include <stdexcept>

RenderEngine::RenderEngine()
    : skyColor(glm::vec3(0.0f)), closing(false)
{
    /* Initialize GLFW */
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    /* Shader Manager */
    shaderManager = std::make_unique<ShaderManager>();
}

RenderEngine::~RenderEngine()
{
    glfwTerminate();
}

void RenderEngine::createWindow(int width, int height, const char *name, bool fullscreen)
{
    window = std::make_shared<Window>(width, height, name, fullscreen);
    window->makeCurrentContext();

    /* Load GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");

    glEnable(GL_DEPTH_TEST);
}

void RenderEngine::createCamera(glm::vec3 position)
{
    camera = std::make_unique<Camera>(position);
}

void RenderEngine::renderObject(const std::shared_ptr<Object>& object, int shaderKey)
{
    // Enable object's shader
    shaderManager->getShader(shaderKey)->use();

    // Load uniforms
    lightSource->load();
    ShaderProgram::setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
    ShaderProgram::setUniform("projection", projection);
    ShaderProgram::setUniform("view", camera->getViewMatrix());

    // Render
    object->render();
}

void RenderEngine::render()
{
    // If window can't be rendered to, exit before rendering
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

void RenderEngine::loadLightSource(const std::shared_ptr<LightSource>& source)
{
    lightSource = source;
}

bool RenderEngine::isClosing() const
{
    return closing;
}

void RenderEngine::setSkyColor(glm::vec3 color)
{
    skyColor = color;
}