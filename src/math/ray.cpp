#include "ray.h"

using namespace rt;

vec3 rt::ray::at(double t) const
{
    return orig + dir * t;
}