#ifndef OPENGLPROJECT_OBJECT_H
#define OPENGLPROJECT_OBJECT_H

#include "RawObject.h"
#include "../ShaderProgram.h"
#include "raw/VAO.h"
#include <glm/vec3.hpp>
#include <memory>

namespace Engine {
    class Object : public RawObject {
    private:
        std::shared_ptr<Texture> specularMap;
        float shininess;

    public:
        Object(const std::shared_ptr<VAO> &vao, Transform transform, const std::shared_ptr<Texture> &texture, std::shared_ptr<Texture> specularMap, float shininess);

        void render() const override;
    };
}

#endif //OPENGLPROJECT_OBJECT_H