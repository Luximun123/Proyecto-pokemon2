#include <iostream>
#include <string>
#include "entrenacabra.h"
#include "batalla.h"
#include <cstdlib>
#include <fstream>
#include <cstdio>
using namespace std;

// Función para limpiar la pantalla
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función mejorada para pausar
void pausarPantalla() {
    cout << "\n";
    #ifdef _WIN32
        system("pause"); 
    #else
        cout << "Presiona ENTER para continuar...";
        cin.clear();
        cin.ignore(10000, '\n');
        cin.get();
    #endif
}

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
   

    entrenador_1->cargarEquipo(entrenador_1, entrenador_2); 

	// Verificar si los equipos están vacíos (si no se cargó nada)
bool equipo1Vacio = true, equipo2Vacio = true;
for (int i = 0; i < 3; i++) {
    if (entrenador_1->obtenerPokemon(i) != nullptr) equipo1Vacio = false;
    if (entrenador_2->obtenerPokemon(i) != nullptr) equipo2Vacio = false;
}

if (equipo1Vacio || equipo2Vacio) {
    cout << "No se encontró equipos.txt, creando equipos por defecto...\n";

    entrenador_1->AgregarPokemon(buscarPokemon("Promeia"), 0);
    entrenador_1->AgregarPokemon(buscarPokemon("Capitano"), 1);
    entrenador_1->AgregarPokemon(buscarPokemon("Solid_Snake"), 2);

    entrenador_1->EquipoCPU(entrenador_2, entrenador_1);

    entrenador_1->guardar_equipo(entrenador_1, entrenador_2);
}

pausarPantalla();
	
int opcion = 0;
    while (opcion != 5) {

    limpiarPantalla();
        cout << "\n    MENU PRINCIPAL  \n";
        cout << "1. Ver equipo del entrenador 1\n"; 
		cout << "2. Ver equipo del entrenador 2\n"; 
		cout << "3. Iniciar batalla\n";
		cout << "4. Gestionar ficheros\n"; 
		cout << "5. Salir\n"; 

		cout << "Que opcion desea: ";
		cin >> opcion;
        cout << endl << endl;

        if (opcion == 1) {
            cout << "Operadores de el Agente 1 "<< entrenador_1->obtenerNombre() <<endl;
            entrenador_1->MostrarEquipo();
            entrenador_1->MostrarMochila();
            pausarPantalla();
        } 
        else if (opcion == 2) {
            cout << "Operadores de el Agente 2 "<< entrenador_2->obtenerNombre() <<endl;
            entrenador_2->MostrarEquipo();
            entrenador_2->MostrarMochila();
            pausarPantalla();
        } 
        else if (opcion == 3) {
            Batalla Combate;
            Combate.inicio_combat(entrenador_1, entrenador_2);
            cout << "Iniciando batalla\n";   
            pausarPantalla();  

        }
        //MENU NUEVO 

        else if (opcion == 4) {
			// SUBMENÚ DE GESTIÓN DE ARCHIVOS 
			int subOpcion = 0;
			while (subOpcion != 7) { 
                limpiarPantalla();

				cout << "\n--- GESTION DE FICHEROS ---\n";
				cout << "1. Ver listado de Pokemon disponibles\n"; 
				cout << "2. Editar equipo actual\n"; 
				cout << "3. Guardar equipo a fichero\n"; 
				cout << "4. Cargar equipo desde fichero\n"; 
				cout << "5. Ver historial de batallas\n"; 
                cout << "6. Eliminar guardados\n";
				cout << "7. Volver\n"; 
				cout << "Seleccione una opcion: ";
				cin >> subOpcion;
				cout << endl << endl;

                limpiarPantalla();

				if (subOpcion == 1) {
					Leer_poke(); 
                    pausarPantalla();
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
                    pausarPantalla();
				}
				else if (subOpcion == 3) {
					entrenador_1->guardar_equipo(entrenador_1, entrenador_2); 
                    pausarPantalla();
				}
				else if (subOpcion == 4) {
					entrenador_1->cargarEquipo(entrenador_1, entrenador_2); 
                    pausarPantalla();
				}
				else if (subOpcion == 5) {
					Batalla batallaTemp;
					batallaTemp.Historialbatallas();   
                    pausarPantalla();

				}
                else if (subOpcion == 6) {   // <--- NUEVO CASO: BORRAR EQUIPO
                    char confirmar;
                        cout << "¿Estás seguro de que quieres borrar el último equipo guardado? (s/n): ";
                        cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S') {
                        if (remove("equipos.txt") == 0) {
                            cout << "\nArchivo 'equipos.txt' borrado correctamente.\n";
                            cout << "Los equipos actuales no se ven afectados, pero la próxima vez que cargues se generarán aleatorios.\n";
                       } 
                       else {
                            cout << "\nNo se encontró el archivo 'equipos.txt' para borrar.\n";
                       }
                    } 
                    else {
                        cout << "\nOperación cancelada.\n";
                    }

                    pausarPantalla();
                }
        // subOpcion == 7 -> sale del while
    

			}
		}


  
        
    }
    delete entrenador_1;
    delete entrenador_2;

    return 0;
} // llave del main
