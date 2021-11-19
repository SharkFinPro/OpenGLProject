#ifndef OPENGLPROJECT_VBO_H
#define OPENGLPROJECT_VBO_H

#include "../../model loading/StructData.h"
#include <vector>

class VBO {
private:
    unsigned int id{};
    unsigned int verticesCount{};

public:
    VBO();
    ~VBO();

    void bind() const;
    void load(float vertices[], int verticesSize, unsigned int verticesCount = {});
    void load(std::vector<Vertex_>& vertices);

    [[nodiscard]] unsigned int getVerticesCount() const;
};


#endif //OPENGLPROJECT_VBO_H
