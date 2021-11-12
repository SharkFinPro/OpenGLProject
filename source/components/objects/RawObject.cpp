#include "RawObject.h"

RawObject::RawObject(VAO *vao, Texture *texture)
    : vao(vao), texture(texture)
{

}

RawObject::~RawObject()
{
    delete vao;
    delete texture;
}

void RawObject::render() const
{
    vao->draw();
}