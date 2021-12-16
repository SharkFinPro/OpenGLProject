#include "EBO.h"
#include <glad/glad.h>

namespace Engine {
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

    void EBO::loadIndices(unsigned int *indices, int size, unsigned int faces)
    {
        faceCount = faces;
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
    }

    unsigned int EBO::getFaceCount() const
    {
        return faceCount;
    }
}