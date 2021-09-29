#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <cmath>

#include "components/Window.h"
#include "components/ShaderProgram.h"

void render(Window* window, ShaderProgram* shaderProgram, unsigned int& VAO);

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
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };

    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    // Create VAO & VBO & EBO
    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void*>(nullptr));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    /* Main loop */
    while (!window->shouldClose())
    {
        render(window, shaderProgram, VAO);
    }

    /* Cleanup & Exit */
    delete shaderProgram;
    delete window;
    glfwTerminate();

    return 0;
}

void render(Window* window, ShaderProgram* shaderProgram, unsigned int& VAO)
{
    // Input
    window->processInput();

    // Rendering
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Use shader
    shaderProgram->use();

    // Update uniforms
    float greenValue = (std::sin(static_cast<float>(glfwGetTime())) / 2.0f) + 0.5f;
    shaderProgram->setUniform("greenColor", greenValue);

    // Draw Object
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    // Check & call events & swap the buffers
    window->update();
}