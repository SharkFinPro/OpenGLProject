#ifndef OPENGLPROJECT_VAO_H
#define OPENGLPROJECT_VAO_H


class VAO {
private:
    unsigned int vaoID{}, vboID{}, eboID{}, triangles;
    static void unbind();

    void bindBuffers() const;

public:
    VAO(float vertices[], int verticesSize, unsigned int indices[], int indicesSize, unsigned int triangles);
    ~VAO();

    void bind() const;

    void addAttribute(int index, int size, int stride, int distance);

    void draw() const;
};


#endif //OPENGLPROJECT_VAO_H
