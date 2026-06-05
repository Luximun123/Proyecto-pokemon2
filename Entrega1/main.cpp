#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"

using namespace std;

int main(){

//PROMEIA >> CAPITANO
//BASURA >> CAPITANO
//Pokemones y entrenadores

    EntrenaCabra *entrenador_1 = new Entrenacabra("Arthur Morgan", 1889);
    EntrenaCabra *entrenador_2 = new Entrenacabra("John Marston", 1911);

                  //nombre, especie, tipo, vida ,salud, ataque, defensa, velocidad, nivel
    Pokemones *p1("Promeia",120,120,15,35,20,25);
    Pokemones *p2("Capitano, Humano, Fisico", 1000 , 1000 , 1000 , 999);
    Pokemones *p3("Solid snake, Humanoide","eter",);
    

    Pokemones *p4("Big Boss, Humanoide, Soldado", 1000 , 1000 , 1000 , 999);
    Pokemones *p5("Wonder of you , humanoide , stand");
    Pokemones *p6("Adam Smasher, robot, humanoide ");
 
    // asignar pokemones a entrenadoes 




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
