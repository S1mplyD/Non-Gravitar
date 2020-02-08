#include "MainMenu.h"
//Classe menu
Menu::Menu(float width, float height) //Costruttore
{
	if (!font.loadFromFile("Font/04B_03__.ttf"))
	{
		// handle error
	}
    //Posiziona, colora e setta il font dei tasti del menu
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Yellow);
	menu[0].setString("PLAY");
	menu[0].setPosition(sf::Vector2f(((width / 2)-20), height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("TUTORIAL");
	menu[1].setPosition(sf::Vector2f(((width / 2)-54), height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setPosition(sf::Vector2f(((width / 2)-20), height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0; //Indica quale è il tasto selezionato correntemente
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) //Disegna i tasti del menu
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) //Disegna i tasti uno per uno
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() //Muove il tasto selezionato nel menu in su, colorandolo in giallo, cambiando l'iteratore
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown() //Muove il tasto selezionato nel menu in giù, colorandolo in giallo, cambiando l'iteratore
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}
