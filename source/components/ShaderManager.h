#ifndef OPENGLPROJECT_SHADERMANAGER_H
#define OPENGLPROJECT_SHADERMANAGER_H

#include <map>
#include "ShaderProgram.h"

class ShaderManager {
private:
    std::map<int, ShaderProgram*> shaders;

public:
    ShaderManager();
    ~ShaderManager();

    void loadShader(int key, const char* vertexShader, const char* fragmentShader);

    const ShaderProgram* getShader(int key) const;
};


#endif //OPENGLPROJECT_SHADERMANAGER_H
