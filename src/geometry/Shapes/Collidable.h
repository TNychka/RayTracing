//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_COLLIDABLE_H
#define RAYTRACING_COLLIDABLE_H

#include <src/geometry/Vector3D.h>
#include <src/geometry/Ray.h>
class Collidable {
public:
    struct HitRecord {
      float t;
      Vector3D p;
      Vector3D normal;
    };

    virtual ~Collidable() = 0;
    virtual bool collision(const Ray& r, float t_min, float t_max, HitRecord& rec) const = 0;
};

#endif //RAYTRACING_COLLIDABLE_H
