#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"

using namespace std;

int main(){
    
//Pokemones y entrenadores

    Entrenacabra *entrenador_1 = new Entrenacabra("Arthur Morgan", 1889);
    Entrenacabra *entrenador_2 = new Entrenacabra("John Marston", 1911);


    Pokemones *p1("fuego")
    Pokemones *p2("")
    Pokemones *p3("")

    Pokemones *p4("")
    Pokemones *p
    Pokemones



int opcion = 0;
    while (opcion != 3) {
        cout << "\n    Menu de pokemon 2    \n1. Ver equipos y la mochila\n2. Batalla\n3. Salir\nQue desea: ";
        cin >> opcion;

        if (opcion == 1) {
            entrenador1->mostrarEquipo();
            entrenador1->MostrarMochila();

            entrenador2->mostrarEquipo();
            entrenador2->MostrarMochila();
        } else if (opcion == 2) {
            
            cout << "Iniciando batalla\n";
            // poner la funcion de la batalla             
        }


    delete entrenador1;
    delete entrenador2;
    return 0;

        
    }
} // llave del main