#include "Mesh.h"

#include <glad/glad.h>

Mesh::Mesh(std::vector<Vertex_> vertices, std::vector<unsigned int> indices, std::vector<Texture_> textures)
    : vertices(vertices), indices(indices), textures(std::move(textures))
{
    vao = std::make_shared<VAO>(true, true);
    vao->loadVBO(vertices);
    vao->loadEBO(&indices[0], indices.size() * sizeof(unsigned int), indices.size());

    vao->addAttribute(0, 3, sizeof(Vertex_), 0);
    vao->addAttribute(1, 3, sizeof(Vertex_), offsetof(Vertex_, normal));
    vao->addAttribute(2, 2, sizeof(Vertex_), offsetof(Vertex_, textureCoordinates));
}