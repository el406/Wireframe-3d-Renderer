#ifndef BALLRENDERPROJECT_VECTORMATH_H
#define BALLRENDERPROJECT_VECTORMATH_H
#include <SFML/Graphics.hpp>
#include "point.h"

point crossProduct(point i, point j)
{
    point ret{};
    ret.plotPoints(((i.y*j.z)-(i.z*j.y)),((i.z*j.x)-(i.x*j.z)),((i.x*j.y)-(i.y*j.x)));
    return ret;
}

point vectorAddition(point i, point j)
{
    point k{};
    k.plotPoints(i.x+j.x,i.y+j.y,i.z+j.z);
    return k;
}

#endif
