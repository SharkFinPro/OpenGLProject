#ifndef OPENGLPROJECT_FILEIO_H
#define OPENGLPROJECT_FILEIO_H

#include "../components/objects/raw/VAO.h"
#include <string>

namespace Engine::helpers
{
    std::string fileToString(const char *path);

    std::shared_ptr<VAO> loadModel(const char *path);
}

#endif //OPENGLPROJECT_FILEIO_H