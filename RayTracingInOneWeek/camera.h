#ifndef CAMERAH
#define CAMERAH

#include "ray.h"

class camera {
public:
  vec3 origin;
  vec3 lower_left_corner;
  vec3 horizontal;
  vec3 vertical;
public:
  camera() {
    origin = vec3(0.f, 0.f, 0.f);
    lower_left_corner = vec3(-2.f, -1.f, -1.f);
    horizontal = vec3(4.f, 0.f, 0.f);
    vertical = vec3(0.f, 2.f, 0.f);
  }

  ray get_ray(float u, float v) {
    return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
  }
};

#endif
