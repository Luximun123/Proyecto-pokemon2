#ifndef BATALLA_H
#define BATALLA_H

#include "pokegod.h"
#include "entrenacabra.h"
#include <string>
using namespace std;

class Batalla {
    private:

    string opcion; // atacar , cambia pokemon , usar objeto 
    

    public:
    bool ganar(); // condicion para ganar la batalla
    void MostrarEstados(); // muestra los estados de los personajes
    
    
};

#endif