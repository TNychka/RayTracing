//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include <src/geometry/Vector3D.h>
#include <src/geometry/Ray.h>
class Camera {
public:
    Camera(float vfov, float aspect);
    Ray getRay(float u, float v);

private:
    Vector3D origin;
    Vector3D lowerLeft;
    Vector3D horizontal;
    Vector3D vertical;
};

#endif //RAYTRACING_CAMERA_H
