#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include "Player.h"
#include <vector>
#include "SystemGame.h"
#include <SFML/Graphics/Transform.hpp>


class DeathScene
{
    public:
    sf::RectangleShape death_scene; //Il rettangolo che fa da sfondo per il Game Over
    sf::Text death_text; //Il testo che dice di scegliere se tornare al menu o no
    DeathScene(sf::Font *font); //Costruttore, che assegna il font della scritta
    void DrawDeath(sf::RenderWindow &window); //Disegna la schermata di Game Over
    void HandleDeathScene(sf::RenderWindow &window); //La funzione che fa tornare al menu o fa ricominciare
    void GameOver(sf::RenderWindow &window, Player &player); //La funzione che contiene tutto

};
