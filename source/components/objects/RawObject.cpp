#include "RawObject.h"

#include "../ShaderProgram.h"

RawObject::RawObject(std::shared_ptr<VAO> vao, Transform transform, std::shared_ptr<Texture> texture)
    : transform(transform), vao(std::move(vao)), texture(std::move(texture))
{}

void RawObject::render() const
{
    if (texture)
        texture->bind(0);
    else
        Texture::unBind();

    vao->draw();
}

Transform RawObject::getTransform() const
{
    return transform;
}

void RawObject::move(glm::vec3 change)
{
    transform.position += change;
}