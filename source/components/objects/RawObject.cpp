#include "RawObject.h"

RawObject::RawObject(std::shared_ptr<VAO> vao, std::shared_ptr<Texture> texture)
    : vao(vao), texture(texture)
{

}

void RawObject::render() const
{
    vao->draw();
}