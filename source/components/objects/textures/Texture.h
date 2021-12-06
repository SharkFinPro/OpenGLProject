#ifndef OPENGLPROJECT_TEXTURE_H
#define OPENGLPROJECT_TEXTURE_H

#include <glad/glad.h>

class Texture {
private:
    unsigned int textureID{};

public:
    Texture(const char* fileName, const char* fileType);
    ~Texture();

    void bind(GLenum layer) const;

    static void unBind();
};


#endif //OPENGLPROJECT_TEXTURE_H
