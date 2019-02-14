//
// Created by Tyler nychka on 2019-02-02.
//
#include <fstream>
#include <src/geometry/Shapes/Sphere.h>
#include "display/PpmDisplayer.h"
#include "CONFIG.h"

int main() {
  Model model;
  Camera camera(s_fov, s_pixelWidth / s_pixelHeight, s_aperture);
  PpmDisplayer ppmDisplayer(model, camera);

  std::ofstream output;
  output.open("PrettyPictures.ppm", std::ios::trunc);
  ppmDisplayer.render(s_pixelWidth, s_pixelHeight, &output);
  output.close();
}
