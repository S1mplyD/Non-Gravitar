#include "SystemGame.h"

Systems::Systems(sf::Texture *planet){
    numero_astri = rand() % 4 + 1; //Il numero di pianeti è generato randomicamente tra 1 e 5
    for (int i = 0; i < numero_astri; i++){ //Riempie il vettori dei pianeti, e genera anche le posizioni
        Planet pianeti(planet); //Costruttore pianeti

        astri.push_back(pianeti); //Riempie il vettore
        if (i==0){
            x_astro.push_back(rand() % 250); //Il primo pianeta viene posizionato, e su di esso si basa la posizione degli altro
            y_astro.push_back(rand() % 470 + 150);
        } else {
            x_astro.push_back(rand() % 250 + x_astro[i - 1] + 100); //Questa funzione permette di posizionare ogni pianeta in dipendenza della posizione del successivo
            y_astro.push_back(rand() % 470 + 150);
        }
    }

}

SystemGame::SystemGame(){ //Crea finestra e player, e richiama la funzione di gestione di sistemi
    sf::Texture playerTexture; //Texture del player
    playerTexture.loadFromFile("Texture/Ufo100.png");
    Player player(&playerTexture); //Costruttore con in input la texture del player
    sf::RenderWindow window(VideoMode(1300,720), "NON-GRAVITAR", Style::Default); //Crea la finestra
    AfterSystemGame(it, player, window); //Gestisce il vettore di sistemi e ciò che accade nella
}

int SystemGame::AfterSystemGame(int &it, Player &player, sf::RenderWindow &window){
    player.shape.setPosition(650, 120); //Setta la posizione del player nella finestra
    srand(time(NULL));
    sf::Font font; //Font per fuel e score. Il codice è simile ad altri
    font.loadFromFile("Font/04B_03__.ttf");

    sf::Texture texture;
    if (!texture.loadFromFile("Texture/videoblocks-retro-8-bit-arcade-game-space-in-loop_hqzbawwz1q_thumbnail-full01.png"))
    {
        // error...
    }

    //You Died
    Texture youdiedtexture; //Texture della schermata del Game Over
    youdiedtexture.loadFromFile("Texture/youDied.jpg");
    DeathScene deathscene(&font);
    deathscene.death_scene.setTexture(&youdiedtexture); //Richiama la classe che gestisce la schermata del Game Over

    sf::Sprite background; //Texture dello sfondo
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, 1300, 720)); //Ridimensiona lo sprite dello sfondo

    window.setFramerateLimit(60); //Setta il framerate della schermata

    player.hpBar.setFillColor(Color::Yellow); //Barra della vita del player
    player.hpBar.setSize(Vector2f((float)player.getHP()* 20.f , 20.f)); //Setta la dimensione della barra della vita
    player.hpBar.setPosition(560.f, 10.f);

    Text scoreText; //Testo dello score, con font e colore
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(1100.f, 10.f);

	Text fuelText; //Testo del fuel, con font e colore
	fuelText.setFont(font);
	fuelText.setCharacterSize(20);
	fuelText.setFillColor(Color::White);
	fuelText.setPosition(200.f,10.f);

    sf::Texture planet1; //Texture del pianeta
    planet1.loadFromFile("Texture/planet five.png");

    sf::Texture deadplanet;
    deadplanet.loadFromFile("Texture/planet three.png"); //Texture del pianeta dopo la distruzione dei bunker

    Systems sistema1(&planet1); //Genera il sistema
    vettore_sistemi.push_back(sistema1); //Colloca il

    for (size_t i = 0; i < sistema1.astri.size(); i++){ //Per ogni sistema del vettore di sistemi, crea il vettorie di pianeti
            vettore_sistemi[it].astri[i].shape_of_planet.setPosition(vettore_sistemi[it].x_astro[i], vettore_sistemi[it].y_astro[i]);
    }
    while (window.isOpen()){ //Mentre la finestra rimane aperta fa questo
        Event event;
        while(window.pollEvent(event)){ //Gestisce la chiusura della finestra dalla pressione della X della finestra
            if(event.type == Event::Closed)
                window.close();
        }
        window.clear(); //Pulisce il contenuto della schermata
        window.draw(background); //Disegna il background della finestra
        if ((player.getHP() > 0) && (player.getFuel() > 0)) { //Mentre il player è "vivo", fa le seguenti cose
            player.hpBar.setSize(Vector2f((float)player.getHP() * 20.f, 20.f)); //Modifica la dimensione della barra della vita se il player perde HP
			//Movimenti del giocatore
			//WASD
            if (Keyboard::isKeyPressed(Keyboard::W)){ //Muove in su il giocatore
				player.shape.move(0.f, -7.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::A)){ //Muove a sinistra il giocatore
                player.shape.move(-7.f, 0.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::S)){ //Muova giù il giocatore
                player.shape.move(0.f, 7.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::D)){ //Muove a destra il giocatore
                player.shape.move(7.f, 0.f);
                player.fuelDown();
            }
            //Freccette (i commenti sono gli stessi che erano per WASD
            if (Keyboard::isKeyPressed(Keyboard::Up)){
                player.shape.move(0.f, -7.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                player.shape.move(-7.f, 0.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)){
				player.shape.move(0.f, 7.f);
				player.fuelDown();
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                player.shape.move(7.f, 0.f);
                player.fuelDown();
            }

            size_t k = 0;
            while (k < vettore_sistemi[it].astri.size()){ //Gestisce l'entrata nei pianeti
                if ((player.shape.getGlobalBounds().intersects(vettore_sistemi[it].astri[k].shape_of_planet.getGlobalBounds())) && (vettore_sistemi[it].astri[k].destroyed == false)){
                    MainGame(player, vettore_sistemi[it].astri[k].y_punti_terreno, vettore_sistemi[it].astri[k].pos_bunker1, vettore_sistemi[it].astri[k].pos_bunker2, vettore_sistemi[it].astri[k].pos_fuel1, vettore_sistemi[it].astri[k].pos_fuel2,
                              vettore_sistemi[it].astri[k].numero_bunker1, vettore_sistemi[it].astri[k].numero_bunker2, vettore_sistemi[it].astri[k].numero_fuel1, vettore_sistemi[it].astri[k].numero_fuel2, vettore_sistemi[it].astri[k].nemici1,
                              vettore_sistemi[it].astri[k].nemici2, vettore_sistemi[it].astri[k].carburante1, vettore_sistemi[it].astri[k].carburante2, window);
                    player.shape.setPosition(650, 120);
                    //Qui gestisce la crescita dello score quando si esce dal pianeta, e cambia anche la texture del pianeta. Una volta cambiata la texture, il bool impedisce la rientrata del pianeta
                    if ((vettore_sistemi[it].astri[k].nemici1.size() <= 0) && (vettore_sistemi[it].astri[k].nemici2.size() <= 0)){
                        vettore_sistemi[it].astri[k].shape_of_planet.setTexture(deadplanet);
                        vettore_sistemi[it].astri[k].destroyed = true;
                        player.HPUp();
                        player.ScoreUp3();
                    }
                }
                k++;
            }
            //UI
            scoreText.setString("Score: " + std::to_string(player.getScore())); //Posiziona il testo di score e fuel
            fuelText.setString("Fuel: " + std::to_string(player.getFuel()));
            deathscene.death_text.setString("Do you want to play again? Press [Y](Yes) or [N](No)"); //Testo della schermata del Game Over
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)){ //Se si preme ESC sulla tastiera, allora fa uscire per tornare al menu
            window.close();
        }

        else if(player.shape.getPosition().x > 1250.0f){ //Gestisce il passaggio tra sistemi. Se va oltre il bordo della schermata a destra per raggiungere il sistema successivo
            size_t counter = 0;
            for (size_t i = 0; i < vettore_sistemi[it].astri.size(); i++){ //Conta i pianeti che sono stati distrutti, per getsire il passaggio tra sistemi
                if (vettore_sistemi[it].astri[i].destroyed == true) counter++;
            }
            if (counter == vettore_sistemi[it].astri.size()) { //Se i pianeti sono distrutti
                    it ++; //Aumenta l'iteratore per passare al sistema successivo
                    AfterSystemGame(it, player,window); //Per passare al sistema successivo
                    player.shape.setPosition(650, 120); //Posiziona da capo il player
            } else if (counter < vettore_sistemi[it].astri.size()) player.shape.setPosition(sf::Vector2f(1250,player.shape.getPosition().y)); //Se il counter dei pianeti distrutti è minore del numero dei pianeti, non fa uscire dal sistema corrente
        }
        else if(player.shape.getPosition().x < 0.0f && it != 0){ //Gestisce il passaggio tra sistemi. Se va oltre il bordo della schermata a sinistra per tornare indietro al sistema precedente
                    AfterSystemGame(--it, player,window); //Applica la funzione al sistema successivo
                    player.shape.setPosition(650, 120); //Riposiziona il player
        }
        //Le funzioni seguenti impediscono di uscire dalla schermata in alto e in basso
        else if(player.shape.getPosition().y < 60.0f)
            player.shape.setPosition(sf::Vector2f(player.shape.getPosition().x,60.0f));
        else if(player.shape.getPosition().y > 690.0f)
            player.shape.setPosition(sf::Vector2f(player.shape.getPosition().x,690.0f));
        else if (player.shape.getPosition().x < 0 && it == 0)
            player.shape.setPosition(0,player.shape.getPosition().y);

        //Disegna
        window.draw(scoreText); //Disegna il testo dello score del player
        window.draw(player.hpBar); //Disegna la barra degli HP
        window.draw(fuelText); //Disegna il testo del fuel del player
        for (size_t i = 0; i < vettore_sistemi[it].astri.size(); i++){ //Disegna ogni pianeta del sistema
            window.draw(vettore_sistemi[it].astri[i].shape_of_planet);
        }
        window.draw(player.shape); //Disegna il player
        deathscene.GameOver(window, player); //Se il player muore o finisce il fuel, attiva la schermata del Game Over
        window.display(); //Mostra gli oggetti disegnati a schermo
    }
    return 0;
}


