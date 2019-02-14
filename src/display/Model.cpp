//
// Created by Tyler nychka on 2019-02-14.
//

#include "Model.h"
Model::Model()
{

}

Model::~Model() {
    for (Collidable* collidable : collidables) {
        delete collidable;
    }
}

bool Model::detectCollision(const Ray& r, float tmin, float tmax, Collidable::HitRecord& hitRecord) const
{
    Collidable::HitRecord hit;
    double closest = tmax;
    for (Collidable* collidable : collidables) {
        if (collidable->collision(r, tmin, closest, hit)) {
            closest = hit.t;
            hitRecord = hit;
        }
    }
    return closest < tmax;
}

std::vector<Collidable*>& Model::getObjects()
{
    return collidables;
}
