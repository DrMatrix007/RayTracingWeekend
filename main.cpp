#include <iostream>

#include "src/constants.h"
#include "src/math/vec.h"
#include "src/math/color.h"
#include "src/math/ray.h"

using vec3 = rt::vec3;
using color = rt::color;
using ray = rt::ray;

bool hit_sphere(const vec3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

color ray_color(const ray& r) {

    if (hit_sphere(vec3(0,0,-1), 0.5, r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}


int main(int, char **)
{
    std::clog << "WIDTH, HEIGHT: (" << WIDTH <<", " << HEIGHT << ")" << std::endl;
    std::cout << "P3\n"
              << WIDTH << ' ' << HEIGHT << "\n255\n";


    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * RATIO;
    auto camera_center = vec3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / WIDTH;
    auto pixel_delta_v = viewport_v / HEIGHT;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
              

    for (int j = 0; j < HEIGHT; j++)
    {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;

        for (int i = 0; i < WIDTH; i++)
        {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);

            rt::write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                           \n";
    return 0;
}
