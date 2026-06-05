#ifndef ENTRENACABRA_H
#define ENTRENACABRA_H

#include <string>
#include "pokegod2.h"

using namespace std;

class EntrenaCabra{

    private:
        string Nombre;
        int id;
        int const cantidadPokemones=3;
        int pokemonplay; // Pokemon activo
        int posicion;
        
        Pokemones** equipo; // accede al valor que se guarda en la direccion

        string mochila[5];
       
        bool objetousado[5]; // Array para ver si cada objeto en la mochila ha sido usado
    
    public:
       
        EntrenaCabra(string nombre, int id);
        ~EntrenaCabra();
        
        bool cambiarPokemon();
        bool usarObjeto();
        bool estasmuerto();
        void MostrarEquipo();
        void MostrarDatos();
        void MostrarMochila();


        void AgregarPokemon(Pokemones*, int posicion);  // FUNCION A TERMINAR
    


        Pokemones* obtenerActivo();
        string obtenerNombre();
    
};





#endif 