#include "entrenacabra.h"
#include <iostream>
using namespace std;


    EntrenaCabra::EntrenaCabra(string nombre, int id_num){
        Nombre=nombre;
        id = id_num;
        equipo = new Pokemones*[cantidadPokemones];
        pokemonplay = 0;

    for(int i=0 ; i<cantidadPokemones; i++){
        equipo[i]=nullptr;
    }
    
}
    void EntrenaCabra::MostrarEquipo(){
        cout << "/n     Equipo de " << Nombre << ":" << endl;
        for(int i=0 ; i<cantidadPokemones; i++){
            i+1;
        cout << "Pokemon " << i+1 << ": " << equipo[i] << endl;
        }
    }
    
    void EntrenaCabra::MostrarMochila(){
        cout << "/n     Mochila de: " << endl;
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
mochila [0]= "nesti";
mochila [1]= "yamato_rebelion";
mochila [2]= "Monster";
mochila [3]= "CQC";
mochila [4]= "Minecraft2015";
