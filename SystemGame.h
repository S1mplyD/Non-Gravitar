#ifndef SYSTEMGAME_H
#define SYSTEMGAME_H

#include <iostream>
#include "DeathScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include "Player.h"
#include "Planet.h"
#include <vector>
#include "Nemici.h"
#include "Fuel.h"
#include <SFML/Graphics/Transform.hpp>
#include "RaggioTraente.h"
#include "MainGame.h"

class Systems{
public:
    std::vector<Planet> astri; //Questo è il vettore dei pianeti
    int numero_astri; //Numero di pianeti nel vettore
    std::vector<int> x_astro; //Ascissa di posizione del pianeta
    std::vector<int> y_astro; //Ordinata di posizione del pianeta

    Systems(sf::Texture *planet); //Genera un sistema, prendendo in input la texture, sempre uguale, pe i pianeti
};

class SystemGame{
public:
    std::vector<Systems> vettore_sistemi; //Vettore di sistemi solari
    int it = 0; //Iteratore del vettore di sistemi
    SystemGame(); //Crea finestra e player, e richiama la funzione di gestione di sistemi
    int AfterSystemGame(int &it, Player &player, sf::RenderWindow &window); //Gestisce lo spostamento tra sistemi
};

#endif // SYSTEMGAME_H
