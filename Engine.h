#include "Player.h"
#include "Nemici.h"
#include "Fuel.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "RaggioTraente.h"
#include "Planet.h"

namespace engine {

    void Draw(sf::RenderWindow &window, Player &player, std::vector<sf::ConvexShape> &hitbox, sf::VertexArray &lines,Text scoreText, Text fuelText,std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2,std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2); //Disegna tutti gli oggetti a schermo
    void SistemaSparo(char lastdir, Bullet newbullet, Player &player, sf::Sound &shoot_sound, sf::SoundBuffer &buffershoot, int &timerProiettili); //Gestisce il sistema di sparo del player
    void PlayerBulletCollision(Player &player, std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2, sf::Sound &die_bunker_sound, sf::SoundBuffer &bufferdeath,sf::RenderWindow &window); //Collisione dei proiettili del player con i bunker
    void RaggioTraenteCollision(Player &player, sf::RenderWindow &window, std::vector<Fuel> &carburante1, std::vector<Fuel2> &carburante2); //Gestisce collisione tra raggio traente e fuel
    void PacmanEffect(Player &player, sf::RenderWindow &window); //Implementa il cosiddetto "Pacman"
    void BunkerShootingSystem(std::vector<Bunker> &nemici1, int &timerProiettiliBunker, sf::RenderWindow &window, EnemyBullet bunkerbullet1); //Gestisce lo sparo dei bunker del primo tipo
    void Bunker2ShootingSystem(std::vector<Bunker2> &nemici2, int &timerProiettiliBunker2, sf::RenderWindow &window, EnemyBullet2 bunkerbullet2); //Gestisce lo sparo dei bunker del secondo tipo
    void BunkerBulletRemove(std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2); //Cancella i proiettili dei bunker una volta usciti dallo schermo
    void BunkerBulletCollision(std::vector<Bunker> &nemici1, std::vector<Bunker2> &nemici2, Player &player); //Gestisce le collisioni tra proiettili e player
    void generateTerrain(int y_punti_terreno[], std::vector<sf::ConvexShape> &v);

};
