#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height); //Costruttore del menu
	~Menu();

	void draw(sf::RenderWindow &window); //Disegna i tasti del menu
	void MoveUp(); //Sposta il tasto selezionato in su, colorandolo di rosso
	void MoveDown(); //Sposta il tasto selezionato in giù, colorandolo di rosso
	int GetPressedItem() { return selectedItemIndex; } //Ritorna il corrente tasto selezionato

private:
	int selectedItemIndex; //Indice del corrente tasto
	sf::Font font; //Font del menu
	sf::Text menu[MAX_NUMBER_OF_ITEMS]; //Numero dei tasti

};
