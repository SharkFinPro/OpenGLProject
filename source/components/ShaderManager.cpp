#include "ShaderManager.h"

ShaderManager::ShaderManager()
{

}

ShaderManager::~ShaderManager()
{
    for (auto &shader : shaders)
        delete shader.second;
}

void ShaderManager::loadShader(int key, const char* vertexShader, const char* fragmentShader)
{
    auto* shader = new ShaderProgram(vertexShader, fragmentShader);
    shaders.insert({ key, shader });
}

const ShaderProgram* ShaderManager::getShader(int key) const
{
    return shaders.at(key);
}