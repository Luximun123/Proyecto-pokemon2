#ifndef ENTRENACABRA_H
#define ENTRENACABRA_H

#include <string>
#include "pokegod.h"

using namespace std;

class EntrenaCabra{

    private:
        string Nombre;
        int id;
        int const cantidadPokemones=3;
        int pokemonplay; // Índice del Pokemon activo
        
        pokemones* equipo[3]; // el operador accede al valor que se guarda en la direccion
        string mochila[5];
       
    public:
        EntrenaCabra(string nombre, int id , int  const cantidadPokemones, mochila mochilla);
        ~EntrenaCabra();
        
        bool estasmuerto();
        void MostrarEquipo();
        void MostrarDatos();

    Pokemones* obtenerActivo();
    string obtenerNombre();
    bool usarObjeto();
};


        void MostrarMochila();


#endif 