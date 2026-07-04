#ifndef ENTRENACABRA_H
#define ENTRENACABRA_H
#include <string>
#include "pokegod2.h"


class EntrenaCabra{

    private:
        std::string Nombre;
        int id;
        int const cantidadPokemones=3;
        int pokemonplay; // Pokemon activo
        
        Pokemones** equipo; // accede al valor que se guarda en la direccion

        std::string mochila[5];
        bool objetousado[5]; // Array para ver si cada objeto en la mochila ha sido usado
    
    public:
       
        EntrenaCabra(std::string nombre, int id);
        ~EntrenaCabra();
        
        int usarObjeto();
        bool cambiarPokemon();
        bool estasmuerto();
        bool usarObjetoCPU(int indice);
        void MostrarEquipo();
        void MostrarMochila();


        void AgregarPokemon(Pokemones* p, int posicion);  // FUNCION A TERMINAR

        // cambios nuevos 

        void guardar_equipo(EntrenaCabra* e1, EntrenaCabra* e2);
        
        void cargarEquipo(EntrenaCabra* e1, EntrenaCabra* e2);

        void editarEquipo(EntrenaCabra*entrenador);

        Pokemones* obtenerActivo();
        std::string obtenerNombre();
        Pokemones* obtenerPokemon(int indice);    
};

//prueba commit 




#endif 