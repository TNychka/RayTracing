//
// Created by Tyler nychka on 2019-02-02.
//
#include <fstream>
#include <src/geometry/Shapes/Sphere.h>
#include "display/PpmDisplayer.h"

int main() {
   Model model;
   std::vector<Collidable*>& items = model.getObjects();

   items.emplace_back(new Sphere(Vector3D(0, 0, -1), 0.5));
   items.emplace_back(new Sphere(Vector3D(0, -100.5, -1), 100));

   PpmDisplayer ppmDisplayer(model);
   std::ofstream output;
   output.open("PrettyPictures.ppm", std::ios::trunc);
   ppmDisplayer.toPpm(2000, 1000, &output);
   output.close();
}
