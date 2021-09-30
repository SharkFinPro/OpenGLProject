#ifndef OPENGLPROJECT_SHADERPROGRAM_H
#define OPENGLPROJECT_SHADERPROGRAM_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram {
private:
    unsigned int programID;

public:
    ShaderProgram(const char* vertex, const char* fragment);
    ~ShaderProgram();

    void use() const;

    void setUniform(const char* name, const int& value) const;
    void setUniform(const char* name, const bool& value) const;
    void setUniform(const char* name, const float& value) const;
    void setUniform(const char* name, const glm::mat4& value) const;
};

#endif //OPENGLPROJECT_SHADERPROGRAM_H
