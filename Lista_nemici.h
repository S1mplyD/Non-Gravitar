#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Nemici.h"
#include <cstdlib>
#include <cmath>

struct Bunker_list{
    Bunker bunker;
    Bunker_list *next;
    Bunker_list *prev;
};

struct Bunker2_list{
    Bunker2 bunker2;
    Bunker2_list *next;
    Bunker2_list *prev;
};

typedef Bunker_list *B1;
typedef Bunker2_list *B2;

class Bunker1_set{
protected:
    B1 lista1;
public:
    Bunker1_set(){
        lista1=NULL;
    }
    void crea_lista(sf::Texture *texture){
        B1 tmp;
        srand(time(0));
        int n=(rand()%4)+1;
        for (int i=0; i<=n; i++){
            (tmp->bunker)=Bunker(texture);
            tmp->next=lista1;
        }
    }
    };

class Bunker2_set{
protected:
    B2 lista2;
public:
    Bunker2_set(){
        lista2=NULL;
    }
    void crea_lista(sf::Texture *texture){
        B2 tmp;
        srand(time(0));
        int n=(rand()%4)+1;
        for (int i=0; i<=n; i++){
           (tmp->bunker2)=Bunker2(texture);
            tmp->next=lista2;
        }
    }
    };
