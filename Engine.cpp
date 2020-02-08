#include "Engine.h"
namespace engine{

    void Draw(sf::RenderWindow &window, Player &player, std::vector<sf::ConvexShape> &hitbox, sf::VertexArray &lines,Text scoreText, Text fuelText,std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2,std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2){
    for (size_t i = 0; i < player.bulletsdown.size(); i++)
        {
            player.bulletsdown[i].draw(window); //disegno i proiettili
        }
        for (size_t i = 0; i < player.bulletsup.size(); i++)
        {
            player.bulletsup[i].draw(window); //disegno i proiettili
        }
        for (size_t i = 0; i < player.bulletsleft.size(); i++)
        {
            player.bulletsleft[i].draw(window); //disegno i proiettili
        }
        for (size_t i = 0; i < player.bulletsright.size(); i++)
        {
            player.bulletsright[i].draw(window); //disegno i proiettili
        }
        window.draw(scoreText); // Disegna testo score
        window.draw(player.shape); //Disegna player
        window.draw(player.hpBar); //Disegna barra della vita
        window.draw(fuelText); //Disegna testo fuel
        for (size_t i = 0; i < hitbox.size(); i++) {window.draw(hitbox[i]);} //Disegna hitbox terreno
        window.draw(lines); //Disegna linea bordo terreno
        for (size_t i = 0; i < nemici1.size(); i++)
	    {
			window.draw(nemici1[i].shape); //Disegna i bunker del primo tipo
		}
		for (size_t i = 0; i < nemici2.size() ; i++)
	    {
			window.draw(nemici2[i].shape); //Disegna i bunker del secondo tipo
		}
        for(size_t i = 0; i < carburante1.size(); i++)
        {
            window.draw(carburante1[i].shape); //Disegna i fuel dei primo tipo
		}
		for(size_t i = 0; i < carburante2.size(); i++)
		{
            window.draw(carburante2[i].shape); //Disegna i fuel del secondo tipo
		}
    }

    void SistemaSparo(char lastdir,Bullet newbullet, Player &player, sf::Sound &shoot_sound, sf::SoundBuffer &buffershoot, int &timerProiettili){

        if (timerProiettili < 15) //uso un timer per evitare che i proiettili vadano ad una velocità eccessiva
                timerProiettili++;

			if (Keyboard::isKeyPressed(Keyboard::Space) && timerProiettili >= 15 && lastdir == 'd') //Sto sparando
			{
			    newbullet.setPos(Vector2f(player.shape.getPosition().x+24, player.shape.getPosition().y +20)); //setto da dove devono partire i proiettili
				player.bulletsdown.push_back(newbullet); //aggiungo un proiettile nel vettore
				timerProiettili = 0; //reset timer
				shoot_sound.setBuffer(buffershoot);
				shoot_sound.play();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space) && timerProiettili >= 15 && lastdir == 'u') //Sto sparando
			{
			    newbullet.setPos(Vector2f(player.shape.getPosition().x+24, player.shape.getPosition().y +20)); //setto da dove devono partire i proiettili
				player.bulletsup.push_back(newbullet); //aggiungo un proiettile nel vettore
				timerProiettili = 0; //reset timer
				shoot_sound.setBuffer(buffershoot);
				shoot_sound.play();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space) && timerProiettili >= 15 && lastdir == 'l') //Sto sparando
			{
			    newbullet.setPos(Vector2f(player.shape.getPosition().x+24, player.shape.getPosition().y +20)); //setto da dove devono partire i proiettili
				player.bulletsleft.push_back(newbullet); //aggiungo un proiettile nel vettore
				timerProiettili = 0; //reset timer
				shoot_sound.setBuffer(buffershoot);
				shoot_sound.play();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Space) && timerProiettili >= 15 && lastdir == 'r') //Sto sparando
			{
			    newbullet.setPos(Vector2f(player.shape.getPosition().x+24, player.shape.getPosition().y +20)); //setto da dove devono partire i proiettili
				player.bulletsright.push_back(newbullet); //aggiungo un proiettile nel vettore
				timerProiettili = 0; //reset timer
				shoot_sound.setBuffer(buffershoot);
				shoot_sound.play();
			}
}

    void PlayerBulletCollision(Player &player, std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2, sf::Sound &die_bunker_sound, sf::SoundBuffer &bufferdeath, sf::RenderWindow &window){
        for (size_t i = 0; i < player.bulletsdown.size(); i++)
                {
                    player.bulletsdown[i].fuocod(); //faccio muovere i proiettili
                    if(player.bulletsdown[i].getY() > window.getSize().y+720)
                    {
                        player.bulletsdown.erase(player.bulletsdown.begin() +i);
                    }
                    //controllo se i proiettili collidono con i bunker
                    for (size_t k = 0; k < nemici1.size(); k++)
                    {
                        if (player.bulletsdown[i].bullet.getGlobalBounds().intersects(nemici1[k].shape.getGlobalBounds()))
                        {
                            if (nemici1[k].getHP() < 1)
                            {   //se il proiettile collide e il bunker ha 1hp allora viene eliminato dal vettore
                                player.ScoreUp1();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici1.erase(nemici1.begin() + k);
                            }
                                //se invece il bunker ha più di 1hp perde un punto salute per proiettile
                                nemici1[k].DannoSubito();
                            //quando il proiettile collide con il bunker, viene eliminato
                            player.bulletsdown.erase(player.bulletsdown.begin() + i);
                        }
                    }

                    //stesso ciclo visto sopra, ma per i bunker2
                    for (size_t k = 0; k < nemici2.size(); k++)
                    {
                        if (player.bulletsdown[i].bullet.getGlobalBounds().intersects(nemici2[k].shape.getGlobalBounds()))
                        {
                            if (nemici2[k].getHP() <= 1)
                            {
                                player.ScoreUp2();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici2.erase(nemici2.begin() + k);
                            }
                                nemici2[k].DannoSubito();
                            player.bulletsdown.erase(player.bulletsdown.begin() + i);
                        }
                    }
                }
                for (size_t i = 0; i < player.bulletsup.size(); i++)
                {
                    player.bulletsup[i].fuocou(); //faccio muovere i proiettili
                    if(player.bulletsup[i].getY() > window.getSize().y+720)
                    {
                        player.bulletsup.erase(player.bulletsup.begin() +i);
                    }
                    //controllo se i proiettili collidono con i bunker
                    for (size_t k = 0; k < nemici1.size(); k++)
                    {
                        if (player.bulletsup[i].bullet.getGlobalBounds().intersects(nemici1[k].shape.getGlobalBounds()))
                        {
                            if (nemici1[k].getHP() < 1)
                            {   //se il proiettile collide e il bunker ha 1hp allora viene eliminato dal vettore
                                player.ScoreUp1();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici1.erase(nemici1.begin() + k);
                            }
                            //se invece il bunker ha più di 1hp perde un punto salute per proiettile
                            nemici1[k].DannoSubito();
                            //quando il proiettile collide con il bunker, viene eliminato
                            player.bulletsup.erase(player.bulletsup.begin() + i);
                        }
                    }

                    //stesso ciclo visto sopra, ma per i bunker2
                    for (size_t k = 0; k < nemici2.size(); k++)
                    {
                        if (player.bulletsup[i].bullet.getGlobalBounds().intersects(nemici2[k].shape.getGlobalBounds()))
                        {
                            if (nemici2[k].getHP() <= 1)
                            {
                                player.ScoreUp2();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici2.erase(nemici2.begin() + k);
                            }
                                nemici2[k].DannoSubito();
                            player.bulletsup.erase(player.bulletsup.begin() + i);
                        }
                    }
                }
                for (size_t i = 0; i < player.bulletsleft.size(); i++){
                    player.bulletsleft[i].fuocol(); //faccio muovere i proiettili
                    if(player.bulletsleft[i].getY() > window.getSize().y+720){
                    player.bulletsleft.erase(player.bulletsleft.begin() +i);
                }
                //controllo se i proiettili collidono con i bunker
                for (size_t k = 0; k < nemici1.size(); k++)
                    {
                        if (player.bulletsleft[i].bullet.getGlobalBounds().intersects(nemici1[k].shape.getGlobalBounds()))
                        {
                            if (nemici1[k].getHP() < 1)
                            {   //se il proiettile collide e il bunker ha 1hp allora viene eliminato dal vettore
                                player.ScoreUp1();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici1.erase(nemici1.begin() + k);
                            }
                                //se invece il bunker ha più di 1hp perde un punto salute per proiettile
                                nemici1[k].DannoSubito();
                            //quando il proiettile collide con il bunker, viene eliminato
                            player.bulletsleft.erase(player.bulletsleft.begin() + i);
                        }
                    }

                    //stesso ciclo visto sopra, ma per i bunker2
                    for (size_t k = 0; k < nemici2.size(); k++)
                    {
                        if (player.bulletsleft[i].bullet.getGlobalBounds().intersects(nemici2[k].shape.getGlobalBounds()))
                        {
                            if (nemici2[k].getHP() <= 1)
                            {
                                player.ScoreUp2();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici2.erase(nemici2.begin() + k);
                            }
                                nemici2[k].DannoSubito();
                            player.bulletsleft.erase(player.bulletsleft.begin() + i);
                        }
                    }
                }
                for (size_t i = 0; i < player.bulletsright.size(); i++){
                    player.bulletsright[i].fuocor(); //faccio muovere i proiettili
                    if(player.bulletsright[i].getY() > window.getSize().y+720)
                    {
                        player.bulletsright.erase(player.bulletsright.begin() +i);
                    }
                //controllo se i proiettili collidono con i bunker
                for (size_t k = 0; k < nemici1.size(); k++)
                    {
                        if (player.bulletsright[i].bullet.getGlobalBounds().intersects(nemici1[k].shape.getGlobalBounds()))
                        {
                            if (nemici1[k].getHP() < 1)
                            {   //se il proiettile collide e il bunker ha 1hp allora viene eliminato dal vettore
                                player.ScoreUp1();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici1.erase(nemici1.begin() + k);
                            }
                                //se invece il bunker ha più di 1hp perde un punto salute per proiettile
                                nemici1[k].DannoSubito();
                            //quando il proiettile collide con il bunker, viene eliminato
                            player.bulletsright.erase(player.bulletsright.begin() + i);
                        }
                    }

                    //stesso ciclo visto sopra, ma per i bunker2
                    for (size_t k = 0; k < nemici2.size(); k++)
                    {
                        if (player.bulletsright[i].bullet.getGlobalBounds().intersects(nemici2[k].shape.getGlobalBounds()))
                        {
                            if (nemici2[k].getHP() <= 1)
                            {
                                player.ScoreUp2();
                                die_bunker_sound.setBuffer(bufferdeath);
                                die_bunker_sound.play();
                                nemici2.erase(nemici2.begin() + k);
                            }
                                nemici2[k].DannoSubito();
                            player.bulletsright.erase(player.bulletsright.begin() + i);
                        }
                    }
                }
    }

    void RaggioTraenteCollision(Player &player, sf::RenderWindow &window, std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2){
            RaggioTraente raggioTraente(player);
                    raggioTraente.draw(window);
                    //Si controlla se il raggio traente collide con i fuel
                    for (size_t k = 0; k < carburante1.size(); k++)
                    {
                        if (raggioTraente.raggioTraente.getGlobalBounds().intersects(carburante1[k].shape.getGlobalBounds()))
                        {
                            player.fuelUP();
                            carburante1.erase(carburante1.begin() + k);
                        }
                    }
                    for (size_t k = 0; k < carburante2.size(); k++)
                    {
                        if (raggioTraente.raggioTraente.getGlobalBounds().intersects(carburante2[k].shape.getGlobalBounds()))
                        {
                            player.fuelUP2();
                            carburante2.erase(carburante2.begin() + k);
                        }
                    }
    }

    void PacmanEffect(Player &player, sf::RenderWindow &window){
        if(player.shape.getPosition().x > 1270 ) //Se esci dalla schermata a destra...
                    player.shape.setPosition(Vector2f(0.f, player.shape.getPosition().y)); //... ricompare a sinistra
                if(player.shape.getPosition().x < 0) //se esci dalla schermata a sinistra...
                        player.shape.setPosition(Vector2f(1260.f, player.shape.getPosition().y)); //... ricompare a destra
                if(player.shape.getPosition().y < 30) //Impedisce di uscire dallo schermo in alto
                    player.shape.setPosition(Vector2f(player.shape.getPosition().x, 30));
                if(player.shape.getPosition().y > window.getSize().y -40) //Impedisce di uscire dallo schermo in basso
                    player.shape.setPosition(Vector2f(player.shape.getPosition().x, window.getSize().y - 50));
    }

    void BunkerShootingSystem(std::vector<Bunker> &nemici1, int &timerProiettiliBunker, sf::RenderWindow &window, EnemyBullet bunkerbullet1){
    if(timerProiettiliBunker < 15) //Timer tra un proiettile e l'altro
                    timerProiettiliBunker++;

                if(timerProiettiliBunker >= 15){ //Mentre il timer è ancora pieno, allora riempe i vettori dei proiettili
                    for(size_t i = 0; i < nemici1.size(); i++){
                        bunkerbullet1.setPos(sf::Vector2f(nemici1[i].shape.getPosition().x +25, nemici1[i].shape.getPosition().y)); //Direziona i proiettili
                        nemici1[i].bullets.push_back(bunkerbullet1);
                        nemici1[i].bulletsl.push_back(bunkerbullet1);
                    }
                    timerProiettiliBunker = 0;
                }
                for(size_t i = 0; i < nemici1.size(); i++){ //Spara i proiettili
                    for(size_t j = 0; j < nemici1[i].bullets.size(); j++){
                        nemici1[i].bullets[j].fuoco();
                        nemici1[i].bullets[j].draw(window);
                    }
                }
                for(size_t i = 0; i < nemici1.size(); i++){ //Spara i proiettili
                    for(size_t j = 0; j < nemici1[i].bulletsl.size(); j++){
                        nemici1[i].bulletsl[j].fuocol();
                        nemici1[i].bulletsl[j].draw(window);
                    }
                }
    }
 //Il codice di sopra è simile a quello sopra. Non è necessario ripetere i commenti
    void Bunker2ShootingSystem(std::vector<Bunker2> &nemici2, int &timerProiettiliBunker2, sf::RenderWindow &window, EnemyBullet2 bunkerbullet2){
        if(timerProiettiliBunker2 < 45)
                    timerProiettiliBunker2++;

                if(timerProiettiliBunker2 >= 45){
                    for(size_t i = 0; i < nemici2.size(); i++){
                        bunkerbullet2.setPos(sf::Vector2f(nemici2[i].shape.getPosition().x +25, nemici2[i].shape.getPosition().y));
                        nemici2[i].bullets.push_back(bunkerbullet2);
                        nemici2[i].bulletsl.push_back(bunkerbullet2);
                        nemici2[i].bulletsc.push_back(bunkerbullet2);
                    }
                    timerProiettiliBunker2 = 0;
                }
                for(size_t i = 0; i < nemici2.size(); i++)
                {
                    for(size_t j = 0; j < nemici2[i].bullets.size(); j++)
                    {
                        nemici2[i].bullets[j].fuoco();
                        nemici2[i].bullets[j].draw(window);
                    }
                }
                for(size_t i = 0; i < nemici2.size(); i++)
                {
                    for(size_t j = 0; j < nemici2[i].bulletsl.size(); j++)
                    {
                        nemici2[i].bulletsl[j].fuocol();
                        nemici2[i].bulletsl[j].draw(window);
                    }
                }

                 for(size_t i = 0; i < nemici2.size(); i++)
                 {
                    for(size_t j = 0; j < nemici2[i].bulletsc.size(); j++)
                    {
                        nemici2[i].bulletsc[j].fuococ();
                        nemici2[i].bulletsc[j].draw(window);
                    }
                 }
    }

    void BunkerBulletRemove(std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2){
        for(size_t i = 0; i < nemici1.size(); i++) //Mentre i bunker sono ancora presenti
                {
                    for(size_t j = 0; j < nemici1[i].bullets.size(); j++) //Mentre i vettori di proiettili sono pieni
                    {
                        if(nemici1[i].bullets[j].getY() < 0 || nemici1[i].bullets[j].getX() > 1300 || nemici1[i].bullets[j].getX() < 0) //Li cancella quando finiscono fuori dallo schermo
                            nemici1[i].bullets.erase(nemici1[i].bullets.begin() + j);
                    }
                }
                for(size_t i = 0; i < nemici1.size(); i++) //Uguale a sopra
                {
                    for(size_t j = 0; j < nemici1[i].bulletsl.size(); j++)
                    {
                        if(nemici1[i].bulletsl[j].getY() < 0 || nemici1[i].bulletsl[j].getX() > 1300 || nemici1[i].bulletsl[j].getX() < 0)
                            nemici1[i].bulletsl.erase(nemici1[i].bulletsl.begin() + j);
                    }
                }

                //bunker 2 out of bounds
                for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
                {
                    for(size_t j = 0; j < nemici2[i].bullets.size(); j++)
                    {
                        if(nemici2[i].bullets[j].getY() < 0 || nemici2[i].bullets[j].getX() > 1300 || nemici2[i].bullets[j].getX() < 0)
                            nemici2[i].bullets.erase(nemici2[i].bullets.begin() + j);
                    }
                }
                for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
                {
                    for(size_t j = 0; j < nemici2[i].bulletsl.size(); j++)
                    {
                        if(nemici2[i].bulletsl[j].getY() < 0 || nemici2[i].bulletsl[j].getX() > 1300 || nemici2[i].bulletsl[j].getX() < 0)
                            nemici2[i].bulletsl.erase(nemici2[i].bulletsl.begin() + j);
                    }
                }
                for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
                {
                    for(size_t j = 0; j < nemici2[i].bulletsc.size(); j++)
                    {
                        if(nemici2[i].bulletsc[j].getY() < 0 || nemici2[i].bulletsc[j].getX() > 1300 || nemici2[i].bulletsc[j].getX() < 0)
                            nemici2[i].bulletsc.erase(nemici2[i].bulletsc.begin() + j);
                    }
                }
    }

    void BunkerBulletCollision(std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2, Player &player){
    for(size_t i = 0; i < nemici1.size(); i++) //Per ogni bunker controlliamo se i loro proiettili colpiscono il player
            {
                for(size_t j = 0; j < nemici1[i].bullets.size(); j++)
                {
                    if(nemici1[i].bullets[j].bullet.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        player.DannoSubito(); //Danneggia il player
                        nemici1[i].bullets.erase(nemici1[i].bullets.begin() + i); //Cancella il proiettile
                    }

                }
            }
            for(size_t i = 0; i < nemici1.size(); i++) //Uguale a sopra
                {
                for(size_t j = 0; j < nemici1[i].bulletsl.size(); j++)
                {
                    if(nemici1[i].bulletsl[j].bullet.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        player.DannoSubito();
                        nemici1[i].bulletsl.erase(nemici1[i].bulletsl.begin() + i);
                    }

                }
            }
            //collisioni proiettili bunker2 sul player
            for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
            {
                for(size_t j = 0; j < nemici2[i].bullets.size(); j++)
                {
                    if(nemici2[i].bullets[j].bullet.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        player.DannoSubito();
                        nemici2[i].bullets.erase(nemici2[i].bullets.begin() + i);
                    }

                }
            }
            for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
            {
                for(size_t j = 0; j < nemici2[i].bulletsl.size(); j++)
                {
                    if(nemici2[i].bulletsl[j].bullet.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        player.DannoSubito();
                        nemici2[i].bulletsl.erase(nemici2[i].bulletsl.begin() + i);
                    }
                }
            }
            for(size_t i = 0; i < nemici2.size(); i++) //Uguale a sopra
            {
                for(size_t j = 0; j < nemici2[i].bulletsc.size(); j++)
                {
                    if(nemici2[i].bulletsc[j].bullet.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        player.DannoSubito();
                        nemici2[i].bulletsc.erase(nemici2[i].bulletsc.begin() + i);
                    }

                }
            }
    }

    void generateTerrain(int y_punti_terreno[], std::vector<sf::ConvexShape> &v){
    sf::ConvexShape hb1, hb2, hb3, hb4, hb5, hb6, hb7, hb8, hb9, hb10, hb11, hb12, hb13;
    hb1.setPointCount(4);
    hb1.setPoint(0, sf::Vector2f(0,720));
    hb1.setPoint(1, sf::Vector2f(0,y_punti_terreno[0]));
    hb1.setPoint(2, sf::Vector2f(100,y_punti_terreno[1]));
    hb1.setPoint(3, sf::Vector2f(100,720));
    hb1.setFillColor(sf::Color::Black);

    hb2.setPointCount(4);
    hb2.setPoint(0, sf::Vector2f(100,720));
    hb2.setPoint(1, sf::Vector2f(100,y_punti_terreno[1]));
    hb2.setPoint(2, sf::Vector2f(200,y_punti_terreno[2]));
    hb2.setPoint(3, sf::Vector2f(200,720));
    hb2.setFillColor(sf::Color::Black);

    hb3.setPointCount(4);
    hb3.setPoint(0, sf::Vector2f(200,720));
    hb3.setPoint(1, sf::Vector2f(200,y_punti_terreno[2]));
    hb3.setPoint(2, sf::Vector2f(300,y_punti_terreno[3]));
    hb3.setPoint(3, sf::Vector2f(300,720));
    hb3.setFillColor(sf::Color::Black);

    hb4.setPointCount(4);
    hb4.setPoint(0, sf::Vector2f(300,720));
    hb4.setPoint(1, sf::Vector2f(300,y_punti_terreno[3]));
    hb4.setPoint(2, sf::Vector2f(400,y_punti_terreno[4]));
    hb4.setPoint(3, sf::Vector2f(400,720));
    hb4.setFillColor(sf::Color::Black);

    hb5.setPointCount(4);
    hb5.setPoint(0, sf::Vector2f(400,720));
    hb5.setPoint(1, sf::Vector2f(400,y_punti_terreno[4]));
    hb5.setPoint(2, sf::Vector2f(500,y_punti_terreno[5]));
    hb5.setPoint(3, sf::Vector2f(500,720));
    hb5.setFillColor(sf::Color::Black);

    hb6.setPointCount(4);
    hb6.setPoint(0, sf::Vector2f(500,720));
    hb6.setPoint(1, sf::Vector2f(500,y_punti_terreno[5]));
    hb6.setPoint(2, sf::Vector2f(600,y_punti_terreno[6]));
    hb6.setPoint(3, sf::Vector2f(600,720));
    hb6.setFillColor(sf::Color::Black);

    hb7.setPointCount(4);
    hb7.setPoint(0, sf::Vector2f(600,720));
    hb7.setPoint(1, sf::Vector2f(600,y_punti_terreno[6]));
    hb7.setPoint(2, sf::Vector2f(700,y_punti_terreno[7]));
    hb7.setPoint(3, sf::Vector2f(700,720));
    hb7.setFillColor(sf::Color::Black);

    hb8.setPointCount(4);
    hb8.setPoint(0, sf::Vector2f(700,720));
    hb8.setPoint(1, sf::Vector2f(700,y_punti_terreno[7]));
    hb8.setPoint(2, sf::Vector2f(800,y_punti_terreno[8]));
    hb8.setPoint(3, sf::Vector2f(800,720));
    hb8.setFillColor(sf::Color::Black);

    hb9.setPointCount(4);
    hb9.setPoint(0, sf::Vector2f(800,720));
    hb9.setPoint(1, sf::Vector2f(800,y_punti_terreno[8]));
    hb9.setPoint(2, sf::Vector2f(900,y_punti_terreno[9]));
    hb9.setPoint(3, sf::Vector2f(900,720));
    hb9.setFillColor(sf::Color::Black);

    hb10.setPointCount(4);
    hb10.setPoint(0, sf::Vector2f(900,720));
    hb10.setPoint(1, sf::Vector2f(900,y_punti_terreno[9]));
    hb10.setPoint(2, sf::Vector2f(1000,y_punti_terreno[10]));
    hb10.setPoint(3, sf::Vector2f(1000,720));
    hb10.setFillColor(sf::Color::Black);

    hb11.setPointCount(4);
    hb11.setPoint(0, sf::Vector2f(1000,720));
    hb11.setPoint(1, sf::Vector2f(1000,y_punti_terreno[10]));
    hb11.setPoint(2, sf::Vector2f(1100,y_punti_terreno[11]));
    hb11.setPoint(3, sf::Vector2f(1100,720));
    hb11.setFillColor(sf::Color::Black);

    hb12.setPointCount(4);
    hb12.setPoint(0, sf::Vector2f(1100,720));
    hb12.setPoint(1, sf::Vector2f(1100,y_punti_terreno[11]));
    hb12.setPoint(2, sf::Vector2f(1200,y_punti_terreno[12]));
    hb12.setPoint(3, sf::Vector2f(1200,720));
    hb12.setFillColor(sf::Color::Black);

    hb13.setPointCount(4);
    hb13.setPoint(0, sf::Vector2f(1200,720));
    hb13.setPoint(1, sf::Vector2f(1200,y_punti_terreno[12]));
    hb13.setPoint(2, sf::Vector2f(1300,y_punti_terreno[13]));
    hb13.setPoint(3, sf::Vector2f(1300,720));
    hb13.setFillColor(sf::Color::Black);

     //Riempie il vettore di convexshape per ogni pezzo della hitbox
    v.push_back(hb1);
    v.push_back(hb2);
    v.push_back(hb3);
    v.push_back(hb4);
    v.push_back(hb5);
    v.push_back(hb6);
    v.push_back(hb7);
    v.push_back(hb8);
    v.push_back(hb9);
    v.push_back(hb10);
    v.push_back(hb11);
    v.push_back(hb12);
    v.push_back(hb13);
    }



}
