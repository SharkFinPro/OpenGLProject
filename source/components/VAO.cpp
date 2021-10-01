#include "VAO.h"

#include <glad/glad.h>

VAO::VAO(VBO* vbo, EBO* ebo)
{
    this->vbo = vbo;
    this->ebo = ebo;

    glGenVertexArrays(1, &vaoID);
}

VAO::~VAO()
{
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

void VAO::addAttribute(int index, int size, int stride, int distance) const
{
    bind();
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(distance * sizeof(float)));
    glEnableVertexAttribArray(index);
}

void VAO::draw() const
{
    bind();
    if (ebo != nullptr) {
        glDrawElements(GL_TRIANGLES, ebo->getTriangles(), GL_UNSIGNED_INT, nullptr);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, vbo->getVerticesCount());
    }
}