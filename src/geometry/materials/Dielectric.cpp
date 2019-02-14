//
// Created by Tyler nychka on 2019-02-14.
//

#include "Dielectric.h"


bool Dielectric::scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered)
{
    float reflectProb = 1;
    attenuation = RGB(1.0, 1.0, 1.0);
    float niOverNt;
    float cosine;
    Vector3D outwardNorm;
    Vector3D refracted;
    Vector3D reflected = reflect(rin.getDirection(), rec.normal);
    if (Vector3D::dot(rin.getDirection(), rec.normal) > 0) {
        outwardNorm = -rec.normal;
        niOverNt = refId;
        cosine = refId * Vector3D::dot(rin.getDirection(), rec.normal) / rin.getDirection().length();
    } else {
        outwardNorm = rec.normal;
        niOverNt = 1.0 / refId;
        cosine = -Vector3D::dot(rin.getDirection(), rec.normal) / rin.getDirection().length();
    }

    if (refract(rin.getDirection(), outwardNorm, niOverNt, refracted)) {
        reflectProb = schlick(cosine, refId);
    }

    if (drand48() < reflectProb) {
        scattered = Ray(rec.p, reflected);
    } else {
        scattered = Ray(rec.p, refracted);
    }
    return true;
}

Dielectric::Dielectric(float ri) : refId{ri}
{

}
