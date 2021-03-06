//
// Created by Tyler nychka on 2019-02-14.
//

#include "Metals.h"

Metals::Metals(std::unique_ptr<RGB> &&albedo, float f) : Material(std::move(albedo)) {
  fuzz = f < 1 ? f : 1;
}

bool Metals::scatter(const Ray &rin, const HitRecord &rec, RGB &attenuation, Ray &scattered) {
  Vector3D reflected = reflect(Vector3D::makeUnitVector(rin.getDirection()), rec.normal);
  scattered = Ray(rec.p, reflected + fuzz * Collidable::randomInUnitSphere());
  attenuation = *albedo;
  return (Vector3D::dot(scattered.getDirection(), rec.normal) > 0);
}
