//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_METALS_H
#define RAYTRACING_METALS_H

#include <src/geometry/Vector3D.h>
#include <src/geometry/Shapes/Collidable.h>
#include <src/geometry/RGB.h>
#include "Material.h"

class Metals : public Material {
private:
public:
    Metals(const RGB& albedo, float f);
    virtual bool scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered) override;
private:
    RGB albedo;
    float fuzz;
};

#endif //RAYTRACING_METALS_H
