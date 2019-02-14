//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include <src/geometry/Vector3D.h>
#include <src/geometry/Ray.h>
#include <src/geometry/RGB.h>
#include <src/geometry/Shapes/Collidable.h>
class Material {
protected:
    bool refract(const Vector3D& v, const Vector3D& n, float niOverNt, Vector3D& refracted);
    Vector3D reflect(const Vector3D& v, const Vector3D& n);
    float schlick(float cosine, float refId);
public:
    virtual bool scatter(const Ray& rin, const Collidable::HitRecord& rec, RGB& attenuation, Ray& scattered) = 0;
};

#endif //RAYTRACING_MATERIAL_H
