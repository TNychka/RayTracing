//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_LAMBERTIAN_H
#define RAYTRACING_LAMBERTIAN_H

#include <src/geometry/RGB.h>
#include "Material.h"

class Lambertian : public Material {
private:
    RGB albedo;
public:
    Lambertian(const RGB& a);
    virtual bool scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered);
};

#endif //RAYTRACING_LAMBERTIAN_H
