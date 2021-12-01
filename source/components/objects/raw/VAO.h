#ifndef OPENGLPROJECT_VAO_H
#define OPENGLPROJECT_VAO_H

#include "EBO.h"
#include "VBO.h"
#include <memory>
#include <vector>

class VAO {
private:
    unsigned int id{};
    std::shared_ptr<VBO> vbo;
    std::shared_ptr<EBO> ebo;

public:
    VAO(bool useVBO, bool useEBO);
    ~VAO();

    void bind() const;

    void loadVBO(float vertices[], int verticesSize, unsigned int verticesCount = {});
    [[maybe_unused]] void loadEBO(unsigned int indices[], int indicesSize, unsigned int triangles);
    void addAttribute(int index, int size, int stride, int distance) const;

    void draw() const;
};


#endif //OPENGLPROJECT_VAO_H
