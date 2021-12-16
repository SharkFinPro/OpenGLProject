#include "VAO.h"
#include <glad/glad.h>

namespace Engine {
    VAO::VAO(bool useVBO, bool useEBO)
    {
        if (useVBO)
            vbo = std::make_shared<VBO>();

        if (useEBO)
            ebo = std::make_shared<EBO>();

        glGenVertexArrays(1, &id);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &id);
    }

    void VAO::bind() const
    {
        glBindVertexArray(id);
    }

    void VAO::addAttribute(int index, int size, int stride, int distance) const
    {
        bind();
        glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, static_cast<GLsizei>(stride * sizeof(float)), (void *) (distance * sizeof(float)));
        glEnableVertexAttribArray(index);
    }

    void VAO::loadVBO(float *vertices, int verticesSize, unsigned int verticesCount)
    {
        bind();
        vbo->loadVertices(vertices, verticesSize, verticesCount);
    }

    void VAO::loadEBO(unsigned int *indices, int indicesSize, unsigned int triangles)
    {
        bind();
        ebo->loadIndices(indices, indicesSize, triangles);
    }

    void VAO::draw() const
    {
        bind();
        if (ebo != nullptr)
            glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(ebo->getFaceCount()), GL_UNSIGNED_INT, nullptr);
        else
            glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vbo->getVerticesCount()));
    }
}