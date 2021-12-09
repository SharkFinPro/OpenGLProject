#ifndef OPENGLPROJECT_SHADERMANAGER_H
#define OPENGLPROJECT_SHADERMANAGER_H

#include "ShaderProgram.h"
#include <map>
#include <memory>

class ShaderManager {
private:
    std::map<int, std::shared_ptr<ShaderProgram>> shaders;

public:
    ShaderManager();

    void loadShader(int key, const char* vertexShader, const char* fragmentShader);

    [[nodiscard]] std::shared_ptr<ShaderProgram> getShader(int key) const;
};


#endif //OPENGLPROJECT_SHADERMANAGER_H
