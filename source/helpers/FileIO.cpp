#include "FileIO.h"

#include <fstream>
#include <sstream>

namespace helpers
{
    bool fileToString(const char* fileName, std::string& output) {
        std::ifstream file(fileName);
        std::stringstream outputStream;

        outputStream << file.rdbuf();

        output = outputStream.str();

        return true;
    }
}