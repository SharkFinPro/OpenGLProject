#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

#include <stdexcept>

#include "components/Window.h"
#include "components/ShaderProgram.h"
#include "components/Texture.h"
#include "components/VAO.h"
#include "components/EBO.h"
#include "components/VBO.h"

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

    /* Load Shaders */
//    auto shaderProgram = new ShaderProgram("source/shaders/vertex.vert", "source/shaders/fragment.frag");
    auto shaderProgram = new ShaderProgram("source/shaders/cubeVertex.vert", "source/shaders/cubeFragment.frag");
    glEnable(GL_DEPTH_TEST);

    /* Create Graphics */
    /*float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };

    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    auto ebo = new EBO();
    auto vbo = new VBO();
    auto vao = new VAO(vbo, ebo);
    vao->bind();
    ebo->load(indices, sizeof(indices), 6);
    vbo->load(vertices, sizeof(vertices));

    vao->addAttribute(0, 3, 8, 0); // Position
    vao->addAttribute(1, 3, 8, 3); // Color
    vao->addAttribute(2, 2, 8, 6); // Texture*/

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    auto vbo = new VBO();
    auto vao = new VAO(vbo);
    vao->bind();
    vbo->load(vertices, sizeof(vertices), 36);

    vao->addAttribute(0, 3, 5, 0);
    vao->addAttribute(1, 2, 5, 3);

    /* Load & Create Texture */
    auto texture1 = new Texture("source/images/wall", "jpg");
    auto texture2 = new Texture("source/images/awesomeface", "png");

    /* Set Uniforms */
    shaderProgram->use();
    shaderProgram->setUniform("texture1", 0);
    shaderProgram->setUniform("texture2", 1);

    /* Coordinate Systems */
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    shaderProgram->setUniform("model", model);

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    shaderProgram->setUniform("view", view);

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
    shaderProgram->setUniform("projection", projection);

    /* Main loop */
    while (!window->shouldClose())
    {
        // Input
        window->processInput();

        // Clear canvas
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use shader
        shaderProgram->use();

        // Update uniforms
        model = glm::mat4(1.0f);
        model = glm::rotate(model, (float)(glfwGetTime()) * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        shaderProgram->setUniform("model", model);

        projection = glm::perspective(glm::radians(45.0f), static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight()), 0.1f, 100.0f);
        shaderProgram->setUniform("projection", projection);

        // Bind texture
        texture1->bind(GL_TEXTURE0);
        texture2->bind(GL_TEXTURE1);

        // Draw Object
        vao->draw();

        // Check & call events & swap the buffers
        window->update();
    }

    /* Cleanup & Exit */
    delete texture1;
    delete texture2;
    delete vbo;
    //delete ebo;
    delete vao;
    delete shaderProgram;
    delete window;
    glfwTerminate();

    return 0;
}