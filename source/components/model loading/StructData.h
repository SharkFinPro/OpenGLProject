#ifndef OPENGLPROJECT_STRUCTDATA_H
#define OPENGLPROJECT_STRUCTDATA_H

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <string>

struct Vertex_ {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoordinates;
};

struct Texture_ {
    unsigned int id;
    std::string type;
};

#endif //OPENGLPROJECT_STRUCTDATA_H
