//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include "Vector3D.h"
class Ray {
public:
    Ray();
    Ray(const Vector3D& start, const Vector3D& direction);
    Vector3D getStart() const;
    Vector3D getDirection() const;
    Vector3D pointAtDistance(float t) const;
private:
    Vector3D start;
    Vector3D direction;
};

#endif //RAYTRACING_RAY_H
