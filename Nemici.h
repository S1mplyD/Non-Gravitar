#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "Proiettili.h"
#include <cmath>

using namespace sf;

#define M_PI 3.14

class Bunker {
public:
    Sprite shape; //sprite del bunker a cui applico una texture
    Bunker(Texture *texture);
    std::vector<EnemyBullet> bullets;
    std::vector<EnemyBullet> bulletsl;
     //vettore utilizzato per i proiettili del bunker
    //funzione che mi ritorna gli HP
    int getHP();
    //funzione che mi ritorna gli HP massimi
    int getHPMAX();
    //funzione che riduce la vita quando viene subito del danno
    void DannoSubito();
    //funzione che setta la posizione del bunker
    void setpos(std::vector<ConvexShape> surface, int current_vertex_index);
    int isAlive();
private:
    int HP;
    int HPMAX;
};

class Bunker2 { //Non riporto, perchè quello è sopra, ed è circa lo stesso
public:
    Sprite shape;
    Bunker2(Texture *texture);
    std::vector<EnemyBullet2> bullets;
    std::vector<EnemyBullet2> bulletsl;
    std::vector<EnemyBullet2> bulletsc;
    int getHP();
    int getHPMAX();
    void DannoSubito();
    void setpos(std::vector<ConvexShape> surface, int current_vertex_index);
private:
    int HP;
    int HPMAX;
};
