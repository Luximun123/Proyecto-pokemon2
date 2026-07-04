#ifndef BATALLA_H
#define BATALLA_H
#include "entrenacabra.h"
#include <string>

class Batalla {
    private:

    float ventaja(std::string tipo_atacante, std::string tipo_defensor); // calcula la ventaja de un tipo sobre otro
    

    public:
 void inicio_combat(EntrenaCabra* Jugador, EntrenaCabra* cpu); // inicia la batalla

 void Historialbatallas();

 void GuardarHistorial(std::string Historial);

// commit prueba 
};

#endif