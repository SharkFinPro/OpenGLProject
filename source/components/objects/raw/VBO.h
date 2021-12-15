#ifndef OPENGLPROJECT_VBO_H
#define OPENGLPROJECT_VBO_H

#include <vector>

namespace Engine {
    class VBO {
    private:
        unsigned int id{};
        unsigned int verticesCount{};

    public:
        VBO();

        ~VBO();

        void bind() const;

        void load(float vertices[], int verticesSize, unsigned int verticesCount = {});

        [[nodiscard]] unsigned int getVerticesCount() const;
    };
}

#endif //OPENGLPROJECT_VBO_H