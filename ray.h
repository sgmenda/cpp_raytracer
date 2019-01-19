// ray.h
// Implements the ray class.
// Ray: p(t) = A + t*B
// A: origin
// B: direction

#ifndef RAYH
#define RAYH

#include "vec3.h"

class ray {
    public:
    // Constructors
    ray() {}
    ray(const vec3& a, const vec3& b) { A=a; B=b; }

    vec3 origin() const { return A; }
    vec3 direction() const { return B; }
    vec3 point_at_parameter(float t) const { return A + t*B; }

    // Fields
    vec3 A;
    vec3 B;
};

#endif