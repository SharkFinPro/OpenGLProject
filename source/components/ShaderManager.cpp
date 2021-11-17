#include "ShaderManager.h"

void ShaderManager::loadShader(int key, const char* vertexShader, const char* fragmentShader)
{
    auto shader = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);
    shaders.insert({ key, shader });
}

std::shared_ptr<ShaderProgram> ShaderManager::getShader(int key) const
{
    return shaders.at(key);
}