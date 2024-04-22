


#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

struct Camera
{
    //fun note; tb stands for tait-bryan angles lol.
public:
    float tbx = 0;
    float tby = 0;
    float tbz = 0;
    float x = 100;
    float y = 0;
    float z = -100;
    void reset()
    {
        tbx = 0;
        tby = 0;
        tbz = 0;
        x = 100;
        y = 0;
        z = -100;
    }

};


class point {
public:
    float x;
    float y;
    float z;
    sf::Vector2f returnVector() const;
    sf::Vector2f returnProjectedVector(Camera c) const;
    void plotPoints(float cx, float cy, float cz);
};


class triangle
{
public:
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
        sf::VertexArray ret(sf::LineStrip,3);
        for (auto i = 0; i < 3; ++i)
        {
            ret[i] = points[i].returnProjectedVector(c);
        }
        return ret;
    }

    point points[4];
};



