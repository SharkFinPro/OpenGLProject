#ifndef OPENGLPROJECT_VAO_H
#define OPENGLPROJECT_VAO_H

#include "EBO.h"
#include "VBO.h"

class VAO {
private:
    unsigned int id{};
    VBO* vbo = nullptr;
    EBO* ebo = nullptr;

    static void unbind();

public:
    VAO(bool useVBO, bool useEBO);
    ~VAO();

    void bind() const;

    void loadVBO(float vertices[], int verticesSize, unsigned int verticesCount = {});
    void loadEBO(unsigned int indices[], int indicesSize, unsigned int triangles);
    void addAttribute(int index, int size, int stride, int distance) const;

    void draw() const;
};


#endif //OPENGLPROJECT_VAO_H
