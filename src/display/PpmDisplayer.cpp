//
// Created by Tyler nychka on 2019-02-02.
//

#include "PpmDisplayer.h"
#include <fstream>

void PpmDisplayer::toPpm(int nx, int ny, std::ofstream* outputFile)
{
    *outputFile << "P3\n" << nx << " " << ny << "\n255\n";

    Vector3D lowerLeft(-2.0, -1.0, -1.0);
    Vector3D horizontal(4.0, 0.0, 0.0);
    Vector3D vertical(0.0, 2.0, 0.0);
    Vector3D origin(0.0, 0.0, 0.0);

    for (int j = ny-1; j>=0; --j) {
        for (int i = 0; i<nx; i++) {
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);

            Ray r(origin, lowerLeft + u * horizontal + v*vertical);
            RGB rgb = colour(r);
            *outputFile << rgb << "\n";
        }
    }
}

RGB PpmDisplayer::colour(const Ray& r) const {
    Vector3D unitDirection = Vector3D::makeUnitVector(r.getDirection());
    auto t = static_cast<float>(0.5 * (unitDirection.getY() + 1.0));
    return (1.0 - t) * RGB(1.0, 1.0, 1.0) + t * RGB(0.5, 0.7, 1.0);
}