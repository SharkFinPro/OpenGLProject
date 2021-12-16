#ifndef OPENGLPROJECT_VBO_H
#define OPENGLPROJECT_VBO_H

namespace Engine {
    class VBO {
    private:
        unsigned int id{};
        unsigned int verticesCount{};

    public:
        VBO();
        ~VBO();

        void bind() const;

        void loadVertices(float vertices[], int size, unsigned int count = {});

        [[nodiscard]] unsigned int getVerticesCount() const;
    };
}

#endif //OPENGLPROJECT_VBO_H