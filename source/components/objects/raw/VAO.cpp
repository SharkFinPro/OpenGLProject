#include "VAO.h"

#include <glad/glad.h>

VAO::VAO(bool useVBO, bool useEBO)
{
    if (useVBO)
        vbo = new VBO();

    if (useEBO)
        ebo = new EBO();

    glGenVertexArrays(1, &id);
}

VAO::~VAO()
{
    delete vbo;
    delete ebo;
    glDeleteVertexArrays(1, &id);
}

void VAO::bind() const
{
    glBindVertexArray(id);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::addAttribute(int index, int size, int stride, int distance) const
{
    bind();
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(distance * sizeof(float)));
    glEnableVertexAttribArray(index);
}

void VAO::loadVBO(float *vertices, int verticesSize, unsigned int verticesCount)
{
    bind();
    vbo->load(vertices, verticesSize, verticesCount);
}

void VAO::loadEBO(unsigned int *indices, int indicesSize, unsigned int triangles)
{
    bind();
    ebo->load(indices, indicesSize, triangles);
}

void VAO::draw() const
{
    bind();
    if (ebo != nullptr)
        glDrawElements(GL_TRIANGLES, ebo->getTriangles(), GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, vbo->getVerticesCount());
}