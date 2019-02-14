//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_COLLIDABLE_H
#define RAYTRACING_COLLIDABLE_H

#include <src/geometry/Vector3D.h>
#include <src/geometry/Ray.h>


class Material;

class Collidable {
public:
    struct HitRecord {
      float t;
      Vector3D p;
      Vector3D normal;
      const Collidable* collidable;
    };

    Collidable() = delete;
    Collidable(Material* material);
    virtual ~Collidable() = 0;
    virtual bool collision(const Ray& r, float t_min, float t_max, HitRecord& rec) const = 0;
    static Vector3D randomInUnitSphere();
    virtual Material* getMaterial() const;
private:
    Material* material;
};

#endif //RAYTRACING_COLLIDABLE_H
