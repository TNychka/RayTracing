//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_HITRECORD_H
#define RAYTRACING_HITRECORD_H


#include "Vector3D.h"
class Collidable;

struct HitRecord {
  float t;
  Vector3D p;
  Vector3D normal;
  const Collidable* collidable;
};

#endif //RAYTRACING_HITRECORD_H
