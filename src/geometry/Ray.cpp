//
// Created by Tyler nychka on 2019-02-14.
//

#include "Ray.h"
Ray::Ray()
{
}

Ray::Ray(const Vector3D& start, const Vector3D& direction)
        :start{start}, direction{direction}
{
}

Vector3D Ray::getStart() const
{
    return start;
}

Vector3D Ray::getDirection() const
{
    return direction;
}

Vector3D Ray::pointAtDistance(float t) const
{
    return start+direction*t;
}
