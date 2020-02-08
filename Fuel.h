#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

using namespace sf;

#define M_PI 3.14

class Fuel {
public:
    Sprite shape; //Sprite dei fuel  del primo tipo
    Fuel(Texture *texture); //Costruttore
void setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index); //Posiziona il fuel
private:
    int Val; //Quanto valore ricarica il fuel
};

class Fuel2{
public:
    Sprite shape; //Sprite dei fuel del secondo tipo
    Fuel2(Texture *texture); //Costruttore
void setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index); //Posiziona il fuel
private:
    int Val; //Quanto valore ricarica il fuel
};
