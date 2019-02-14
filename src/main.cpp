//
// Created by Tyler nychka on 2019-02-02.
//
#include <fstream>
#include <src/geometry/Shapes/Sphere.h>
#include <src/geometry/materials/Lambertian.h>
#include <src/geometry/materials/Metals.h>
#include <src/geometry/materials/Dielectric.h>
#include "display/PpmDisplayer.h"

int main() {
   Model model;
   Camera camera(90, 400/200);
   std::vector<Collidable*>& items = model.getObjects();

   RGB atten1(0.1, 0.2, 0.5);
   RGB atten2(0.8, 0.8, 0.0);
   RGB atten3(0.8, 0.6, 0.2);
   RGB atten4(0.8, 0.8, 0.8);
   Lambertian l1(atten1);
   Lambertian l2(atten2);
   Lambertian l3(atten3);
   Lambertian l4(atten4);
   Metals m1(atten1, 0.1);
   Metals m2(atten2, 1);
   Metals m3(atten3, 0.1);
   Metals m4(atten4, 0.3);
   Dielectric d1(1.5);
   Dielectric d2(0.5);

   items.emplace_back(new Sphere(Vector3D(0, 0, -1), 0.5, &l1));
   items.emplace_back(new Sphere(Vector3D(0, -100.5, -1), 100, &l2));
   items.emplace_back(new Sphere(Vector3D(1, 0, -1), 0.5, &m3));
   items.emplace_back(new Sphere(Vector3D(-1, 0, -1), 0.5, &d1));
   items.emplace_back(new Sphere(Vector3D(-1, 0, -1), -0.45, &d1));

   PpmDisplayer ppmDisplayer(model, camera);
   std::ofstream output;
   output.open("PrettyPictures.ppm", std::ios::trunc);
   ppmDisplayer.render(400, 200, &output);
   output.close();
}
