#include "DeathScene.h"

DeathScene::DeathScene(sf::Font *font)
{
    death_scene.setSize(Vector2f(1300.0f,720.0f)); //Dimensiona il rettangolo sul retro
    death_text.setFont(*font); //Mette il font
    death_text.setCharacterSize(20); //Mette la dimensione delle parole
    death_text.setFillColor(Color::White); //Setta il colore della scritta
    death_text.setPosition(350.0f, 500.0f); //Setta la posizione
}

void DeathScene::HandleDeathScene(sf::RenderWindow &window)
{
    if (Keyboard::isKeyPressed(Keyboard::Y)) //Se si preme Y, chiude la finestra e richiama SystemGame, iniziando un nuovo gioco
    {
        window.close();
        SystemGame();
    }
    else if (Keyboard::isKeyPressed(Keyboard::N)) window.close(); //Se si preme N, chiude la schermata e basta, permettendo di tornare al menu
}

void DeathScene::DrawDeath(sf::RenderWindow &window)
{
    window.draw(death_scene); //Disegna lo sfondo
    window.draw(death_text); //disegna la scritta
}

void DeathScene::GameOver(sf::RenderWindow &window, Player &player){
    if ((player.getHP() <= 0) || (player.getFuel() <= 1)) //Questa funzione fonde le due precedenti: se il player muore ...
        {
            window.clear();// ... rimuove tutto dallo schermo ...
            DrawDeath(window);// ... disegna sfondo e scritta ...
            HandleDeathScene(window);// ... e gestisce l'uscita dal gioco
        }
}
