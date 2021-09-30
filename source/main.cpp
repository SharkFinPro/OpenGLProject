#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

#include "components/Window.h"
#include "components/ShaderProgram.h"
#include "components/Texture.h"
#include "components/VAO.h"

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
    auto shaderProgram = new ShaderProgram("source/shaders/vertex.vert", "source/shaders/fragment.frag");

    /* Create Graphics */
    float vertices[] = {
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

    auto vao = new VAO(vertices, sizeof(vertices), indices, sizeof(indices));

    /* Load & Create Texture */
    auto texture1 = new Texture("source/images/wall.jpg", "jpg");
    auto texture2 = new Texture("source/images/awesomeface.png", "png");

    /* Set Uniforms */
    shaderProgram->use();
    shaderProgram->setUniform("texture1", 0);
    shaderProgram->setUniform("texture2", 1);

    /* Main loop */
    while (!window->shouldClose())
    {
        // Input
        window->processInput();

        // Clear canvas
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use shader
        shaderProgram->use();

        // Bind texture
        texture1->bind(GL_TEXTURE0);
        texture2->bind(GL_TEXTURE1);

        // Draw Object
        //glBindVertexArray(VAO);
        vao->bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        // Check & call events & swap the buffers
        window->update();
    }

    /* Cleanup & Exit */
    delete texture1;
    delete texture2;
    delete vao;
    delete shaderProgram;
    delete window;
    glfwTerminate();

    return 0;
}