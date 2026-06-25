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
        mochila [0]= "nesti (80 HP)";
        mochila [1]= "yamato_rebelion (40 ATK)";
        mochila [2]= "Monster (40 SPD/CRIT)";
        mochila [3]= "CQC (40 DEF)";
        mochila [4]= "Minecraft2015 (1 nivel)";

        for(int i = 0 ; i < 5; i++){
            objetousado[i] = false;
        }
    }

    EntrenaCabra::~EntrenaCabra() {
        for(int i=0 ; i<cantidadPokemones; i++){
            if (equipo[i] != nullptr){
                delete equipo[i];
            }
        }
        delete[] equipo;
    }

    void EntrenaCabra::AgregarPokemon(Pokemones* p, int posicion) {
        if (posicion >= 0 && posicion < cantidadPokemones) {
            equipo[posicion] = p;
        }
    }


    string EntrenaCabra::obtenerNombre() { return Nombre; }

    Pokemones* EntrenaCabra::obtenerActivo() { 
            return equipo[pokemonplay]; 
    }

    Pokemones* EntrenaCabra::obtenerPokemon(int indice) {
        if (indice >= 0 && indice < cantidadPokemones) return equipo[indice];
            return nullptr;
    }

    bool EntrenaCabra::estasmuerto() {
        for (int i = 0; i < cantidadPokemones; i++) {
            if (equipo[i] != nullptr && !equipo[i]->estaDebilitado()) {
                return false; 
            }
        }
         return true; 
    }

    void EntrenaCabra::MostrarEquipo(){
        cout << "\n     Equipo de " << Nombre << ":" << endl;
        for(int i=0 ; i<cantidadPokemones; i++){
            if(equipo[i] != nullptr) {
                cout << i << ". " << equipo[i]->obtenerNombre() << " (HP: " << equipo[i]->getVida() << "/" << equipo[i]->getSalud() << ")" << endl;
            }
        }
    }

    bool EntrenaCabra::usarObjetoCPU(int indice) {
    if (indice >= 0 && indice <= 4) {
        if (!objetousado[indice]) {
            objetousado[indice] = true;
            return true; 
        }
    }
    return false; 
}
    
    void EntrenaCabra::MostrarMochila(){
        cout << "\n     Mochila de " << Nombre << ":" << endl;
            for(int i = 0 ; i < 5; i++){
                cout << i << ". " << mochila[i];
                if (objetousado[i]) cout << " [AGOTADO]";
                cout << endl;
    }
}
    int EntrenaCabra::usarObjeto() {
        int indice;
        MostrarMochila();
        cout << "Selecciona el indice del dispositivo a usar: ";
        cin >> indice;

        if (indice >= 0 && indice <= 4) {

            if(objetousado[indice]) {
            cout << "Ya has usado el objeto: " << objetousado[indice] << endl;
            return -1;

            }else {

            objetousado[indice] = true;
                return indice;
            }

        }else {

        cout << "Opción inválida." << endl;
            return -1;
        }
    }



    bool EntrenaCabra::cambiarPokemon() {
    MostrarEquipo();
    cout << "Selecciona el indice del nuevo agente (0-2): ";
    int nuevaPos;
    cin >> nuevaPos;
    
    if (nuevaPos >= 0 && nuevaPos < cantidadPokemones) {
        if (equipo[nuevaPos] != nullptr && !equipo[nuevaPos]->estaDebilitado()) {
            pokemonplay = nuevaPos; 
            cout << ">> Entrando al campo: " << equipo[pokemonplay]->obtenerNombre() << "\n";
            return true;
        } else {
            cout << " Ese agente esta debilitado o no existe.\n";
            return false;
        }
    }
    cout << "Indice invalido.\n";
    return false;
}





