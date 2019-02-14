//
// Created by Tyler nychka on 2019-02-14.
//

#include "Camera.h"
Camera::Camera(float vfov,
               float aspect,
               float aperture) {
  Vector3D lookFrom(3, 3, 3);
  Vector3D lookAt(0, 0, -1);
  Vector3D vup(0, 1, 0);

  focusDistance = (lookFrom - lookAt).length();
  lensRadius = aperture / 2;

  float theta = vfov * M_PI / 180;
  float halfHeight = tan(theta / 2);
  float halfWidth = aspect * halfHeight;

  origin = lookFrom;
  w = Vector3D::makeUnitVector(lookFrom - lookAt);
  u = Vector3D::makeUnitVector(Vector3D::cross(vup, w));
  v = Vector3D::cross(w, u);

  lowerLeft = origin - halfWidth * focusDistance * u - halfHeight * focusDistance * v - focusDistance * w;
  horizontal = 2 * halfWidth * focusDistance * u;
  vertical = 2 * halfHeight * focusDistance * v;
}

Camera::Camera(Vector3D &lookfrom,
               Vector3D &lookat,
               Vector3D &vup,
               float vfov,
               float aspect,
               float aperture,
               float focusDistance) : focusDistance{focusDistance} {
  lensRadius = aperture / 2;

  float theta = vfov * M_PI / 180;
  float halfHeight = tan(theta / 2);
  float halfWidth = aspect * halfHeight;

  origin = lookfrom;
  w = Vector3D::makeUnitVector(lookfrom - lookat);
  u = Vector3D::makeUnitVector(Vector3D::cross(vup, w));
  v = Vector3D::cross(w, u);

  lowerLeft = origin - halfWidth * focusDistance * u - halfHeight * focusDistance * v - focusDistance * w;
  horizontal = 2 * halfWidth * focusDistance * u;
  vertical = 2 * halfHeight * focusDistance * v;
}

Ray Camera::getRay(float s, float t) {
  Vector3D rd = lensRadius * randomUnitInDisk();
  Vector3D offset = u * rd.getX() + v * rd.getY();
  return Ray(origin + offset, lowerLeft + s * horizontal + t * vertical - origin - offset);
}