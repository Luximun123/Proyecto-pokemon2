#include "entrenacabra.h"
#include <iostream>
#include <fstream>
#include <string>
#include <randdom>
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

// CAMBIOS NUEVOS 

    void EntrenaCabra::guardar_equipo(EntrenaCabra* entrenador_1, EntrenaCabra* entrenador_2){
        ofstream archivoGuardar("equipos.txt");
            //entrenador 1

	    if (archivoGuardar.is_open()) {
		    archivoGuardar << "Arthur_Morgan "; 
		    for (int i = 0; i < 3; i++) {
			    Pokemones* p = e1->obtenerPokemon(i);
			    if (p != nullptr) {
				// Reemplazamos espacios por guiones bajos para que al leer no se rompa		               
				    string nombrePoke = p->obtenerNombre();
				    for(size_t j = 0; j < nombrePoke.length(); j++) {
					    if(nombrePoke[j] == ' ') nombrePoke[j] = '_';
				    }
				    archivoGuardar << nombrePoke << " ";
			    } 
			    else {
				    archivoGuardar << "Ninguno " << endl; // Por si no tiene un pokemon en esa ranura
			    }
		    }
		    archivoGuardar << endl; 
		
		       //entrenador 2

		    archivoGuardar << "John_Marston ";
		    for (int i = 0; i < 3; i++) {
			    Pokemones* p = e2->obtenerPokemon(i);
			    if (p != nullptr) {
			           	
				    string nombrePoke = p->obtenerNombre();
				    for(size_t j = 0; j < nombrePoke.length(); j++) {
					    if(nombrePoke[j] == ' ') nombrePoke[j] = '_';
				    }
				    archivoGuardar << nombrePoke << " ";
			    } 
			    else {
				    archivoGuardar << "Ninguno " << endl;
			    }
		    }
		    archivoGuardar << endl;
		
		    archivoGuardar.close();
		    cout << "Equipos guardados con éxito" << endl;
	    } 
	    else {
		    cout << "Error: No se pudo abrir el archivo para guardar los equipos" << endl;
	    }
}

// EQUIPO DE LA CPU
void EntrenaCabra::equipoCPU(EntrenaCabra* e2, EntrenaCabra* e1){

    int cantPokemon=0 ;
    string lineas;

    ifstream archivoPokemon("pokemon_pool.txt");
    if(!archivoPokemon.is_open()){
        cout<< "no se encuentra el archivo" <<endl;
        return;
    }
        while(getline(archivoPokemon,lineas)){  //leer cada linea del archivo
            cantPokemon++;
        }
        //pokemon aleatorio
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> lista(0, cantPokemon-1);

        // comprobar que no repita pokemones del jugador 

        for(int i=0; i<3; i++){
            Pokemones* poke;
            bool repetido = true;
            while(repetido){
                repetido = false;
                poke = buscarPokemon(obtenerNombre(lista(gen)));

                for(int j=0; j<3;j++){

                    if(e1->obtenerPokemon(j) != nullptr && e1->obtenerPokemon(j)->obtenerNombre() == poke->obtenerNombre()){
                        repetido = true;
                        
                    }
                }

                //comprobar que no se repita pokemon la cpu
                for(int k=0; k<3; k++){
                    if(e2->obtenerPokemon(k) != nullptr && e2->obtenerPokemon(k)->obtenerNombre() == poke->obtenerNombre()){    
                    }
                     repetido = true;             
                }
                if (poke != nullptr) 

              // asignar pokemones aleatorio al segundo entrenador 
                e2->AgregarPokemon(poke, i);
            }

        }
archivoPokemon.close();
}


void EntrenaCabra::cargarEquipo(EntrenaCabra* e1, EntrenaCabra* e2) {
	ifstream archivoCargar("equipos.txt");
	if (!archivoCargar.is_open()) {
		cout << "\n>> Error: No se encontró el archivo 'equipos.txt'" << endl;
		return;
	}
	
	string nombreEntrenador;
	string p1, p2, p3;

	//Entrenador 1
	if (archivoCargar >> nombreEntrenador >> p1 >> p2 >> p3) {
        // Buscamos y creamos los pokemones correspondientes

        //NOTA: En caso de haber error aqui cambia "buscarPokemon" a  "buscarYCrearPokemon"


        Pokemones* poke1 = buscarPokemon(p1);
        Pokemones* poke2 = buscarPokemon(p2);
        Pokemones* poke3 = buscarPokemon(p3);               
        // Los asignamos a las ranuras 0, 1 y 2
        if (poke1 != nullptr) e1->AgregarPokemon(poke1, 0);
        if (poke2 != nullptr) e1->AgregarPokemon(poke2, 1);
        if (poke3 != nullptr) e1->AgregarPokemon(poke3, 2);
    }

	//Entrenador 2
	if (archivoCargar >> nombreEntrenador >> p1 >> p2 >> p3) {

        equipoCPU(e2,e1)


		// Buscamos y creamos los pokemones correspondientes
    /*    
		Pokemones* poke1 = buscarPokemon(p1);
		Pokemones* poke2 = buscarPokemon(p2);
		Pokemones* poke3 = buscarPokemon(p3);
		
		if (poke1 != nullptr) e2->AgregarPokemon(poke1, 0);
		if (poke2 != nullptr) e2->AgregarPokemon(poke2, 1);
		if (poke3 != nullptr) e2->AgregarPokemon(poke3, 2);
        */
	}
	
	archivoCargar.close();
	cout << "\n Equipos cargados exitosamente desde el archivo";
}
    

    void EntrenaCabra::editarEquipo(EntrenaCabra* entrenador) {
    cout << "\n EDITAR EQUIPO DE " << entrenador->obtenerNombre() << endl;
    entrenador->MostrarEquipo(); // Mostramos el equipo actual para que vea los indices (0, 1, 2)
    
    int posicion;
    cout << "Que posicion de tu equipo deseas cambiar? (0, 1 o 2): ";
    cin >> posicion;

    if (posicion < 0 || posicion > 2) {
        cout << " Posición invalida. Debe ser 0, 1 o 2.\n";
        return;
    }

    
    cout << "\nCargando pokemones disponibles desde el pool...\n";
    leer_poke(); // Reutilizamos la función de listar el pool que hicieron al principio

    string nombreElegido;
    cout << "\nEscribe el nombre EXACTO del Pokemon que deseas integrar: ";
    cin >> nombreElegido;

    // Buscamos y creamos el nuevo Pokemon usando la funcion auxiliar
    Pokemones* nuevoPoke = buscarPokemon(nombreElegido);

    if (nuevoPoke != nullptr) {
        // Asignamos el nuevo objeto en la posición seleccionada
        entrenador->AgregarPokemon(nuevoPoke, posicion);
        cout << "\n " << nombreElegido << " ha sido asignado con exito a la posicion " << posicion << "\n";
    } else {
        cout << "\n Error: No se encontro ningun Pokemon con ese nombre en el pool" << endl;
    }
}




