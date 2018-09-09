#ifndef SPHEREH
#define SPHEREH

#include "hitable.h"

class sphere : public hitable {
public:
  vec3 center;
  float radius;
public:
  sphere() {}
  sphere(const vec3& cen, float r) :
    center(cen),
    radius(r) {

  }
  
  virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
};

bool sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec) const {
  vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = 2.f * dot(oc, r.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b * b - 4 * a * c;
  if (discriminant >= 0) {
    float temp = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    if (temp > tmin && temp < tmax) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - center) / radius;
      return true;
    }
    temp = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    if (temp > tmin && temp < tmax) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - center) / radius;
      return true;
    }
  }
  
  return false;
}

#endif
