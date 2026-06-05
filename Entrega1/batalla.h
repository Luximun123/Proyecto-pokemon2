#ifndef BATALLA_H
#define BATALLA_H
#include "entrenacabra.h"
#include <string>
using namespace std;

class Batalla {
    private:

    float ventaja(string tipo_atacante, string tipo_defensor); // calcula la ventaja de un tipo sobre otro
    

    public:
 void inicio_combat(EntrenaCabra* Jugador, EntrenaCabra* cpu); // inicia la batalla
};

#endif