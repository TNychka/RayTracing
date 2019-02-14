//
// Created by Tyler nychka on 2019-02-02.
//

#ifndef RAYTRACING_PPMDISPLAYER_H
#define RAYTRACING_PPMDISPLAYER_H

#include <src/geometry/Ray.h>
#include <src/geometry/RGB.h>

class PpmDisplayer {
public:
    void toPpm(int nx, int ny, std::ofstream* outputFile);
private:
    RGB colour(const Ray & r) const;
};

#endif //RAYTRACING_PPMDISPLAYER_H
