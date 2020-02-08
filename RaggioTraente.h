#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"

using namespace sf;

class RaggioTraente{ //Ogetto raggio traente
public:

    RaggioTraente(Player &player); //Il costruttore prende in input il player di cui si vuole disegnare il raggio traente
    sf::ConvexShape raggioTraente; //Forma raggio traente
    void draw(sf::RenderWindow &window); //Si disegna il raggio traente a schermo
};
