#include "RawObject.h"
#include "../ShaderProgram.h"

namespace Engine {
    RawObject::RawObject(std::shared_ptr<VAO> vao, Transform transform, std::shared_ptr<Texture> texture)
        : transform(transform), vao(std::move(vao)), texture(std::move(texture))
    {}

    RawObject::~RawObject()
    = default;

    void RawObject::render() const
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(transform.scale));
        model = glm::translate(model, transform.position);

        ShaderProgram::setUniform("model", model);

        if (texture)
            texture->bind(0);
        else
            Texture::unBind();

        vao->draw();
    }

    void RawObject::move(glm::vec3 change)
    {
        transform.position += change;
    }
}