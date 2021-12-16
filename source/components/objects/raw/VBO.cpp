#include "VBO.h"
#include <glad/glad.h>

namespace Engine {
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

    void VBO::loadVertices(float *vertices, int size, unsigned int count)
    {
        verticesCount = count;
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    unsigned int VBO::getVerticesCount() const
    {
        return verticesCount;
    }
}