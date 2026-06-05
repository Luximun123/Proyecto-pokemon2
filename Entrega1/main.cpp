#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"

using namespace std;

int main(){

//Pokemones y entrenadores

    EntrenaCabra *entrenador_1 = new EntrenaCabra("Arthur Morgan", 1889);
    EntrenaCabra *entrenador_2 = new EntrenaCabra("John Marston", 1911);

                  //nombre, especie, tipo, vida ,salud, ataque, defensa, velocidad, nivel
    Pokemones *p1("Promeia",120,120,15,35,20,25);
    Pokemones *p2("Capitano, Humano, Fisico", 1000 , 1000 , 1000 , 999);
    Pokemones *p3("Solid snake, Humanoide","eter",);
    Pokemones *p4("Big Boss, Humanoide, Soldado", 1000 , 100 , 1000 , 999);
    

    Pokemones *p4("Big Boss, Humanoide, Soldado", 1000 , 1000 , 1000 , 999);
    Pokemones *p5("Wonder of you , humanoide , stand");
    Pokemones *p6("Adam Smasher, robot, humanoide ");
 
    // asignar pokemones a entrenadoes 


     // TERMINAR EL CODIGO Y QUE FFUNCIOONE CORRECTAMENTE
    entrenador_1->AgregarPokemon(p1,0);
    entrenador_1->AgregarPokemon(p2,1);
    entrenador_1->AgregarPokemon(p3,2);

    entrenador_2->AgregarPokemon(p4,0);
    entrenador_2->AgregarPokemon(p5,1);
    entrenador_2->AgregarPokemon(p6,2);
    



int opcion = 0;
    while (opcion != 3) {
        cout << "\n    Menu de pokemon 2    \n1. Ver equipos y la mochila\n2. Batalla\n3. Salir\nQue desea: ";
        cin >> opcion;

        if (opcion == 1) {
            entrenador_1->MostrarEquipo();
            entrenador_1->MostrarMochila();

            entrenador_2->MostrarEquipo();
            entrenador_2->MostrarMochila();
        } else if (opcion == 2) {
            
            cout << "Iniciando batalla\n";
            // poner la funcion de la batalla             
        }


    delete entrenador_1;
    delete entrenador_2;
    return 0;

        
    }
} // llave del main
