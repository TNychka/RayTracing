//
// Created by Tyler nychka on 2019-02-14.
//

#include "Sphere.h"

Sphere::Sphere(Vector3D vector3D, float radius, std::unique_ptr<Material> &&material)
    : Collidable{std::move(material)}, position{vector3D}, radius{radius} {}

bool Sphere::collision(const Ray &r, float t_min, float t_max, HitRecord &hitRecord) const {
  Vector3D oc = r.getStart() - position;
  float a = Vector3D::dot(r.getDirection(), r.getDirection());
  float b = Vector3D::dot(oc, r.getDirection());
  float c = Vector3D::dot(oc, oc) - radius * radius;
  float discriminant = b * b - a * c;
  if (discriminant > 0) {
    float hit1 = (-b - sqrt(b * b - a * c)) / a;
    if (hit1 < t_max && hit1 > t_min) {
      hitRecord.p = r.pointAtDistance(hit1);
      hitRecord.t = hit1;
      hitRecord.normal = (hitRecord.p - position) / radius;
      hitRecord.collidable = this;
      return true;
    }
    float hit2 = (-b + sqrt(b * b - a * c)) / a;
    if (hit2 < t_max && hit2 > t_min) {
      hitRecord.p = r.pointAtDistance(hit2);
      hitRecord.t = hit2;
      hitRecord.normal = (hitRecord.p - position) / radius;
      hitRecord.collidable = this;
      return true;
    }
  }
  return false;
}

