#include "entrenacabra.h"
#include <iostream>
using namespace std;


    entrenacabra::entrenacabra(string nombre, int id , mochilla mochila){

    equipo = new *pokemones[cantidadPokemones];
    pokemon_activo = 0;
    pokemonplay = 0;

    for(int i=0 ; icantidadPokemones; i++){
        equipo[i]=nullptr;
    }
    
}
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

    bool EntrenaCabra::usarObjeto() {
        int opcion;
        MostrarMochila();

        cin >> opcion;
        if (opcion >= 1 && opcion <= 5) {
            cout << "Has usado el objeto: " << mochila[opcion - 1] << endl;
            return true;
        } else {
            cout << "Opción inválida." << endl;
            return false;
        }

        Pokemones* p = obtenerActivo();

        

    }
mochila [0]={"nesti"};
mochila [1]= {"yamato_rebelion"};
mochila [2]= {"Monster"};
mochila [3]= {"CQC"};
mochila [4]= {"Minecraft2015"};
