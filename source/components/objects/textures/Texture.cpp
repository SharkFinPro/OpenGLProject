#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <stdexcept>

Texture::Texture(const char* fileName, const char* fileType)
{
    glGenTextures(1, &textureID);
    bind(GL_TEXTURE0);

    // Set wrapping & filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(std::string(std::string(fileName) + "." + fileType).c_str(), &width, &height, &nrChannels, 0);

    if (data)
    {
        if (strcmp(fileType, "jpg") == 0)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else if (strcmp(fileType, "png") == 0)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
        throw std::runtime_error("Failed to load texture");

    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &textureID);
}

void Texture::bind(GLenum layer) const
{
    glActiveTexture(layer);
    glBindTexture(GL_TEXTURE_2D, textureID);
}