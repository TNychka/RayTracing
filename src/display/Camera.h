//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include <src/geometry/primitives/Vector3D.h>
#include <src/geometry/primitives/Ray.h>
class Camera {
 private:
  Vector3D randomUnitInDisk() {
    Vector3D p;
    Vector3D diskCenter(1, 1, 0);
    do { // TODO
      p = 2.0 * Vector3D(drand48(), drand48(), 0) - diskCenter;
    } while (Vector3D::dot(p, p) >= 1);
    return p;
  }

 public:
  Camera(float vfov,
         float aspect,
         float aperture);

  Camera(Vector3D &lookfrom,
         Vector3D &lookat,
         Vector3D &vup,
         float vfov,
         float aspect,
         float aperture,
         float focusDistance);

  Ray getRay(float s, float t);

 private:
  Vector3D origin;
  Vector3D lowerLeft;
  Vector3D horizontal;
  Vector3D vertical;

  float lensRadius;
  float focusDistance;

  Vector3D u, v, w;
};

#endif //RAYTRACING_CAMERA_H
