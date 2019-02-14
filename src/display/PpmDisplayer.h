//
// Created by Tyler nychka on 2019-02-02.
//

#ifndef RAYTRACING_PPMDISPLAYER_H
#define RAYTRACING_PPMDISPLAYER_H

#include <src/geometry/Ray.h>
#include <src/geometry/RGB.h>
#include "Model.h"
#include "Camera.h"

class PpmDisplayer {
public:
    PpmDisplayer(Model& model, Camera& camera);
    void render(int nx, int ny, std::ofstream* outputFile);
private:
    RGB colour(const Ray & r, int depth) const;
    Model model;
    Camera camera;
};

#endif //RAYTRACING_PPMDISPLAYER_H
