//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Collidable.h"
class Sphere : public Collidable {
public:
    Sphere(Vector3D vector3D, float radius, Material* material);
    virtual bool collision(const Ray& r, float t_min, float t_max, HitRecord& hitRecord) const override;
private:
    float radius;
    Vector3D position;
};

#endif //RAYTRACING_SPHERE_H
