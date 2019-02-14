//
// Created by Tyler nychka on 2019-02-14.
//

#include "Vector3D.h"

Vector3D::Vector3D() = default;

Vector3D::Vector3D(float x, float y, float z)
{
    values[X] = x;
    values[Y] = y;
    values[Z] = z;
}

Vector3D Vector3D::makeUnitVector(const Vector3D v)
{
    return v / v.length();
}