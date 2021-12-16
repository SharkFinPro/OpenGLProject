#ifndef OPENGLPROJECT_EBO_H
#define OPENGLPROJECT_EBO_H

namespace Engine {
    class EBO {
    private:
        unsigned int id{}, faceCount{};

    public:
        EBO();

        ~EBO();

        void bind() const;

        void loadIndices(unsigned int indices[], int size, unsigned int faces);

        [[nodiscard]] unsigned int getFaceCount() const;
    };
}

#endif //OPENGLPROJECT_EBO_H