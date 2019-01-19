#include <iostream>
#include "ray.h"

// Sphere at origin; see notes for derivation of formula
bool hit_sphere(const vec3& center, float radius, const ray& r) {
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

// Linearly blends white and blue.
// t=1.0 is blue and t=0.0 is white
// and has a sphere
vec3 color(const ray& r) {
    if (hit_sphere(vec3(0,0,-1), 0.5, r)) {
        return vec3(1,0,0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(){
    int nx = 200;
    int ny = 100;

    // Boilerplate for PPM file
    std::cout << "P3" << std::endl;             // P3 means ASCII
    std::cout << nx << " " << ny << std::endl;  // cols, rows
    std::cout << "255" << std::endl;            // Max color

    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    for (int j = ny-1; j >= 0; j--){
        for (int i = 0; i < nx; i++){
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
}