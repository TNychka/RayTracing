//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_DIELECTRIC_H
#define RAYTRACING_DIELECTRIC_H

#include "Material.h"
class Dielectric : public Material {
private:
public:
    Dielectric(float ri);
    bool scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered) override;
private:
    float refId;
};

#endif //RAYTRACING_DIELECTRIC_H
