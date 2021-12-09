#include "ShaderManager.h"

ShaderManager::ShaderManager()
= default;

void ShaderManager::loadShader(int key, const char* vertexShader, const char* fragmentShader)
{
    shaders.insert({ key, std::make_shared<ShaderProgram>(vertexShader, fragmentShader) });
}

std::shared_ptr<ShaderProgram> ShaderManager::getShader(int key) const
{
    return shaders.at(key);
}