//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_METALS_H
#define RAYTRACING_METALS_H

#include <src/geometry/primitives/Vector3D.h>
#include <src/geometry/Shapes/Collidable.h>
#include <src/geometry/primitives/RGB.h>
#include "Material.h"

class Metals : public Material {
private:
public:
    Metals(std::unique_ptr<RGB>&& albeto, float f);
    virtual ~Metals() = default;
    virtual bool scatter(const Ray& rin, const HitRecord& rec, RGB& attenuation, Ray& scattered) override;
private:
    float fuzz;
};

#endif //RAYTRACING_METALS_H
