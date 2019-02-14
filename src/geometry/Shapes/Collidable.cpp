//
// Created by Tyler nychka on 2019-02-14.
//

#include "Collidable.h"

Collidable::~Collidable() = default;

Material* Collidable::getMaterial() const
{
    return material;
}

Collidable::Collidable(Material* material) : material{material} {

}

Vector3D Collidable::randomInUnitSphere()
{
    Vector3D p;
    Vector3D unit(1,1,1);
    do {
        p = 2.0 * Vector3D(drand48(), drand48(), drand48()) - unit;
    } while (p.squaredLength() >= 1.0);
    return p;
}
