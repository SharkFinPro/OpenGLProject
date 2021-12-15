#ifndef OPENGLPROJECT_EBO_H
#define OPENGLPROJECT_EBO_H

namespace Engine {
    class EBO {
    private:
        unsigned int id{}, triangles{};

    public:
        EBO();

        ~EBO();

        void bind() const;

        void load(unsigned int indices[], int indicesSize, unsigned int triangles);

        [[nodiscard]] unsigned int getTriangles() const;
    };
}

#endif //OPENGLPROJECT_EBO_H