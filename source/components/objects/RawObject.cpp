#include "RawObject.h"

RawObject::RawObject(glm::vec3 position, std::shared_ptr<VAO> vao, std::shared_ptr<Texture> texture)
    : position(position), vao(vao), texture(texture)
{

}

void RawObject::render() const
{
    vao->draw();
}

glm::vec3 RawObject::getPosition() const
{
    return position;
}