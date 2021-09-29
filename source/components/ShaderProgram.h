#ifndef OPENGLPROJECT_SHADERPROGRAM_H
#define OPENGLPROJECT_SHADERPROGRAM_H

class ShaderProgram {
private:
    unsigned int programID;

public:
    ShaderProgram(const char* vertex, const char* fragment);

    void use();

    void setUniform(const char* name, int value);
    void setUniform(const char* name, bool value);
    void setUniform(const char* name, float value);
};

#endif //OPENGLPROJECT_SHADERPROGRAM_H
