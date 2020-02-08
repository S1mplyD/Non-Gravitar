#include "Player.h"
//Classe player
Player::Player(Texture *texture) { //Costruttore della classe player
    //La vita massima è data da 10 HP
    HPMAX= 10;
    //Attualmemte, gli HP correnti sono uguali a quelli massimi. Diminuiranno nel corso del gioco
    HP = HPMAX;
    //Settiamo la texture dell'UFO
    texture = texture;
    shape.setTexture(*texture);
    //Settiamo la dimensione e la posizione del player nella schermata di gioco
    shape.setScale(0.5f,0.5f);
    shape.setPosition(Vector2f(640.0f,30.f));
}
int Player::getHP(){ //Questa funzione serve a riportare gli HP correnti
    return HP;
}
int Player::getHPMAX(){ //Questa funzione serve a riportare gli HP massimi
    return HPMAX;
}
void Player::DannoSubito(){ //Questa funzione diminuisce gli HP del player
    HP--;
}
void Player::fuelUP(){ //Questa funzione ricarica di 50 punti il fuel. Se, con la ricarica, si va oltre i 3000 punti di fuel, li setta di nuovo a 3000
    fuel = fuel + 750;
    if (fuel >= 3000) fuel = 3000;
}
void Player::fuelUP2(){ //Questa funzione ricarica di 100 punti il fuel. Se, con la ricarica, si va oltre i 3000 punti di fuel, li setta di nuovo a 3000
    fuel = fuel + 1500;
    if (fuel >= 3000) fuel = 3000;
}
void Player::fuelDown(){ //Ogni volta che ci si muove, questa funzione "scarica" il fuel
    fuel-=1;
}
int Player::getFuel(){ //Questa funzione restituisce il fuel corrente
    return fuel;
}
int Player::getScore(){ //Restituisce lo score corrente
    return score;
}
void Player::ScoreUp1(){ //Incrementa lo score di 100 punti
    score += 100;
}
void Player::ScoreUp2(){ //Incrementa lo score di 150 punti
    score += 150;
}
void Player::HPUp(){ //Riporta la vita su quando si esce dal pianeta
    HP = 10;
}
void Player::ScoreUp3(){ //Incrementa i punti quando un pianeta è distrutto
    score += 200;
}
