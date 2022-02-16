#include "Math.h"
#include <cmath>

const float RADIAN_CONVERSION = M_PI / 180.0f;

namespace Engine::helpers
{
    float radians(float degrees)
    {
        return degrees * RADIAN_CONVERSION;
    }
}