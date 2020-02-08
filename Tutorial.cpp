#include "Tutorial.h"

Tutorial::Tutorial(){
    sf::RenderWindow window(sf::VideoMode(1300, 720), "NON-GRAVITAR"); //Genera la finestra del tutorial, con dimensione e titolo

    sf::Font font; //Font del testo del tutorial
    font.loadFromFile("Font/04B_03__.ttf");

    sf::Texture texture;
    if (!texture.loadFromFile("Texture/videoblocks-retro-8-bit-arcade-game-space-in-loop_hqzbawwz1q_thumbnail-full01.png"))
    {
        // error...
    }

    sf::Sprite background; //Gestisce lo sfondo del tutorial
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, 1300, 720));
    sf::Text tutorial_text[5]; //Questi sono i 5 testi del tutorial
    //Il codice è lo stesso per tutti i seguenti
    tutorial_text[0].setFont(font); //Assegna il font
	tutorial_text[0].setFillColor(sf::Color::White); //Assegna il colore
	tutorial_text[0].setString("Press W, A , S and D or the arrows to move up, left, down and right"); //Assegna il testo
	tutorial_text[0].setPosition(sf::Vector2f(3, 720 / (5 + 1) * 1)); //Posiziona a schermo il testo

	tutorial_text[1].setFont(font);
	tutorial_text[1].setFillColor(sf::Color::White);
	tutorial_text[1].setString("To shoot, press the Space Bar. For the magnetic beam, press T");
	tutorial_text[1].setPosition(sf::Vector2f(5, 720 / (5 + 1) * 2));

	tutorial_text[2].setFont(font);
	tutorial_text[2].setFillColor(sf::Color::White);
	tutorial_text[2].setString("To close the game window, press ESC on the keyboard");
	tutorial_text[2].setPosition(sf::Vector2f(3, 720 / (5 + 1) * 3));

	tutorial_text[3].setFont(font);
	tutorial_text[3].setFillColor(sf::Color::White);
	tutorial_text[3].setString("If the HP bar or the Fuel are reduced to 0, the game goes in GAME OVER");
	tutorial_text[3].setPosition(sf::Vector2f(5, 720 / (5 + 1) * 4));

	tutorial_text[4].setFont(font);
	tutorial_text[4].setFillColor(sf::Color::White);
	tutorial_text[4].setString("To leave a planet, go up while in the window with the terrain");
	tutorial_text[4].setPosition(sf::Vector2f(5, 720 / (5 + 1) * 5));

    while (window.isOpen()) //Gestisce l'aperture della finestra
    {
        sf::Event event; //Evento
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ //Se si preme ESC sulla tastiera, si torna al menu
            window.close();
        }
        //Draw
        window.clear();
        window.draw(background);
        for (int i = 0; i < 5; i++) //Il ciclo permette disegnare ogni elemento del tutorial
        {
            window.draw(tutorial_text[i]);
        }
        window.display();
    }

}
