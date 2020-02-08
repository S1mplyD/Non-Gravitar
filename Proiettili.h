#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

using namespace sf;

class Bullet{ //Classe dei bullet del player
public:
    RectangleShape bullet; //Forma
    Bullet(sf::Vector2f size); //Costruttore
    void setPos(Vector2f newpos); //Posizione proiettili
    void fuocod();
    void fuocou();
    void fuocol();
    void fuocor();
    void draw(RenderWindow &window); //Disegna i proiettili
    int getY(); //Trova l'ordinata dei proiettili
    int getX();
};

class EnemyBullet{ //Classe dei bullet del primo bunker (non riporto le descrizioni di sopra)
public:
    CircleShape bullet;
    EnemyBullet(float size);
    void setPos(Vector2f newpos);
    void fuoco();
    void fuocol();
    void draw(RenderWindow &window);
    int getY();
    int getX();
};

class EnemyBullet2{ //Classe dei bullet del secondo bunker (non riporto le descrizioni di sopra)
public:
    CircleShape bullet;
    EnemyBullet2(float size);
    void setPos(Vector2f newpos);
    void fuoco();
    void fuocol();
    void fuococ();
    void draw(RenderWindow &window);
    int getY();
    int getX();
};
