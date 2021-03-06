#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
  float e[3];

public:
  vec3() {}
  vec3(float e0, float e1, float e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
  }

  inline float x() const {
    return e[0];
  }
  inline float y() const {
    return e[1];
  }
  inline float z() const {
    return e[2];
  }
  inline float r() const {
    return e[0];
  }
  inline float g() const {
    return e[1];
  }
  inline float b() const {
    return e[2];
  }

  inline const vec3& operator+() const {
    return *this;
  }
  inline vec3 operator-() const {
    return vec3(-e[0], -e[1], -e[2]);
  }
  inline float operator[](int i) const {
    return e[i];
  }
  inline float& operator[](int i) {
    return e[i];
  }

  inline vec3& operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }
  inline vec3& operator-=(const vec3& v) {
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
  }
  inline vec3& operator*=(const vec3& v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
  }
  inline vec3& operator/=(const vec3& v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
  }
  inline vec3& operator*=(float s) {
    e[0] *= s;
    e[1] *= s;
    e[2] *= s;
    return *this;
  }
  inline vec3& operator/=(float s) {
    e[0] /= s;
    e[1] /= s;
    e[2] /= s;
    return *this;
  }

  inline float length() const {
    return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
  }
  inline float squared_lengh() const {
    return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
  }
  inline void make_unit_vector() {
    float k = 1.f / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
  }
};

inline std::istream& operator>>(std::istream& is, vec3& t) {
  is >> t.e[0] >> t.e[1] >> t.e[2];
  return is;
}
inline std::ostream& operator<<(std::ostream& os, const vec3& t) {
  os << t.e[0] << " " << t.e[1] << " " << t.e[2];
  return os;
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
  return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline vec3 operator-(const vec3& v1, const vec3& v2) {
  return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}
inline vec3 operator*(const vec3& v1, const vec3& v2) {
  return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}
inline vec3 operator/(const vec3& v1, const vec3& v2) {
  return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}
inline vec3 operator*(const vec3& v, float s) {
  return vec3(v.e[0] * s, v.e[1] * s, v.e[2] * s);
}
inline vec3 operator*(float s, const vec3& v) {
  return vec3(v.e[0] * s, v.e[1] * s, v.e[2] * s);
}
inline vec3 operator/(const vec3& v, const float s) {
  return vec3(v.e[0] / s, v.e[1] / s, v.e[2] / s);
}

inline float dot(const vec3& v1, const vec3& v2) {
  return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}
inline vec3 cross(const vec3& v1, const vec3& v2) {
  return vec3(
    v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
    v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
    v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]
  );
}
inline vec3 unit_vector(const vec3& v) {
  return v / v.length();
}


#endif // !VEC3H