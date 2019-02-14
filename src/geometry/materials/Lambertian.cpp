//
// Created by Tyler nychka on 2019-02-14.
//

#include "Lambertian.h"
Lambertian::Lambertian(const RGB& a) : albedo{a}
{
}

bool Lambertian::scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered)
{
    Vector3D target = rec.p + rec.normal + Collidable::randomInUnitSphere();
    scattered = Ray(rec.p, target-rec.p);
    attenuation = albedo;
    return true;
}
