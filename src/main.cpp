//
// Created by Tyler nychka on 2019-02-02.
//
#include <fstream>
#include "display/PpmDisplayer.h"

int main() {
   PpmDisplayer ppmDisplayer;
   std::ofstream output;
   output.open("PrettyPictures.ppm", std::ios::trunc);
   ppmDisplayer.toPpm(2000, 1000, &output);
   output.close();
}
