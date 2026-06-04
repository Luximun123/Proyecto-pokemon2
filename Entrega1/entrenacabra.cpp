#include "entrenacabra.h"
#include <iostream>
using namespace std;


    entrenacabra::entrenacabra(string nombre, int id,  int  const cantidadPokemones, mochilla mochila);

    equipo = new *pokemones[cantidadPokemones];
    pokemon_activo = 0;
    pokemonplay = 0;

    void entrenacabra::MostrarEquipo(){
        for(int i=0 ; i<cantidadPokemones; i++){
            i+1;
        cout << "Pokemon "  << ": " << equipo[i] << endl;
        }
    }

    void entrenacabra::MostrarMochila(){
        for(int i=0 ; i<5; i++){
            i+1;
        cout << "Objeto "  << ": " << mochila[i] << endl;
        }
    }

mochila [0]={"nesti"};
mochila [1]= {"yamato_rebelion"};
mochila [2]= {"Monster"};
mochila [3]= {"CQC"};
mochila [4]= {"Minecraft2015"};
