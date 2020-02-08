#include "RaggioTraente.h"
//Classe Raggio Traente
RaggioTraente::RaggioTraente(Player &player){ //Crea la forma del raggio traente
    raggioTraente.setPointCount(3);
    raggioTraente.setPoint(0, sf::Vector2f(player.shape.getPosition().x+25, player.shape.getPosition().y+45)); //Setta la posizione dei vertici
    raggioTraente.setPoint(1, sf::Vector2f(player.shape.getPosition().x+50, player.shape.getPosition().y+200));
    raggioTraente.setPoint(2, sf::Vector2f(player.shape.getPosition().x, player.shape.getPosition().y+200));
}

void RaggioTraente::draw(sf::RenderWindow &window){
    window.draw(raggioTraente); //Disegna a finestra il raggio traente
}

