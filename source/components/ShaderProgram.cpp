#include "ShaderProgram.h"

#include <glad/glad.h>
#include <iostream>
#include <stdexcept>

#include "../helpers/FileIO.h"

ShaderProgram::ShaderProgram(const char* vertex, const char* fragment)
{
    std::string vertexShaderSourceString, fragmentShaderSourceString;
    helpers::fileToString(vertex, vertexShaderSourceString);
    helpers::fileToString(fragment, fragmentShaderSourceString);
    const char* vertexShaderSource = vertexShaderSourceString.c_str();
    const char* fragmentShaderSource = fragmentShaderSourceString.c_str();

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

void ShaderProgram::use()
{
    glUseProgram(programID);
}

void ShaderProgram::setUniform(const char* name, int value)
{
    glUniform1i(glGetUniformLocation(programID, name), value);
}

void ShaderProgram::setUniform(const char* name, bool value)
{
    glUniform1i(glGetUniformLocation(programID, name), value);
}

void ShaderProgram::setUniform(const char* name, float value)
{
    glUniform1f(glGetUniformLocation(programID, name), value);
}