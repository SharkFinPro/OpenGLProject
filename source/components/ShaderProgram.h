#ifndef OPENGLPROJECT_SHADERPROGRAM_H
#define OPENGLPROJECT_SHADERPROGRAM_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Engine {
    class ShaderProgram {
    private:
        unsigned int programID;

        static unsigned int activeProgramID;

    public:
        ShaderProgram(const char *vertex, const char *fragment);

        ~ShaderProgram();

        void use() const;

        static void setUniform(const char *name, const int &value);

        static void setUniform(const char *name, const bool &value);

        static void setUniform(const char *name, const float &value);

        static void setUniform(const char *name, const glm::mat4 &value);

        static void setUniform(const char *name, const float &x, const float &y, const float &z);

        static void setUniform(const char *name, glm::vec3 vec3);
    };
}

#endif //OPENGLPROJECT_SHADERPROGRAM_H