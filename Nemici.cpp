#include "Nemici.h"
//Classe Bunker (funzionano entrambe allo stesso modo, quindi non riporto i commenti
Bunker::Bunker(Texture *texture){
    HPMAX= 5; //hp massimi del bunker
    HP = HPMAX;
    shape.setTexture(*texture); //setto la texture al bunker
    shape.setScale(0.5f,0.5f);  //scalo le dimensioni

}
int Bunker::isAlive(){
    if(HP > 0)
        return true;
}
int Bunker::getHP(){ //Riporta gli HP correnti
    return HP;
}
int Bunker::getHPMAX(){ //Riporta gli HP massimi
    return HPMAX;
}

 void Bunker::DannoSubito(){ //Diminuisce gli HP correnti
    HP--;
}
void Bunker::setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index){ // Posiziona i bunker sulla linea del terreno, mediante la formula del coefficiente angolare
    shape.setRotation((180 / M_PI) * (atan((surface[current_vertex_index].getPoint(2).y - surface[current_vertex_index].getPoint(1).y) /
    (surface[current_vertex_index].getPoint(2).x - surface[current_vertex_index].getPoint(1).x))));
    shape.setPosition((surface[current_vertex_index].getPoint(1).x + surface[current_vertex_index].getPoint(2).x) / 2,
    ((surface[current_vertex_index].getPoint(1).y + surface[current_vertex_index].getPoint(2).y) / 2)-36);
}
//Come prima, non riporto i commenti, in quanto sono gli stessi, e cambiano solo gli HP del bunker
Bunker2::Bunker2(Texture *texture){
    HPMAX= 3;
    HP = HPMAX;
    shape.setTexture(*texture);
    shape.setScale(0.5f,0.5f);
}
int Bunker2::getHP(){
    return HP;
}
int Bunker2::getHPMAX() {
    return HPMAX;
}
void Bunker2::DannoSubito(){
    HP--;
}
void Bunker2::setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index){ // Posiziona i bunker sulla linea del terreno, mediante la formula del coefficiente angolare
    shape.setRotation((180 / M_PI) * (atan((surface[current_vertex_index].getPoint(2).y - surface[current_vertex_index].getPoint(1).y) /
    (surface[current_vertex_index].getPoint(2).x - surface[current_vertex_index].getPoint(1).x))));
    shape.setPosition((surface[current_vertex_index].getPoint(1).x + surface[current_vertex_index].getPoint(2).x) / 2,
    ((surface[current_vertex_index].getPoint(1).y + surface[current_vertex_index].getPoint(2).y) / 2)-36);
}
