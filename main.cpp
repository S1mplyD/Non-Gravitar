#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "MainGame.h"
#include "SystemGame.h"
#include "MainMenu.h"
#include "Tutorial.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(436, 450), "NON-GRAVITAR"); //Imposta dimensione finestra
    //Carico la texture dello sfondo
	sf::Texture texture;
    if (!texture.loadFromFile("Texture/Menu (2).png"))
        {
            // error...
        }
    sf::Sprite background; //Lo sfondo è uno sprite
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, 436, 450)); //Si assegna la texture allo sfondo

	Menu menu(window.getSize().x, window.getSize().y); //Questo è il costruttore del menu. Serve per gestire tasti e funzioni
    //Carico l'audio del menu
    //Si creano i buffer dell'audio, da dare come oggetto di input a un costruttore
	sf::SoundBuffer buffer_01;

	sf::SoundBuffer buffer_02;

    if (!buffer_01.loadFromFile("Suoni/Menu_Button_Sound.wav"))
        return -1;

    if (!buffer_02.loadFromFile("Suoni/selection_sound.wav"))
        return -1;
    //Creo tre oggetti audio, per ogni tipo di audio
    sf::Sound sound_up;
    sf::Sound sound_down;
    sf::Sound sound_select;
    //Gestisco la finestra del menu. Molto del codice di seguito è standard per la gestione di finestre in SFML
    //AVVERTENZA: negli switch sono necessari i break. Non rimuoverli
	while (window.isOpen())
	{
		sf::Event event;//Si crea un oggetto di tipo Event. Serve a gestire la pressione di tasti da tastiera

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased: //Se si preme un tasto
				switch (event.key.code)
				{
				case sf::Keyboard::Up: //Ci si sposta nel menu in su, fa anche partire l'audio
					menu.MoveUp();
					sound_up.setBuffer(buffer_01);
					sound_up.play();
					break;

				case sf::Keyboard::Down: //Ci si sposta nel menu in giù, fa anche partire l'audio
					menu.MoveDown();
					sound_down.setBuffer(buffer_01);
					sound_down.play();
					break;

				case sf::Keyboard::Return: //Gestisce il cliccare dei tasti del menu, con anche l'audio
					switch (menu.GetPressedItem())
					{
					case 0: //Si apre il gioco
					    sound_select.setBuffer(buffer_02); //Audio di selezione del menu
					    sound_select.play();
					    SystemGame(); //Viene richiamata la funzione di gioco
						break;
                    case 1: //Si apre il tutorial
					    sound_select.setBuffer(buffer_02);
					    sound_select.play();
					    Tutorial(); //Funzione che apre la finestra del tutorial
						break;
					case 2:
						window.close(); //Si chiude il menu e il gioco
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
//Viene disegnato tutto
		window.clear();

		window.draw(background);

		menu.draw(window);

		window.display();
	}
}
