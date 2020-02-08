#include "MainGame.h"

MainGame::MainGame(Player &player, int y_punti_terreno[], int indici_bunker1[], int indici_bunker2[], int indici_fuel1[], int indici_fuel2[], int numero_bunker1, int numero_bunker2, int numero_fuel1, int numero_fuel2,
                   std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2, std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2, sf::RenderWindow &window)
{
    bool FLAG = 1;
    srand(time(NULL));
    Font font; //Font di fuel e score
    font.loadFromFile("Font/04B_03__.ttf");

    sf::Texture texture; //Texture sfondo
    if (!texture.loadFromFile("Texture/videoblocks-retro-8-bit-arcade-game-space-in-loop_hqzbawwz1q_thumbnail-full01.png"))
    {
        // error...
    }

    sf::Sprite background; //Sprite sfondo
    background.setTexture(texture);
    background.setTextureRect(sf::IntRect(0, 0, 1300, 720));

    sf::SoundBuffer buffershoot; //Suono sparo player

    if (!buffershoot.loadFromFile("Suoni/shooting_sound.wav"))
    {
        //Handle error
    }

    sf::Sound shoot_sound;

    sf::SoundBuffer bufferdeath; //Suono morte bunker
    if (!bufferdeath.loadFromFile("Suoni/die_bunker.wav"))
    {
        //Handle error
    }
    sf::Sound die_bunker_sound;


    window.setFramerateLimit(60);//Settiamo il framerate della schermata

    sf::Texture enemyTexture; //Texture bunker primo tipo
    enemyTexture.loadFromFile("Texture/Bunker.png");

    sf::Texture enemy2Texture; //Texture bunker secondo tipo
    enemy2Texture.loadFromFile("Texture/Bunker2.png");

    sf::Texture fuelTexture; //Texture fuel primo tipo
    fuelTexture.loadFromFile("Texture/fuel50.png");

    sf::Texture fuel2Texture; //Texture fuel secondo tipo
    fuel2Texture.loadFromFile("Texture/fuel100.png");

    //generazione mondo
    //Vettore di forme convesse, per la hitbox. Ad ognuno di essi sono assegnati i punti y del terreno
    std::vector<sf::ConvexShape> hitbox;
    engine::generateTerrain(y_punti_terreno, hitbox);


    int x = 0;
    sf::VertexArray terrain(sf::LinesStrip, 14); //Crea il bordo del terreno
    for(size_t i = 0; i < 14; i++) //Colloca i vertici del bordo del terreno
    {
        terrain[i].position = Vector2f(x, y_punti_terreno[i]);
        x += 100;
    }

    //proiettili
    Bullet newbullet(Vector2f(4,4));
    EnemyBullet bunkerbullet1(3);
    EnemyBullet2 bunkerbullet2(3);

    //inizializzazione giocatore

    int timerProiettili = 20;

    //Barra della vita, con colore, dimensione e posizione
    player.hpBar.setFillColor(Color::Yellow);
    player.hpBar.setSize(Vector2f((float)player.getHP()* 20.f , 20.f));
    player.hpBar.setPosition(560.f, 10.f);

    char lastdir;

    //You Died
    Texture youdiedtexture;
    youdiedtexture.loadFromFile("Texture/youDied.jpg"); //Texture schermata di morte
    DeathScene deathscene(&font);
    deathscene.death_scene.setTexture(&youdiedtexture);

    //imposto il timer dei proiettili nemici e il contatore dei nemici nella mappa
    int timerProiettiliBunker = 20;
    int timerProiettiliBunker2 = 50;

    //Inizializzazione interfaccia utente
	Text scoreText; //Testo score, con dimensione, posizione e colore
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(1100.f, 10.f);

	Text fuelText;//Testo fuel, con dimensione, posizione e colore
	fuelText.setFont(font);
	fuelText.setCharacterSize(20);
	fuelText.setFillColor(Color::White);
	fuelText.setPosition(200.f,10.f);

    //Nemici
    //Posiziona i bunker dei vettori, e li dota di texture

    for (size_t i = 0; i < nemici1.size(); i++)
    {
            nemici1[i].setpos(hitbox, indici_bunker1[i]);
            nemici1[i].shape.setTexture(enemyTexture);
    }

    for (size_t i = 0; i < nemici2.size() ; i++)
    {
            nemici2[i].setpos(hitbox, indici_bunker2[i]);
            nemici2[i].shape.setTexture(enemy2Texture);
    }

    //carburante
    //Posiziona i fuel dei vettori, e li dota di texture

    for(size_t i = 0; i < carburante1.size(); i++)
    {
            carburante1[i].setpos(hitbox, indici_fuel1[i]);
            carburante1[i].shape.setTexture(fuelTexture);
    }

    for(size_t i = 0; i < carburante2.size(); i++)
    {
            carburante2[i].setpos(hitbox, indici_fuel2[i]);
            carburante2[i].shape.setTexture(fuel2Texture);
    }
    //Setto la posizione del player
    player.shape.setPosition(sf::Vector2f(650.0f,120.0f));

    while(window.isOpen() && FLAG != 0) //Gestisco la schermata
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        if (player.getHP() > 0)
		{
            player.hpBar.setSize(Vector2f((float)player.getHP() * 20.f, 20.f)); //Modifica la barra degli HP in caso essi diminuiscano
			//Movimenti del giocatore
			//WASD
			if (Keyboard::isKeyPressed(Keyboard::W)) //Muoviti in su
			{
				player.shape.move(0.f, -7.f);
				player.fuelDown();
				lastdir = 'u';
            }
			if (Keyboard::isKeyPressed(Keyboard::A)) //Muoviti a sinistra
			{
                player.shape.move(-7.f, 0.f);
				player.fuelDown();
				lastdir = 'l';
			}
			if (Keyboard::isKeyPressed(Keyboard::S)) //Muoviti in giù
			{
                player.shape.move(0.f, 7.f);
				player.fuelDown();
				lastdir = 'd';
			}

			if (Keyboard::isKeyPressed(Keyboard::D)) //Muoviti a destra
            {
                player.shape.move(7.f, 0.f);
                player.fuelDown();
                lastdir = 'r';
			}

            //Freccette (corrispondono al movimento)
            if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                player.shape.move(0.f, -7.f);
				player.fuelDown();
				lastdir = 'u';
            }

			if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                player.shape.move(-7.f, 0.f);
				player.fuelDown();
				lastdir = 'l';
            }

			if (Keyboard::isKeyPressed(Keyboard::Down))
            {
				player.shape.move(0.f, 7.f);
				player.fuelDown();
				lastdir = 'd';
            }
			if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                player.shape.move(7.f, 0.f);
                player.fuelDown();
                lastdir = 'r';
            }

            //Meccaniche di sparo (si trovano nel namespace Engine)
            engine::SistemaSparo(lastdir, newbullet, player, shoot_sound, buffershoot, timerProiettili);
			 if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            {   //"Spara" il raggio traente (si trovano nel namespace Engine)
                engine::RaggioTraenteCollision(player,window,carburante1,carburante2);
            }
            engine::PlayerBulletCollision(player,nemici1,nemici2,die_bunker_sound,bufferdeath, window);
			//effetto pacman e terra piatta (si trovano nel namespace Engine)
            engine::PacmanEffect(player,window);
            //meccaniche di sparo dei bunker1 (si trovano nel namespace Engine)
            engine::BunkerShootingSystem(nemici1,timerProiettiliBunker,window,bunkerbullet1);
            //meccaniche di sparo bunker2 (si trovano nel namespace Engine)
            engine::Bunker2ShootingSystem(nemici2,timerProiettiliBunker2,window,bunkerbullet2);
            //Bunker 1 out of bounds (si trovano nel namespace Engine)
            engine::BunkerBulletRemove(nemici1,nemici2);

            for(size_t i = 0; i < nemici1.size(); i++) //Questa parte controlla se si va a sbattere contro i bunker. Ci si danneggia
            {
                if(player.shape.getGlobalBounds().intersects(nemici1[i].shape.getGlobalBounds()))
                {
                    player.DannoSubito();
                    player.shape.setPosition(sf::Vector2f(player.shape.getPosition().x, player.shape.getPosition().y-30.0f));
                }
            }
            for(size_t i = 0; i < nemici2.size(); i++) //Idem come sopra
            {
                if(player.shape.getGlobalBounds().intersects(nemici2[i].shape.getGlobalBounds()))
                {
                    player.DannoSubito();
                    player.shape.setPosition(sf::Vector2f(player.shape.getPosition().x ,player.shape.getPosition().y-30.0f));
                }
            }

            for (size_t i = 0; i < hitbox.size(); i++){ //Per ogni membro del vettore hitbox
                if(player.shape.getGlobalBounds().intersects(hitbox[i].getLocalBounds())){ //Controlla se si va a sbattere contro il terreno, collidendo con la hitbox
                    player.DannoSubito();
                    player.shape.setPosition(sf::Vector2f(player.shape.getPosition().x, player.shape.getPosition().y-75.0f));
                }
            }

            //collsioni proiettili bunker1 sul player
            engine::BunkerBulletCollision(nemici1,nemici2,player);

            //UI
            scoreText.setString("Score: " + std::to_string(player.getScore())); //Imposto il testo dello score
            fuelText.setString("Fuel: " + std::to_string(player.getFuel())); //Imposto il testo del fuel
            deathscene.death_text.setString("Do you want to play again? Press [Y](Yes) or [N](No)");

            if (((nemici1.empty()==true) && (nemici2.empty()== true)) && (player.shape.getPosition().y < 80)) FLAG = 0; //Questa gestisce, mediante un flag, il passaggio tra schermata sistemi e schermata mondo, senza aprire ogni volta una finestra
            if (player.shape.getPosition().y < 80) FLAG = 0;
            if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close(); //Se premi ESC si chiude la finestra

		}
        //Draw

        engine::Draw(window,player,hitbox,terrain,scoreText,fuelText,nemici1,nemici2,carburante1,carburante2);
        deathscene.GameOver(window, player); //Come in SystemGame, questo gestisce il Game Over

        window.display();
    }
}
