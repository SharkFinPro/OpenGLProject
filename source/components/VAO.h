#ifndef OPENGLPROJECT_VAO_H
#define OPENGLPROJECT_VAO_H

#include "EBO.h"
#include "VBO.h"

class VAO {
private:
    unsigned int vaoID{};
    VBO* vbo;
    EBO* ebo;


    static void unbind();

public:
    VAO(VBO* vbo, EBO* ebo = nullptr);
    ~VAO();

    void bind() const;

    void addAttribute(int index, int size, int stride, int distance) const;

    void draw() const;
};


#endif //OPENGLPROJECT_VAO_H
