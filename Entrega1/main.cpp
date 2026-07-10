#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"
#include <cstdlib>
#include <fstream>
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


    cout<< "       BIENVENIDOS A MI BEST IN THE WORLD GAME MADE EVER, NOW IN GROUP ( AND ARCH)"<<endl;
    cout << "                               POKEMON2 MAY CRY REMAKE" <<endl<<endl<<endl;
//Pokemones y entrenadores

    EntrenaCabra *entrenador_1 = new EntrenaCabra("Arthur Morgan", 1889);
    EntrenaCabra *entrenador_2 = new EntrenaCabra("John Marston", 1911);
   

    entrenador_1->AgregarPokemon(p1,0);
    entrenador_1->AgregarPokemon(p2,1);
    entrenador_1->AgregarPokemon(p3,2);

    /*
    entrenador_2->AgregarPokemon(p4,0);
    entrenador_2->AgregarPokemon(p5,1);
    entrenador_2->AgregarPokemon(p6,2);
    */

    cargarEquipo(entrenador_1, entrenador_2); 

int opcion = 0;
    while (opcion != 5) {
        cout << "1. Ver equipo del entrenador 1\n"; 
		cout << "2. Ver equipo del entrenador 2\n"; 
		cout << "3. Iniciar batalla\n";
		cout << "4. Gestionar ficheros\n"; 
		cout << "5. Salir\n"; 

		cout << "Que opcion desea: ";
		cin >> opcion;


        if (opcion == 1) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            cout << "Operadores de el Agente 1"<<endl;
            entrenador_1->MostrarEquipo();
            entrenador_1->MostrarMochila();
            cout<<endl;
            cout << "Operadores de el Agente 2"<<endl;
            entrenador_2->MostrarEquipo();
            entrenador_2->MostrarMochila();


       

        } 
        else if (opcion == 2) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            Batalla Combate;
            Combate.inicio_combat(entrenador_1, entrenador_2);

            cout << "Iniciando batalla\n";        
        }
        //MENU NUEVO 

        else if (opcion == 4) {
			// SUBMENÚ DE GESTIÓN DE ARCHIVOS 
			int subOpcion = 0;
			while (subOpcion != 6) { // 6 para Volver 
				cout << "\n--- GESTION DE FICHEROS ---\n";
				cout << "1. Ver listado de Pokemon disponibles\n"; 
				cout << "2. Editar equipo actual\n"; 
				cout << "3. Guardar equipo a fichero\n"; 
				cout << "4. Cargar equipo desde fichero\n"; 
				cout << "5. Ver historial de batallas\n"; 
				cout << "6. Volver\n"; 
				cout << "Seleccione una opcion: ";
				cin >> subOpcion;
				
				if (subOpcion == 1) {
					leer_poke(); 
				}
				else if (subOpcion == 2) {
					// Le preguntamos al usuario a cual de los dos entrenadores quiere editarle el equipo
    				int cualEntrenador;
    				cout << "A que entrenador deseas editarle el equipo?\n1. " << entrenador_1->obtenerNombre() << "\n2. " << entrenador_2->obtenerNombre() << "\nSelección: ";
    				cin >> cualEntrenador;

    				if (cualEntrenador == 1) {
    				    entrenador_1-> editarEquipo(entrenador_1);  //por si falla colocar editarEquipo(entrenador_1)
    				} else if (cualEntrenador == 2) {
    				    entrenador_2-> editarEquipo(entrenador_2);
    				} else {
    			    cout << "Opción inválida.\n";
    				}
				}
				else if (subOpcion == 3) {
					guardar_equipo(entrenador_1, entrenador_2); 
				}
				else if (subOpcion == 4) {
					cargarEquipo(entrenador_1, entrenador_2); 
				}
				else if (subOpcion == 5) {
					Batalla.Historialbatallas();   // considerar cosas a faltar en esta linea 
                    

				}
			}
		}


  
        
    }
    delete entrenador_1;
    delete entrenador_2;

    return 0;
} // llave del main
