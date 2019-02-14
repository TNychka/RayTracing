//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_COLLIDABLE_H
#define RAYTRACING_COLLIDABLE_H

#include <src/geometry/primitives/Vector3D.h>
#include <src/geometry/primitives/Ray.h>
#include <src/geometry/materials/Material.h>
#include <src/geometry/primitives/HitRecord.h>

class Collidable {
 public:
  Collidable() = delete;
  Collidable(std::unique_ptr<Material>&& material);
  virtual ~Collidable() = 0;
  virtual bool collision(const Ray &r, float t_min, float t_max, HitRecord &rec) const = 0;
  static Vector3D randomInUnitSphere();
  virtual Material &getMaterial() const;
 private:
  std::unique_ptr<Material> material;
};

#endif //RAYTRACING_COLLIDABLE_H
