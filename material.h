#ifndef MATERIAL_H_
#define MATERIAL_H_
#include "hittable.h"

struct ScatterResult {
  bool did;
  vec3 attenuation;
  Ray scattered;
};

class Material {
  public:
    virtual ScatterResult scatter(const Ray &ray, const HitResult &hit) const = 0;
};

class Lambertian : public Material {
  public:
    Lambertian(const vec3 &albedo) : albedo(albedo) {}

    virtual ScatterResult scatter(const Ray &ray, const HitResult &hit) const override {
      vec3 scatter_dir = hit.normal + random_unit_vector();

      if (scatter_dir.near_zero()) {
        scatter_dir = hit.normal;
      }

      return {true, albedo, Ray(hit.point, scatter_dir)};
    }

    vec3 albedo;
};
#endif