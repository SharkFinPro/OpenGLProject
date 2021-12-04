#ifndef OPENGLPROJECT_FILEIO_H
#define OPENGLPROJECT_FILEIO_H

#include <string>

#include "../components/objects/raw/VAO.h"

namespace helpers
{
    void fileToString(const char* fileName, std::string& output);

    std::shared_ptr<VAO> loadModel(std::string path);
}

#endif //OPENGLPROJECT_FILEIO_H
