//
// Created by Tyler nychka on 2019-02-14.
//

#ifndef RAYTRACING_MODEL_H
#define RAYTRACING_MODEL_H

#include <src/geometry/Shapes/Collidable.h>
#include <vector>
class Model {
public:
    Model();
    ~Model();
    virtual bool detectCollision(const Ray& r, float tmin, float tmax, Collidable::HitRecord& hitRecord) const;
    std::vector<Collidable*>& getObjects();
private:
    std::vector<Collidable*> collidables;
};

#endif //RAYTRACING_MODEL_H
