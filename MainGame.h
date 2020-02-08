#ifndef MAINGAME_H
#define MAINGAME_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <cstdlib>
#include "Player.h"
#include <vector>
#include "Nemici.h"
#include "Fuel.h"
#include <SFML/Graphics/Transform.hpp>
#include "SystemGame.h"
#include "RaggioTraente.h"
#include "DeathScene.h"
#include "Engine.h"

class MainGame
{
    public:

        MainGame(Player &player, int y_punti_terreno[], int indici_bunker1[], int indici_bunker2[], int indici_fuel1[], int indici_fuel2[], int numero_bunker1, int numero_bunker2, int numero_fuel1, int numero_fuel2, std::vector<Bunker> &nemici1,
            std::vector<Bunker2> &nemici2, std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2, sf::RenderWindow &window); //Questa funzione gestisce il gioco all'interno del pianeta
        //Questa è la funzione che gestisce la schermata del mondo, con terreno e tutto
};

#endif // MAINGAME_H
