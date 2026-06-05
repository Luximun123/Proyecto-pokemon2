#ifndef BATALLA_H
#define BATALLA_H

#include "pokegod2.h"
#include "entrenacabra.h"
#include <string>
using namespace std;

class Batalla {
    private:

    string opcion; // atacar , cambia pokemon , usar objeto 
    

    public:
    bool ganar(); // condicion para ganar la batalla
    void MostrarEstados(); // muestra los estados de los personajes
    evaluciondelcombate(); // evalua el combate y determina el ganador
    
};

#endif