#ifndef OPENGLPROJECT_VAO_H
#define OPENGLPROJECT_VAO_H


class VAO {
private:
    unsigned int vaoID{}, vboID{}, eboID{};
    static void unbind();

public:
    VAO(float vertices[], int verticesSize, unsigned int indices[], int indicesSize);
    ~VAO();

    void bind() const;
};


#endif //OPENGLPROJECT_VAO_H
