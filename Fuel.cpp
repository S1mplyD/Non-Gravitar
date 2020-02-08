#include "Fuel.h"
//Classe Fuel del primo tipo
Fuel::Fuel(Texture *texture) { //Costruttore
    shape.setTexture(*texture);
}
void Fuel::setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index){ // Posiziona i bunker sulla linea del terreno, mediante la formula del coefficiente angolare
    shape.setRotation((180 / M_PI) * (atan((surface[current_vertex_index].getPoint(2).y - surface[current_vertex_index].getPoint(1).y) /
    (surface[current_vertex_index].getPoint(2).x - surface[current_vertex_index].getPoint(1).x))));
    shape.setPosition((surface[current_vertex_index].getPoint(1).x + surface[current_vertex_index].getPoint(2).x) / 2,
    ((surface[current_vertex_index].getPoint(1).y + surface[current_vertex_index].getPoint(2).y) / 2)-41);
}
//Classe Fuel del secondo tipo
Fuel2::Fuel2(Texture *texture) { //Costruttore
    shape.setTexture(*texture);
}
void Fuel2::setpos(std::vector<sf::ConvexShape> surface, int current_vertex_index){ // Posiziona i bunker sulla linea del terreno, mediante la formula del coefficiente angolare
    shape.setRotation((180 / M_PI) * (atan((surface[current_vertex_index].getPoint(2).y - surface[current_vertex_index].getPoint(1).y) /
    (surface[current_vertex_index].getPoint(2).x - surface[current_vertex_index].getPoint(1).x))));
    shape.setPosition((surface[current_vertex_index].getPoint(1).x + surface[current_vertex_index].getPoint(2).x) / 2,
    ((surface[current_vertex_index].getPoint(1).y + surface[current_vertex_index].getPoint(2).y) / 2)-41);
}
