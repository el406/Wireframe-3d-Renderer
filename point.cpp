//
// Created by milky on 3/25/2024.
//

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
     float dX,dY,dZ;
     float eX = 100;
     float eY =100 ;
     float eZ= 10;
     //ac = actual coord - camera coord
     float acX = x - c.x;
     float acY = y - c.y;
     float acZ = z - c.z;
     //code yay
     dX = cosf(c.tby)*((sinf(c.tbz)*acY)+(cosf(c.tbz)*acX)) - (sinf(c.tby)*acZ);
     dY = sinf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))+cosf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
     dZ = cosf(c.tbx)*(cosf(c.tby)*acZ + sinf(c.tby)*(sinf(c.tbz)*acY+cosf(c.tbz)*acX))-sinf(c.tbx)*(cosf(c.tbz)*acY-sinf(c.tbz)*acX);
     float bX = eZ/dZ*dX + eX;
     float bY = eZ/dZ*dY + eY;
     return {bX,bY};
}
