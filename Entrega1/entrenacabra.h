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
        int pokemonplay;
        pokemones* equipo[3]; // el operador accede al valor que se guarda en la direccion
        
       
    public:
        EntrenaCabra(string nombre, int id , int  const cantidadPokemones, mochila mochilla);
        ~EntrenaCabra();
        
        bool estasmuerto();
        void MostrarEquipo();
        void MostrarDatos();
        
};

class mochilla{
    private:
     
        int cantidad_objetos;
        string mochila_[5];
        /* 
        nesti; //vida
        yamato_rebelion; // damage
        Monster; // Velocidad
        CQC; // Defensa
        Minecraft2015; // experiencia vegeta777
        */
        
    public:
        mochila(int nesti, int yamato_rebelion, int Monster, int CQC, int Minecraft2015);

        void MostrarMochila();
        

};

#endif 