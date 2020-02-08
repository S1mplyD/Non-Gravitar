#include "Planet.h"

Planet::Planet(sf::Texture *texture){ //Costruttore
    //Bunker
    Texture enemyTexture, enemy2Texture;
    enemyTexture.loadFromFile("Texture/Bunker.png");
    enemy2Texture.loadFromFile("Texture/Bunker2.png");
    //Carburante
    Texture fuelTexture, fuel2Texture;
    fuelTexture.loadFromFile("Texture/fuel50.png");
    fuel2Texture.loadFromFile("Texture/fuel100.png");
    shape_of_planet.setTexture(*texture);
    Bunker bunker1(&enemyTexture);//SI richiamano i costruttori di bunker e fuel
    Bunker2 bunker2(&enemy2Texture);
    Fuel fuel1(&fuelTexture);
    Fuel2 fuel2(&fuel2Texture);
    numero_bunker1 = rand() % 3 + 1; //Si genera randomicamente il numero di bunker e fuel, di entrambi i tipi
    numero_bunker2 = rand() % 3 + 1;
    numero_fuel1 = rand() % 3 + 1;
    numero_fuel2 = rand() % 3 + 1;
    for (int i = 0; i < 14; i++){ //Si generano casualmente le ordinate dei punti del terreno
        y_punti_terreno[i] = rand()%(600-500 + 1) + 500;
    }
    int n1 = 0; //Si creano le posizioni preimpostate per le posizioni di bunker e fuel
    for (int i = 0; i < numero_bunker1; i++){
            pos_bunker1[i] = n1;
            n1 = n1 + 2;
    }
    int n2 = 8;
    for (int i = 0; i < numero_bunker2; i++){
            pos_bunker2[i] = n2;
            n2 = n2 + 2;
    }
    int n3 = 1;
    for (int i = 0; i < numero_fuel1; i++){
            pos_fuel1[i] = n3;
            n3 = n3 + 2;
    }

    int n4 = 7;
    for (int i = 0; i < numero_fuel2; i++){
            pos_fuel2[i] = n4;
            n4 = n4 + 2;
    }
    //Si riempiono i vettori dei fuel e dei bunker
    for(int i = 0; i < numero_bunker1; i++)
    {
        nemici1.push_back(bunker1);
    }
    for(int i = 0; i < numero_bunker2; i++)
    {
        nemici2.push_back(bunker2);
    }

    for(int i = 0; i < numero_fuel1; i++)
    {
        carburante1.push_back(fuel1);
    }
    for(int i = 0; i < numero_fuel2; i++)
    {
        carburante2.push_back(fuel2);
    }

}

void Planet::entrata_in_atmosfera(sf::Texture *texture){
    shape_of_planet.setTexture(*texture); //Setta la texture del pianeta
}
