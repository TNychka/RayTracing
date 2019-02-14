//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_LAMBERTIAN_H
#define RAYTRACING_LAMBERTIAN_H

#include <src/geometry/primitives/RGB.h>
#include "Material.h"

class Lambertian : public Material {
 public:
  Lambertian(std::unique_ptr<RGB> &&a);
  virtual ~Lambertian() = default;
  virtual bool scatter(const Ray &rin, const HitRecord &rec, RGB &attenuation, Ray &scattered) override;
};

#endif //RAYTRACING_LAMBERTIAN_H
