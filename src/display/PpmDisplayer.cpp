//
// Created by Tyler nychka on 2019-02-02.
//

#include <src/CONFIG.h>
#include "PpmDisplayer.h"

PpmDisplayer::PpmDisplayer(Model &model, Camera &camera)
    : model{model}, camera{camera} {
}

void PpmDisplayer::render(int nx, int ny, std::ofstream *outputFile) {
  *outputFile << "P3\n" << nx << " " << ny << "\n255\n";
  for (int j = ny - 1; j >= 0; --j) {
    for (int i = 0; i < nx; i++) {
      RGB rgb(0, 0, 0);
      for (int s = 0; s < s_antiAliasing; ++s) {
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);
        Ray ray = camera.getRay(u, v);
        rgb += colour(ray, 0);
      }
      rgb /= float(s_antiAliasing);
      rgb = RGB(sqrt(rgb.getR()), sqrt(rgb.getG()), sqrt(rgb.getB()));
      *outputFile << rgb << "\n";
    }
  }
}

RGB PpmDisplayer::colour(const Ray &r, int depth) const {
  HitRecord hit;
  if (model.detectCollision(r, 0.001, MAXFLOAT, hit)) {
    Ray scattered;
    RGB attenuation;
    if (depth < s_depth && hit.collidable->getMaterial().scatter(r, hit, attenuation, scattered)) {
      return attenuation * colour(scattered, depth + 1);
    } else {
      return RGB(0, 0, 0);
    }
  } else {
    Vector3D unitDirection = Vector3D::makeUnitVector(r.getDirection());
    auto t = static_cast<float>(0.5 * (unitDirection.getY() + 1.0));
    return (1.0 - t) * RGB(1.0, 1.0, 1.0) + t * RGB(0.5, 0.7, 1.0);
  }
}