#include "Proiettili.h"
//Classe Bullet del player
Bullet::Bullet(sf::Vector2f size){ //Costruttore
        //Si setta la dimensione e il colore di ogni proiettile della nave
        bullet.setSize(size);
        bullet.setFillColor(Color::Yellow);
}
void Bullet::setPos(Vector2f newpos){ //Setta la posizione del proiettile ogni volta che si muove
    bullet.setPosition(newpos);
}
void Bullet::fuocod(){ //Muove il proiettile
        bullet.move(Vector2f(0.f,10.f));
        }
void Bullet::fuocou(){
        bullet.move(Vector2f(0.f, -10.f));
    }
void Bullet::fuocol(){
        bullet.move(Vector2f(-10.f, 0.f));
    }
void Bullet::fuocor(){
        bullet.move(Vector2f(10.f,0.f));
}

void Bullet::draw(RenderWindow &window){ //Disegna il proiettile sullo schermo
    window.draw(bullet);
}
int Bullet::getY(){ //Restituisce l' ordinata del proiettile, per le collisioni con i bunker
    return bullet.getPosition().y;
}
int Bullet::getX(){
    return bullet.getPosition().x;
}
//Classe Bullet del bunker del primo tipo (stesse di quelle prima, cambiano solo forma e colore)
EnemyBullet::EnemyBullet(float size){
        bullet.setRadius(size);
        bullet.setFillColor(Color::Yellow);
}
 void EnemyBullet::setPos(Vector2f newpos){
    bullet.setPosition(newpos);
}
 void EnemyBullet::fuoco(){
    bullet.move(Vector2f(5.f,-5.f));
}
void EnemyBullet::fuocol(){
    bullet.move(Vector2f(-5.f,-5.f));
}
void EnemyBullet::draw(RenderWindow &window){
    window.draw(bullet);
}
int EnemyBullet::getY(){
    return bullet.getPosition().y;
}
int EnemyBullet::getX(){
    return bullet.getPosition().x;
}
//Classe Bullet del bunker del secondo tipo (stesse di quelle prima, cambiano solo forma e colore)
EnemyBullet2::EnemyBullet2(float size){
        bullet.setRadius(size);
        bullet.setFillColor(Color::Yellow);
}
void EnemyBullet2::setPos(Vector2f newpos){
    bullet.setPosition(newpos);
}
void EnemyBullet2::fuoco(){
    bullet.move(Vector2f(5.f,-5.f));
}
void EnemyBullet2::fuocol(){
    bullet.move(Vector2f(-5.f,-5.f));
}
void EnemyBullet2::fuococ(){
    bullet.move(Vector2f(0.f,-5.f));
}

void EnemyBullet2::draw(RenderWindow &window){
    window.draw(bullet);
}
int EnemyBullet2::getY(){
    return bullet.getPosition().y;
}
int EnemyBullet2::getX(){
    return bullet.getPosition().x;
}
