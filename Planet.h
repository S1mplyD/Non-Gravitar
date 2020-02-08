#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Nemici.h"
#include "Fuel.h"
#include "Engine.h"

class Planet{
public:
    sf::Sprite shape_of_planet; //Sprite pianeta, a cui viene assegnata la texture
    bool destroyed = false; //Booleano che indica se il pianeta è privo di bunker
    int y_punti_terreno[14]; //Ordinate dei punti del terreno
    int numero_bunker1; //Numero bunker dei due tipi, con i vettori
    int numero_bunker2;
    std::vector<Bunker> nemici1;
    std::vector<Bunker2> nemici2;
    int numero_fuel1; //Numero dfuel dei due tipi, con i vettori
    int numero_fuel2;
    std::vector<Fuel> carburante1;
    std::vector<Fuel2> carburante2;
    int pos_bunker1[4]; //Indici di posizionamento dei bunker e dei fuel
    int pos_bunker2[4];
    int pos_fuel1[4];
    int pos_fuel2[4];
    Planet(sf::Texture *texture); //Costruttore pianeta
    void entrata_in_atmosfera(sf::Texture *texture); //Cambio texture se il bool destroyed=true
};
