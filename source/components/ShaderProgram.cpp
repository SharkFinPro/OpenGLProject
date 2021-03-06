#include "ShaderProgram.h"
#include <glad/glad.h>
#include <stdexcept>
#include "../helpers/FileIO.h"

namespace Engine {
    unsigned int ShaderProgram::activeProgramID = 0;

    ShaderProgram::ShaderProgram(const char *vertex, const char *fragment)
    {
        auto vertexShaderSourceString = helpers::fileToString(vertex);
        auto vertexShaderSource = vertexShaderSourceString.c_str();
        auto fragmentShaderSourceString = helpers::fileToString(fragment);
        auto fragmentShaderSource = fragmentShaderSourceString.c_str();

        // Load Vertex Shader
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            throw std::runtime_error("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" + std::string(infoLog));
        }

        // Load Fragment Shader
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            throw std::runtime_error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" + std::string(infoLog));
        }

        // Create Shader Program
        programID = glCreateProgram();

        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);

        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(programID, 512, nullptr, infoLog);
            throw std::runtime_error("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(infoLog));
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(programID);
    }

    void ShaderProgram::use() const
    {
        glUseProgram(programID);
        activeProgramID = programID;
    }

    void ShaderProgram::setUniform(const char *name, const int &value)
    {
        glUniform1i(glGetUniformLocation(activeProgramID, name), value);
    }

    void ShaderProgram::setUniform(const char *name, const bool &value)
    {
        glUniform1i(glGetUniformLocation(activeProgramID, name), value);
    }

    void ShaderProgram::setUniform(const char *name, const float &value)
    {
        glUniform1f(glGetUniformLocation(activeProgramID, name), value);
    }

    void ShaderProgram::setUniform(const char *name, const glm::mat4 &value)
    {
        glUniformMatrix4fv(glGetUniformLocation(activeProgramID, name), 1, GL_FALSE, glm::value_ptr(value));
    }

    void ShaderProgram::setUniform(const char *name, const float &x, const float &y, const float &z)
    {
        glUniform3f(glGetUniformLocation(activeProgramID, name), x, y, z);
    }

    void ShaderProgram::setUniform(const char *name, glm::vec3 vec3)
    {
        glUniform3f(glGetUniformLocation(activeProgramID, name), vec3.x, vec3.y, vec3.z);
    }
}