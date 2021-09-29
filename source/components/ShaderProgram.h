#ifndef OPENGLPROJECT_SHADERPROGRAM_H
#define OPENGLPROJECT_SHADERPROGRAM_H

class ShaderProgram {
private:
    unsigned int programID;

public:
    ShaderProgram(const char* vertex, const char* fragment);
    ~ShaderProgram();

    void use() const;

    void setUniform(const char* name, int value) const;
    void setUniform(const char* name, bool value) const;
    void setUniform(const char* name, float value) const;
};

#endif //OPENGLPROJECT_SHADERPROGRAM_H
