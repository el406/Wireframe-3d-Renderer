#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
struct Camera
{
    //fun note; tb stands for tait-bryan angles lol
public:
    float tbx = 0;
    float tby = 0;
    float tbz = 0;
    float x = 120;
    float y = 190;
    float z = -100;
    float polarX = 0;
    float polarY = 0;
    float r = 250;


    void reset()
    {
        tbx = 0;
        tby = 0;
        tbz = 0;
        x = 120;
        y = 190;
        z = -100;



    }
    void translateToCartX()
    {

        tby = polarX;
        z = (r * (cosf(polarX)))+150;
        x = (r * (sinf(polarX))) +150;


    }
    //ide like to make this better somehow.
    void translateToCartY()
    {
        tbx = -polarY;
        y=(250*sinf(polarY))+190;
        r = (250*cosf(polarY));
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
        sf::VertexArray ret(sf::LineStrip,4);
        for (auto i = 0; i < 3; ++i)
        {
            ret[i] = points[i].returnProjectedVector(c);
        }
        ret[3] = points[0].returnProjectedVector(c);
        return ret;
    }

    point points[3];
};



