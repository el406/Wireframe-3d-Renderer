#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <iostream>
#include "point.h"


sf::VertexArray createLinkLine(point p1, point p2,Camera c)
{
    sf::VertexArray fin(sf::LineStrip,2);
    fin[0] = p1.returnProjectedVector(c);
    fin[1] = p2.returnProjectedVector(c);
    return fin;
}



sf::RenderWindow window(sf::VideoMode(300, 300), "3d render babyyyyy");


int main()
{
    point p1{},p2{},p3{},p4{},p5{},p6{},p7{},p8{};
    point axis1{}, axis2{};
    p1.plotPoints(100,100,100);
    p2.plotPoints(100,200,100);
    p3.plotPoints(200,200,100);
    p4.plotPoints(200,100,100);
    p5.plotPoints(100,100,200);
    p6.plotPoints(100,200,200);
    p7.plotPoints(200,200,200);
    p8.plotPoints(200,100,200);
    axis1.plotPoints(100,150,150);
    axis2.plotPoints(200,150,150);



    Camera core;
    std::vector<triangle> triangles;
    triangles.emplace_back(p1,p2,p3);
    triangles.emplace_back(p1,p4,p3);
    triangles.emplace_back(p5,p6,p7);
    triangles.emplace_back(p5,p8,p7);

    //TODO: Fix the goofy linkline function that you use bc you are a lazy bum
    //triangles.emplace_back(p1,p5,p6);
    //triangles.emplace_back(p5,p6,p2);
    //triangles.emplace_back(p3,p7,p8);



    while (window.isOpen())
    {
        sf::Event event{};
        //controls
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) core.y+=-.5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) core.y+=.5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) core.tbx += .001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) core.tbx += -.001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) core.reset();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            std::cout << core.x << "\n" << core.y << "\n" << core.z << "\n";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) core.polarX+=0.001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) core.polarX+=-0.001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) core.polarY += 0.001;


        core.translateToCartX();
        core.translateToCartY();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        //rendering part
        for (auto&i : triangles)
        {
            window.draw(i.makeProjectedArray(core));


        }
        window.draw(createLinkLine(p1,p5,core));
        window.draw(createLinkLine(p2,p6,core));
        window.draw(createLinkLine(p3,p7,core));
        window.draw(createLinkLine(p4,p8,core));

        //EXTRAS STUFF HERE

        //deprecated controls (Bring back if needed)
        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) core.tby+= -.001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) core.tby += .001;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) core.x+=-.5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) core.x+=.5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))core.z+=.5;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) core.z+=-.5;*/


        //draws y axis for rotation ref
        window.draw(createLinkLine(axis1,axis2,core));






        window.display();
    }

    return 0;
}




