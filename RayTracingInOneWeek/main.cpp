#include <fstream>
#include <stdlib.h>
#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "hitable_list.h"
#include "camera.h"
#include "float.h"

using namespace std;

double drand48() {
  return ((double)(rand() / RAND_MAX));
}

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
  int ns = 100;
  ofs << "P3\n" << nx << " " << ny << "\n255\n";

  hitable* list[2];
  list[0] = new sphere(vec3(0, 0, -1), 0.5);
  list[1] = new sphere(vec3(0, -100.5f, -1), 100);
  // list[2] = new sphere(vec3(2, 0, -1.5), 1);
  hitable_list *world = new hitable_list(list,2);

  camera cam;
  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; ++i) {
      vec3 col(0, 0, 0);
      for (int s = 0; s < ns; ++s) {
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);
        ray r = cam.get_ray(u, v);
        col += color(r, world);
      }
      col /= float(ns);

      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);
      ofs << ir << " " << ig << " " << ib << "\n";
    }
  }

  ofs.close();

  return 0;
}