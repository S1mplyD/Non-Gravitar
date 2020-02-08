#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Proiettili.h"

using namespace sf;

class Player{
public:
    RectangleShape hpBar; //Forma della barra della vita
    Sprite shape; //Sprite del player
    Texture *texture; //Texture
    Player(Texture *texture); //Costruttore
    int getHP(); //Restituisce gli HP correnti
    int getHPMAX(); //Restituisce gli HP massimi
    void DannoSubito(); //Diminuisce gli HP correnti
    std::vector<Bullet> bulletsdown;    //Vettore dei proiettili del player
    std::vector<Bullet> bulletsup;
    std::vector<Bullet> bulletsleft;
    std::vector<Bullet> bulletsright;
    void fuelUP(); //Aumenta il fuel di 50
    void fuelUP2(); //Aumenta il fuel di 100
    void fuelDown(); //Diminuisce il fuel mentre ci si muove
    int getFuel(); //Restituisce il fuel corrente
    void HPzero(); //Setta gli HP a 0
    int getScore(); //Restituisce lo score corrente
    void ScoreUp1(); //Aumenta i punti di 100
    void ScoreUp2(); //Aumenta i punti di 150
    void ScoreUp3();
    void HPUp();
private:
    int HP; //HP correnti
    int HPMAX; //HP massimi
    int fuel = 3000; //Fuel
    int score = 0; //Score iniziali
};
