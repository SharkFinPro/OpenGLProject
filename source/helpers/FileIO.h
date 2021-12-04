#ifndef OPENGLPROJECT_FILEIO_H
#define OPENGLPROJECT_FILEIO_H

#include <string>

#include "../components/objects/raw/VAO.h"

namespace helpers
{
    void fileToString(const char* path, std::string& output);

    std::shared_ptr<VAO> loadModel(const char* path);
}

#endif //OPENGLPROJECT_FILEIO_H
