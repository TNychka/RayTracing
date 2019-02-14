//
// Created by Tyler nychka on 2019-02-14.
//

#include "RGB.h"

RGB::RGB() = default;

RGB::RGB(float r, float g, float b)
{
    rgb[RED] = r;
    rgb[GREEN] = g;
    rgb[BLUE] = b;
}


