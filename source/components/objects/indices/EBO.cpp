#include "EBO.h"

#include <glad/glad.h>

EBO::EBO()
{
    glGenBuffers(1, &id);
}

EBO::~EBO()
{
    glDeleteBuffers(1, &id);
}

void EBO::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::load(unsigned int indices[], int indicesSize, unsigned int triangles)
{
    this->triangles = triangles;
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
}

unsigned int EBO::getTriangles() const
{
    return triangles;
}