//
// Created by Tyler nychka on 2019-02-14.
//

#include "Camera.h"

Camera::Camera(float vfov, float aspect)
{
    float theta = vfov*M_PI/180;
    float halfHeight = tan(theta/2);
    float halfWidth = aspect*halfHeight;
    lowerLeft = Vector3D(-halfWidth, -halfHeight, -1.0);
    horizontal = Vector3D(2*halfWidth, 0, 0);
    vertical = Vector3D(0, 2*halfHeight, 0);
    origin = Vector3D(0, 0, 0);
}

Ray Camera::getRay(float u, float v)
{
    return Ray(origin, lowerLeft+u*horizontal+v*vertical);
}