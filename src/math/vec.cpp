
#include "vec.h"


using namespace rt;


// Default constructor initializes e to {0, 0, 0}
vec3::vec3() : e{0, 0, 0} {}

// Constructor initializes e with specific values
vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

// Get the x component of the vector
double vec3::x() const { return e[0]; }

// Get the y component of the vector
double vec3::y() const { return e[1]; }

// Get the z component of the vector
double vec3::z() const { return e[2]; }

// Unary minus operator for negating the vector
vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }

// Subscript operator to access vector components (const)
double vec3::operator[](int i) const { return e[i]; }

// Subscript operator to access vector components (non-const)
double& vec3::operator[](int i) { return e[i]; }

// Add another vector to this vector
vec3& vec3::operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

// Multiply this vector by a scalar
vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

double vec3::length() const {
    return std::sqrt(length_squared());
}

double vec3::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}




// Divide this vector by a scalar
vec3& vec3::operator/=(double t) {
    return *this *= 1.0 / t;
}
vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

vec3 operator*(const vec3& v, double t) {
    return t * v;
}

vec3 operator/(const vec3& v, double t) {
    return (1.0 / t) * v;
}

double rt::dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

vec3 rt::cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vec3 rt::unit_vector(const vec3& v) {
    return v / v.length();
}