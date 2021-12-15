#ifndef OPENGLPROJECT_FILEIO_H
#define OPENGLPROJECT_FILEIO_H

#include "../components/objects/raw/VAO.h"
#include <string>

namespace Engine::helpers {
    void fileToString(const char *path, std::string &output);

    std::shared_ptr<VAO> loadModel(const char *path);
}

#endif //OPENGLPROJECT_FILEIO_H