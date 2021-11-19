#include "VBO.h"
#include <glad/glad.h>

VBO::VBO()
{
    glGenBuffers(1, &id);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &id);
}

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::load(float vertices[], int verticesSize, unsigned int verticesCount)
{
    this->verticesCount = verticesCount;
    bind();
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
}

void VBO::load(std::vector<Vertex_> &vertices)
{
    bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex_), &vertices[0], GL_STATIC_DRAW);
}

unsigned int VBO::getVerticesCount() const
{
    return verticesCount;
}