#include <fstream>
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"

using namespace std;

vec3 color(const ray& r, hitable_list *world) {
  hit_record rec;
  if (world->hit(r, 0.f, FLT_MAX, rec)) {
    return 0.5f * vec3(rec.normal.x() + 1.f, rec.normal.y() + 1.f, rec.normal.z() + 1.f);
  } else {
    vec3 unit_dir = unit_vector(r.direction());
    float t = 0.5f * (unit_dir.y() + 1.f);
    return (1.f - t) * vec3(1.f, 1.f, 1.f) + t * vec3(0.5f, 0.7f, 1.f);
  }
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

  hitable* list[3];
  list[0] = new sphere(vec3(0, 0, -1), 0.5);
  list[1] = new sphere(vec3(0, -100.5f, -1), 100);
  list[2] = new sphere(vec3(2, 0, -1.5), 1);
  hitable_list *world = new hitable_list(list, 3);

  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; ++i) {
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 col = color(r, world);
      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);
      ofs << ir << " " << ig << " " << ib << "\n";
    }
  }

  ofs.close();

  return 0;
}