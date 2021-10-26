#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

#include <stdexcept>

#include "components/Window.h"
#include "components/ShaderProgram.h"
#include "components/Texture.h"
#include "components/VAO.h"
#include "components/Camera.h"

int main()
{
    /* Initialize GLFW */
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    /* Create Window */
    auto window = new Window(800, 600, "Learn OpenGL");
    window->makeCurrentContext();

    /* Load GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    /* Camera */
    auto camera = new Camera();

    /* Load Shaders */
    auto cubeShader = new ShaderProgram("source/shaders/cube.vert", "source/shaders/cube.frag");
    auto lightCubeShader = new ShaderProgram("source/shaders/lightCube.vert", "source/shaders/lightCube.frag");
    glEnable(GL_DEPTH_TEST);

    /* Create Graphics */
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };

    auto cubeVAO = new VAO(true, false);
    cubeVAO->loadVBO(vertices, sizeof(vertices), 36);
    cubeVAO->addAttribute(0, 3, 3, 0);

    auto lightCubeVAO = new VAO(true, false);
    lightCubeVAO->loadVBO(vertices, sizeof(vertices), 36);
    lightCubeVAO->addAttribute(0, 3, 3, 0);

    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

    /* Main loop */
    while (!window->shouldClose())
    {
        // Input
        window->processInput();
        camera->processInput(window);

        // Clear canvas
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw cube
        cubeShader->use();
        cubeShader->setUniform("objectColor", 1.0f, 0.5f, 0.31f);
        cubeShader->setUniform("lightColor",  1.0f, 1.0f, 1.0f);

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
        glm::mat4 view = camera->getViewMatrix();

        cubeShader->setUniform("model", model);
        cubeShader->setUniform("view", view);
        cubeShader->setUniform("projection", projection);

        cubeVAO->draw();


        // Draw light cube
        lightCubeShader->use();

        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));
        projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
        view = camera->getViewMatrix();

        lightCubeShader->setUniform("model", model);
        lightCubeShader->setUniform("view", view);
        lightCubeShader->setUniform("projection", projection);

        lightCubeVAO->draw();

        // Check & call events & swap the buffers
        window->update();
    }

    /* Cleanup & Exit */
    delete cubeShader;
    delete lightCubeShader;
    delete cubeVAO;
    delete lightCubeVAO;
    delete camera;
    delete window;
    glfwTerminate();

    return 0;
}