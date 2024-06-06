#ifndef BALLRENDERPROJECT_POINT_CPP
#define BALLRENDERPROJECT_POINT_CPP
#include "point.h"
//returns a vector without transformations
sf::Vector2f point::returnVector() const {
    return {x,y};

}

void point::plotPoints(float cx, float cy, float cz) {
    x = cx;
    y = cy;
    z = cz;
}

//actual 3d equation stuff
sf::Vector2f point::returnProjectedVector(Camera c) const {
     point projected = rotationMatrix(c);
     float eX = 100;
     float eY =100;
     float eZ= 300;
     float bX = eZ/projected.z*projected.x + eX;
     float bY = eZ/projected.z*projected.y + eY;
     return {bX,bY};
}

bool point::oldTestProjectedVector(Camera c) const {
    float thresh = 9.5;
    float dX,dY,dZ;
    float eX = 100;
    float eY =100;
    float eZ= 300;
    //ac = actual coord - camera coord
    float acX = x - c.x;
    float acY = y - c.y;
    float acZ = z - c.z;
    //code yay
    dX = cosf(c.tby)*((sinf(c.tbz)*acY)+(cosf(c.tbz)*acX)) - (sinf(c.tby)*acZ);
    dY = sinf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))+cosf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
    dZ = cosf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))-sinf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
    return (dZ < thresh);

}

float point::dotProduct(point i, point j) {return ((i.x*j.x)+(i.y*j.y)+(i.z*j.z));}

point point::rotationMatrix(Camera c) const {
    float dX,dY,dZ;
    //ac = actual coord - camera coord
    float acX = x - c.x;
    float acY = y - c.y;
    float acZ = z - c.z;
    //code yay
    dX = cosf(c.tby)*((sinf(c.tbz)*acY)+(cosf(c.tbz)*acX)) - (sinf(c.tby)*acZ);
    dY = sinf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))+cosf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
    dZ = cosf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))-sinf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
    return point{dX,dY,dZ};

}

#endif