#ifndef OPENGLPROJECT_TEXTURE_H
#define OPENGLPROJECT_TEXTURE_H

#include <glad/glad.h>

namespace Engine {
    class Texture {
    private:
        unsigned int textureID{};

    public:
        explicit Texture(const char *path, bool flip = true);

        ~Texture();

        void bind(GLenum layer) const;

        static void unBind();
    };
}

#endif //OPENGLPROJECT_TEXTURE_H