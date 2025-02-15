#if !defined(RTWEEKEND_VEC_H)
#define RTWEEKEND_VEC_H

#include <math.h>

namespace rt
{

    class vec3
    {
    public:
        double e[3];

        vec3();
        vec3(double e0, double e1, double e2);

        double x() const;
        double y() const;
        double z() const;

        vec3 operator-() const;
        double operator[](int i) const;
        double &operator[](int i);

        vec3 &operator+=(const vec3 &v);
        vec3 &operator*=(double t);
        vec3 &operator/=(double t);

        double length() const;
        double length_squared() const;
    };

    double dot(const vec3 &u, const vec3 &v);
    vec3 cross(const vec3 &u, const vec3 &v);
    vec3 unit_vector(const vec3 &v);
}

rt::vec3 operator+(const rt::vec3 &u, const rt::vec3 &v);
rt::vec3 operator-(const rt::vec3 &u, const rt::vec3 &v);
rt::vec3 operator*(const rt::vec3 &u, const rt::vec3 &v);
rt::vec3 operator*(double t, const rt::vec3 &v);
rt::vec3 operator*(const rt::vec3 &v, double t);
rt::vec3 operator/(const rt::vec3 &v, double t);

#endif // RTWEEKEND_VEC_H