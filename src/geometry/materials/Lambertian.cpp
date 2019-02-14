//
// Created by Tyler nychka on 2019-02-14.
//

#include <src/geometry/Shapes/Collidable.h>
#include "Lambertian.h"
Lambertian::Lambertian(std::unique_ptr<RGB>&&albedo) : Material(std::move(albedo))  {}

bool Lambertian::scatter(const Ray &rin, const HitRecord &rec, RGB &attenuation, Ray &scattered) {
  Vector3D target = rec.p + rec.normal + Collidable::randomInUnitSphere();
  scattered = Ray(rec.p, target - rec.p);
  attenuation = *albedo;
  return true;
}
