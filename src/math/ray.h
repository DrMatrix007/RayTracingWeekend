#if !defined(WEEKEND_RAY_H)
#define WEEKEND_RAY_H

#include "vec.h"

namespace rt
{
    class ray
    {
    public:
        ray(const vec3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

        inline const vec3 &origin() const { return orig; }
        inline const vec3 &direction() const { return dir; }

        vec3 at(double t) const;

    private:
        vec3 orig;
        vec3 dir;
    };
}

#endif // WEEKEND_RAY_H
