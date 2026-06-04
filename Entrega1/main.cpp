#include <iostream>
#include "entrenacabra.h"
#include "batalla.h"
#include "batalla.h"

using namespace std;

int main(){
    string jugador1;

    cout << "Ingrese el nombre de su entrenador ";
    cin >> jugador1;

    Entrenacabra entrenador1(jugador1);
    Entrenacabra entrenador2("Misty");

int opcion = 0;
    while (opcion != 3) {
        cout << "\n    Menu de pokemon 2    \n1. Ver equipos\n2. Batalla\n3. Salir\nQue desea: ";
        cin >> opcion;

        if (opcion == 1) {
            entrenador1->mostrarEquipo();
            mochila_1->MostrarMochila();


            entrenador2->mostrarEquipo();
            mochila_2->MostrarMochila();
        } else if (opcion == 2) {
            
            
            break
        }

    return 0;

        
}