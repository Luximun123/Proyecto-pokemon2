#ifndef ENTRENACABRA_H
#define ENTRENACABRA_H
#include <string>
#include "pokegod.h"

using namespace std;

class EntrenaCabra{

    private:
        string Nombre;
        int id;
        int cantidadPokemones;
        pokemones** equipo // el operador accede al valor que se guarda en la direccion

    
    
        int nesti; //vida
        int yamato_rebelion; // damage
        int Monster; // Velocidad
        int CQC; // Defensa
        int Minecraft2015; // experiencia

    public:
        EntrenaCabra(string nombre, int id , int cantidadPokemones);
        ~Entrenacabra();
    
        bool estasmuerto();
        void MostrarEquipo();
        void MostrarDatos();
        void Mochilla(int nesti, int yamato_rebelion, int Monster, int CQC, int Minecraft2015);

    
};

#endif 