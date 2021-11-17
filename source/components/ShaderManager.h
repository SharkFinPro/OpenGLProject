#ifndef OPENGLPROJECT_SHADERMANAGER_H
#define OPENGLPROJECT_SHADERMANAGER_H

#include <map>
#include "ShaderProgram.h"
#include <memory>

class ShaderManager {
private:
    std::map<int, std::shared_ptr<ShaderProgram>> shaders;

public:
    void loadShader(int key, const char* vertexShader, const char* fragmentShader);

    std::shared_ptr<ShaderProgram> getShader(int key) const;
};


#endif //OPENGLPROJECT_SHADERMANAGER_H
