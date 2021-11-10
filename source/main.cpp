#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

#include <stdexcept>

#include "components/Window.h"
#include "components/ShaderProgram.h"
#include "components/objects/VAO.h"
#include "components/Camera.h"

int main()
{
    /* Initialize GLFW */
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    /* Create Window */
    auto window = new Window(800, 600, "Learn OpenGL", true);
    window->makeCurrentContext();

    /* Load GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw std::runtime_error("Failed to initialize GLAD");

    /* Camera */
    auto camera = new Camera(glm::vec3(0.0f, 0.0f, -5.0f));

    /* Load Shaders */
    auto cubeShader = new ShaderProgram("source/shaders/cube.vert", "source/shaders/cube.frag");
    auto lightCubeShader = new ShaderProgram("source/shaders/lightCube.vert", "source/shaders/lightCube.frag");
    glEnable(GL_DEPTH_TEST);

    /* Create Graphics */
    float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    auto cubeVAO = new VAO(true, false);
    cubeVAO->loadVBO(vertices, sizeof(vertices), 36);
    cubeVAO->addAttribute(0, 3, 6, 0);
    cubeVAO->addAttribute(1, 3, 6, 3);

    auto lightCubeVAO = new VAO(true, false);
    lightCubeVAO->loadVBO(vertices, sizeof(vertices), 36);
    lightCubeVAO->addAttribute(0, 3, 6, 0);

    glm::vec3 lightPos(1.2f, 1.0f, -1.0f);

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
        cubeShader->setUniform("lightColor",  1.0f, 1.0f, 1.0f);
        cubeShader->setUniform("viewPos",  camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);

        // load light info
        cubeShader->setUniform("light.position",  lightPos.x, lightPos.y, lightPos.z);
        cubeShader->setUniform("light.ambient",  0.4f, 0.4f, 0.4f);
        cubeShader->setUniform("light.diffuse",  0.75f, 0.75f, 0.75f);
        cubeShader->setUniform("light.specular",  1.0f, 1.0f, 1.0f);

        // load cube matrices
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
        glm::mat4 view = camera->getViewMatrix();

        cubeShader->setUniform("model", model);
        cubeShader->setUniform("view", view);
        cubeShader->setUniform("projection", projection);

        // load cube specular & shininess
        cubeShader->setUniform("material.specular",  0.5f, 0.5f, 0.5f);
        cubeShader->setUniform("material.shininess",  32.0f);

        // cube 1
        glm::vec3 c = glm::vec3(1.0f, 0.5f, 0.31f);
        glm::vec3 diffuse = c * 0.75f;
        glm::vec3 ambient = diffuse * 0.4f;
        cubeShader->setUniform("material.ambient", ambient.x, ambient.y, ambient.z);
        cubeShader->setUniform("material.diffuse", diffuse.x, diffuse.y, diffuse.z);
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