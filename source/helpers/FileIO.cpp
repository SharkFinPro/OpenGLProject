#include "FileIO.h"

#include <fstream>
#include <sstream>

namespace helpers
{
    void fileToString(const char* fileName, std::string& output) {
        std::ifstream file(fileName);
        std::stringstream outputStream;

        outputStream << file.rdbuf();

        output = outputStream.str();
    }
}