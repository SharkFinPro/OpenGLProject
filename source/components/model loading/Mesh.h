#ifndef OPENGLPROJECT_MESH_H
#define OPENGLPROJECT_MESH_H

#include <vector>
#include "../objects/raw/VAO.h"
#include "StructData.h"

class Mesh {
private:
    std::vector<Vertex_> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture_> textures;

    std::shared_ptr<VAO> vao;

public:
    Mesh(std::vector<Vertex_> vertices, std::vector<unsigned int> indices, std::vector<Texture_> textures);
};


#endif //OPENGLPROJECT_MESH_H
