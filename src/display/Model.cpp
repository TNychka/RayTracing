//
// Created by Tyler nychka on 2019-02-14.
//

#include <src/geometry/primitives/RGB.h>
#include <src/geometry/materials/Lambertian.h>
#include <src/geometry/materials/Metals.h>
#include <src/geometry/Shapes/Sphere.h>
#include <src/geometry/materials/Dielectric.h>
#include "Model.h"

Model::Model() {
  collidables.reserve(1000);
  collidables.emplace_back(new Sphere(Vector3D(0, -1000, 0),
                                      1000,
                                      std::make_unique<Lambertian>(std::make_unique<RGB>(0.5, 0.5, 0.5))));

  for (int a = -11; a < 11; ++a) {
    for (int b = -11; b < 11; ++b) {
      float chooseMaterial = drand48();
      Vector3D center(a + 0.9 * drand48(), 0.2, b + 0.9 * drand48());
      if ((center - Vector3D(4, 0.2, 0)).length() > 0.9) {
        if (chooseMaterial < 0.6) {
          collidables.emplace_back(new Sphere(center,
                                              0.2,
                                              std::make_unique<Lambertian>(std::make_unique<RGB>(drand48() * drand48(),
                                                                                                 drand48() * drand48(),
                                                                                                 drand48() * drand48()))
          ));
        } else if (chooseMaterial < 0.9) {
          collidables.emplace_back(new Sphere(center,
                                              0.2,
                                              std::make_unique<Metals>(std::make_unique<RGB>(drand48() * drand48(),
                                                                                             drand48() * drand48(),
                                                                                             drand48() * drand48()),
                                                                       0.5 * drand48()
                                              )));
        } else {
          collidables.emplace_back(new Sphere(center,
                                              0.2,
                                              std::make_unique<Dielectric>(1.5 * drand48())));
        }
      }
    }
  }
  collidables.emplace_back(new Sphere(Vector3D(0, 1, 0),
                                      1,
                                      std::make_unique<Dielectric>(1.5)));
  collidables.emplace_back(new Sphere(Vector3D(-4, 1, 0),
                                      1,
                                      std::make_unique<Lambertian>(std::make_unique<RGB>(0.4, 0.2, 0.1))));
  collidables.emplace_back(new Sphere(Vector3D(4, 1, 0),
                                      1,
                                      std::make_unique<Metals>(std::make_unique<RGB>(0.7, 0.6, 0.5), 0.0)));
}

Model::~Model() {
  // for (Collidable *collidable : collidables) {
  //   delete collidable;
  // }
}

bool Model::detectCollision(const Ray &r, float tmin, float tmax, HitRecord &hitRecord) const {
  HitRecord hit;
  double closest = tmax;
  for (Collidable *collidable : collidables) {
    if (collidable->collision(r, tmin, closest, hit)) {
      closest = hit.t;
      hitRecord = hit;
    }
  }
  return closest < tmax;
}

std::vector<Collidable *> &Model::getObjects() {
  return collidables;
}
