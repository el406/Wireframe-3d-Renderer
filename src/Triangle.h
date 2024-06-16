#include "point.h"
#include "vectorMath.h"
#ifndef BALLRENDERPROJECT_TRIANGLE_H
#define BALLRENDERPROJECT_TRIANGLE_H

class triangle
{
public:
    point points[3];
    triangle(point p1,point p2, point p3)
    {
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
    }
    sf::VertexArray makeArray()
    {
        sf::VertexArray ret(sf::LineStrip,3);
        for (auto i = 0; i < 3; ++i)
        {
            ret[i] = points[i].returnVector();
        }
        return ret;
    }

    sf::VertexArray makeProjectedArray(Camera c)
    {
        sf::VertexArray ret(sf::LineStrip,4);
        for (auto i = 0; i < 3; ++i)
        {
            ret[i] = points[i].returnProjectedVector(c);
        }
        ret[3] = points[0].returnProjectedVector(c);
        return ret;
    }

    sf::VertexArray createNormals(Camera c)
    {
        sf::VertexArray ret(sf::LineStrip,2);
        point origin = points[1];
        origin.x = -origin.x;
        origin.y = -origin.y;
        origin.z = -origin.z;
        point newPoints[3];
        newPoints[0] = vectorAddition(points[0],origin);
        newPoints[1].plotPoints(0,0,0);
        newPoints[2] = vectorAddition(points[2],origin);
        point final{};
        final = crossProduct(newPoints[0], newPoints[2]);
        final = vectorAddition(final,points[1]);
        ret[0] = points[1].returnProjectedVector(c);
        ret[1] = final.returnProjectedVector(c);
        return ret;


    }

    bool testNormals(Camera c)
    {

        point origin = points[1];
        origin.x = -origin.x;
        origin.y = -origin.y;
        origin.z = -origin.z;
        point newPoints[3];
        newPoints[0] = vectorAddition(points[0],origin);
        newPoints[1].plotPoints(0,0,0);
        newPoints[2] = vectorAddition(points[2],origin);
        point final{};
        final = crossProduct(newPoints[0], newPoints[2]);
        point subFinal = vectorAddition(final,points[1]);
        return subFinal.oldTestProjectedVector(c);


    }

    bool betterTestsNormals(Camera c)
    {
        point origin = points[1];
        point ac = vectorAddition(origin, {-c.x,-c.y,-c.z});
        origin.x = -origin.x;
        origin.y = -origin.y;
        origin.z = -origin.z;
        point newPoints[3];
        newPoints[0] = vectorAddition(points[0],origin);
        newPoints[1].plotPoints(0,0,0);
        newPoints[2] = vectorAddition(points[2],origin);
        point normals{};
        normals = crossProduct(newPoints[0], newPoints[2]);
        if (getAngle(normals,ac) <= 90)
        {
            return true;
        }
        return false;
    }


};


#endif //BALLRENDERPROJECT_TRIANGLE_H
