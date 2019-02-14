//
// Created by Tyler nychka on 2019-02-14.
//

#include "Material.h"
Vector3D Material::reflect(const Vector3D &v, const Vector3D &n) {
  return v - 2 * Vector3D::dot(v, n) * n;
}

bool Material::refract(const Vector3D &v, const Vector3D &n, float niOverNt, Vector3D &refracted) {
  Vector3D uv = Vector3D::makeUnitVector(v);
  float dt = Vector3D::dot(uv, n);
  float discriminant = 1.0 - niOverNt * niOverNt * (1 - dt * dt);
  if (discriminant > 0) {
    refracted = niOverNt * (uv - n * dt) - n * sqrt(discriminant);
    return true;
  }
  return false;
}

float Material::schlick(float cosine, float refId) {
  float r0 = (1 - refId) / (1 + refId);
  r0 = r0 * r0;
  return r0 + (1 - r0) * pow((1 - cosine), 5);
}

Material::Material(std::unique_ptr<RGB> &&albedo) : albedo{std::move(albedo)} {
}
