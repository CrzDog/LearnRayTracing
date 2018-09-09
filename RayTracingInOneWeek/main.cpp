#include <fstream>
#include "vec3.h"
#include "ray.h"

using namespace std;

float hit_sphere(const vec3& center, float radius, const ray& r) {
  vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = 2.f * dot(oc, r.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    return -1.f;
  }
  else {
    return (-b - sqrt(discriminant)) / (2.f * a);
  }
}

vec3 color(const ray& r) {
  float t = hit_sphere(vec3(0, 0, -1), 0.5, r);

  if (t > 0.f) {
    vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1));
    return 0.5 * vec3(N[0] + 1, N[1] + 1, N[2] + 1);
  }
  vec3 unit_dir = unit_vector(r.direction());
  t = 0.5f * (unit_dir.y() + 1.f);
  return (1.f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
}

int main() {
  ofstream ofs;
  ofs.open("./out.ppm");
  int nx = 200;
  int ny = 100;
  ofs << "P3\n" << nx << " " << ny << "\n255\n";

  vec3 lower_left_corner(-2.f, -1.f, -1.f);
  vec3 horizontal(4.f, 0.f, 0.f);
  vec3 vertical(0.f, 2.f, 0.f);
  vec3 origin(0.f, 0.f, 0.f);

  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; ++i) {
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 col = color(r);
      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);
      ofs << ir << " " << ig << " " << ib << "\n";
    }
  }

  ofs.close();

  return 0;
}