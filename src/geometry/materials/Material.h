//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include <src/geometry/primitives/Vector3D.h>
#include <src/geometry/primitives/Ray.h>
#include <src/geometry/primitives/HitRecord.h>
#include <src/geometry/primitives/RGB.h>
class Material {
 protected:
  static bool refract(const Vector3D &v, const Vector3D &n, float niOverNt, Vector3D &refracted);
  static Vector3D reflect(const Vector3D &v, const Vector3D &n);
  static float schlick(float cosine, float refId);

 public:
  Material(std::unique_ptr<RGB>&& albedo);
  virtual ~Material() = default;
  virtual bool scatter(const Ray &rin, const HitRecord &rec, RGB &attenuation, Ray &scattered) = 0;
 protected:
  std::unique_ptr<RGB> albedo;
};

#endif //RAYTRACING_MATERIAL_H
