#if !defined(RTWEEKEND_COLOR_H)
#define RTWEEKEND_COLOR_H

#include "vec.h"
#include <ostream>

namespace rt
{
    using color = vec3;

    void write_color(std::ostream &os, const color &color)
    {
        auto r = color.x();
        auto g = color.y();
        auto b = color.z();

        int rbyte = int(255.999 * r);
        int gbyte = int(255.999 * g);
        int bbyte = int(255.999 * b);

        os << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    }
}

#endif // RTWEEKEND_COLOR_H
