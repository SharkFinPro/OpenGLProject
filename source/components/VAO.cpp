#include "VAO.h"

#include <glad/glad.h>

VAO::VAO(float vertices[], int verticesSize, unsigned int indices[], int indicesSize, unsigned int triangles)
{
    this->triangles = triangles;
    glGenVertexArrays(1, &vaoID);
    glGenBuffers(1, &vboID);
    glGenBuffers(1, &eboID);

    bind();
    bindBuffers();

    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);

    unbind();
}

VAO::~VAO()
{
    glDeleteBuffers(1, &vboID);
    glDeleteBuffers(1, &eboID);
    glDeleteVertexArrays(1, &vaoID);
}

void VAO::bind() const
{
    glBindVertexArray(vaoID);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::bindBuffers() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
}

void VAO::addAttribute(int index, int size, int stride, int distance)
{
    bind();
    bindBuffers();
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(distance * sizeof(float)));
    glEnableVertexAttribArray(index);
}

void VAO::draw() const
{
    bind();
    glDrawElements(GL_TRIANGLES, triangles, GL_UNSIGNED_INT, nullptr);
}