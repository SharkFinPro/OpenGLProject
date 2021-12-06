#include "LightSource.h"

LightSource::LightSource(const std::shared_ptr<VAO>& vao, Transform transform, Material material)
    : Object(vao, transform, material)
{}