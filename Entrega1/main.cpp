#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"

using namespace std;

int main(){


    cout << R"(
⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟⠁
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿⠀⠀⠀⠀
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀
)" <<endl;




    cout<< "       BIENVENIDOS A MI BEST IN THE WORLD GAME MADE EVER, NOW IN GROUP ( AND ARCH)\n                   POKEMON2 MAY CRY REMAKE";
//Pokemones y entrenadores

    EntrenaCabra *entrenador_1 = new EntrenaCabra("Arthur Morgan", 1889);
    EntrenaCabra *entrenador_2 = new EntrenaCabra("John Marston", 1911);

   
                             //nombre, especie, tipo, vida ,salud, ataque, defensa, velocidad, nivel
    Pokemones *p1 =new Pokemones("Promeia","Humano","Hielo",120, 120, 15, 35, 20, 1);
    Pokemones *p2 =new Pokemones("Capitano", "Humano", "Fisico", 150 , 150 , 50 ,30, 20, 1);
    Pokemones *p3 =new Pokemones("Solid snake", "Humanoide", "eter", 80 , 80 , 40 , 20, 30, 1);

    Pokemones *p4 =new Pokemones("Big Boss", "Humanoide", "Soldado", 100 , 100 , 100 , 50, 40,1);
    Pokemones *p5 =new Pokemones("Wonder of you ", "humanoide" , "eter", 80 , 80 , 20 , 40,30, 1);
    Pokemones *p6 =new Pokemones("Adam Smasher", "robot" , "electrico", 200 , 200 , 30 , 50, 20, 1);
 
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
