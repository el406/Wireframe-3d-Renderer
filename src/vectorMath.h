#ifndef BALLRENDERPROJECT_VECTORMATH_H
#define BALLRENDERPROJECT_VECTORMATH_H
#include <SFML/Graphics.hpp>
#include "point.h"
#include <cmath>
#include <iostream>
float dotProduct(point i, point j) {return ((i.x*j.x)+(i.y*j.y)+(i.z*j.z));}

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


float getAngle(point i, point j)
{
   float final = dotProduct(i,j);
   final = final/(i.magnitude() * j.magnitude());
   final = acosf(final);
   final = final * (180/3.14);
   return final;
}
#endif
