#include "batalla.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include "sprites.h"
#include "partidas.h"
using namespace std;

float Batalla::ventaja(string tipo_atacante, string tipo_defensor){
    // Ventajas: Fuego > Hielo > Electrico > Eter > Fisico > Fuego
    if (tipo_atacante == "Fuego" && tipo_defensor == "Hielo") return 1.5;
    if (tipo_atacante == "Hielo" && tipo_defensor == "Electrico") return 1.5;
    if (tipo_atacante == "Electrico" && tipo_defensor == "Eter") return 1.5;
    if (tipo_atacante == "Eter" && tipo_defensor == "Fisico") return 1.5;
    if (tipo_atacante == "Fisico" && tipo_defensor == "Fuego") return 1.5;
    
    // Desventajas
    if (tipo_atacante == "Hielo" && tipo_defensor == "Fuego") return 0.5;
    if (tipo_atacante == "Electrico" && tipo_defensor == "Hielo") return 0.5;
    if (tipo_atacante == "Eter" && tipo_defensor == "Electrico") return 0.5;
    if (tipo_atacante == "Fisico" && tipo_defensor == "Eter") return 0.5;
    if (tipo_atacante == "Fuego" && tipo_defensor == "Fisico") return 0.5;
    
    // Daño normal
    return 1.0;
}

// Ciclo principal para el combate
bool Batalla::inicio_combat(EntrenaCabra* jugador, EntrenaCabra* cpu, int indice_jugador, int indice_cpu){
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> probabilidad(1, 100);
    
    cout << "\n";
    cout << "  INICIANDO SIMULACION DE COMBATE" << endl;
    cout << "  PROXIES EN LA SIMULACION: " << jugador->obtenerNombre() << " VS " << cpu->obtenerNombre() << endl;
    
    // Obtenemos los agentes activos iniciales usando las flechas (->)
    Pokemones* cabraJugador = jugador->obtenerPokemon(indice_jugador);
    Pokemones* cabraCpu = cpu->obtenerPokemon(indice_cpu);
    
     //variables temporales para los buffs de ataque, defensa y critico
    int buffAtaque = 0, buffDefensa = 0, buffCritico = 0;

    while(!jugador->estasmuerto() && !cpu->estasmuerto()){

        // Control por si nuestro agente es eliminado 
        if(cabraJugador->estaDebilitado()){
            cout << "El agente " << cabraJugador->obtenerNombre() << " sufrio demasiado. Solicitando relevo" << endl;
            
            // El do-while maneja todo el flujo de entrada de forma limpia
            do {
                jugador->MostrarEquipo();
                cout << "Selecciona el indice del nuevo agente a desplegar: ";
                cin >> indice_jugador;
                cabraJugador = jugador->obtenerPokemon(indice_jugador);
                
                // Validacion por si metes un numero invalido o un agente muerto
                if(cabraJugador == nullptr || cabraJugador->estaDebilitado()) {
                    if (!jugador->estasmuerto()) {
                        cout << "Indice invalido o agente sin energia vital. Elige otro\n" << endl;
                    }
                }
            } while((cabraJugador == nullptr || cabraJugador->estaDebilitado()) && !jugador->estasmuerto());
            jugador->setIndiceActivo(indice_jugador);  // <--- AÑADIR
            continue;
        }
        
        // Control por si el agente enemigo es eliminado
        if(cabraCpu->estaDebilitado()){
            cout << "\n El agente enemigo " << cabraCpu->obtenerNombre() << " fue ELIMINADO" << endl;
            cabraJugador->subirNivel();

         if(!cpu->estasmuerto()) {

            for (int k = 0; k < 3; k++) {
                Pokemones* temp = cpu->obtenerPokemon(k);
                if (temp != nullptr && !temp->estaDebilitado()) {
                    indice_cpu = k;
                    cabraCpu = temp;
                    cpu->setIndiceActivo(indice_cpu);
                    cout << ">> El rival despliega a su siguiente agente: " << cabraCpu->obtenerNombre() << endl;
                    break;
                }
            }
        }
        
        continue;

        }
        
        // Interfaz de estado
        Pokemones* pJugador = jugador->obtenerPokemon(indice_jugador);
        Pokemones* pCpu = cpu->obtenerPokemon(indice_cpu);
        if (pJugador && pCpu) {
            mostrarSpritesEnBatalla(pJugador, pCpu); // Muestra los sprites lado a lado
        }

        cout << "\n";
        cout << " TU AGENTE:  " << cabraJugador->obtenerNombre() << " [" << cabraJugador->obtenerTipo() << "] | Vida: " << cabraJugador->getVida() << endl;
        cout << " RIVAL CPU:  " << cabraCpu->obtenerNombre() << " [" << cabraCpu->obtenerTipo() << "] | Vida: " << cabraCpu->getVida() << endl;
        cout << endl;
        // Mini Menu para las opciones del proxy
        cout << "\n1. Ejecutar Ataque Basico / Especial" << endl;
        cout << "2. Desplegar Gadget (Mochila) " << endl;
        cout << "3. Relevo Tactico (Cambiar Agente) " << endl;
        cout << "4. Guardar Partida y Salir" << endl <<endl;
        cout << "Selecciona tu comando: ";
        int opcion;
        cin >> opcion;
        
        bool turno_valido = false;
        cout<<"\n";

        if(opcion == 1){
            cout << "\n----------------------------------------" << endl;
            // Logica para el dano de los atributos
            float multiplicador = ventaja(cabraJugador->obtenerTipo(), cabraCpu->obtenerTipo());
            int danio = ((cabraJugador->getAtaque() + buffAtaque) - (cabraCpu->getDefensa() / 2)) * multiplicador;
            if (danio <= 0) danio = 1; // Para que no cure si la defensa es muy alta
            
            if (probabilidad(gen) < (cabraJugador->getVelocidad()/10 + buffCritico)) {
                danio *= 1.5; cout << "ANOMALIA APLICADA: EFECTO CRITICO POR VELOCIDAD\n";
            }
            cabraCpu->recibirGolpes(danio);
            cout << "\n>> " << cabraJugador->obtenerNombre() << " golpea con atributo " << cabraJugador->obtenerTipo();
            
            if(multiplicador > 1.0) cout << " (El enemigo es debil a este atributo) ";
            if(multiplicador < 1.0) cout << " (El enemigo resistio parcialmente el atributo) ";
            cout << "\n Daño infligido: " << danio << endl;
            
            turno_valido = true;
            buffAtaque = 0;
            buffCritico = 0;

        }
        else if (opcion == 2) {
            int item_usado = jugador->usarObjeto(); 

             if (item_usado == -1) {
            cout << "No se pudo usar el objeto.\n";
            turno_valido = false; // no gasta turno
            } else {
            if (item_usado == 0) { cabraJugador->curar(80); cout << ">> Tomaste Nesti y recuperaste 80 HP.\n"; turno_valido = true; }
            else if (item_usado == 1) { buffAtaque = 40; cout << ">> ¡Yamato Rebelion! Ataque masivo por este turno.\n"; turno_valido = true; }
            else if (item_usado == 2) { buffCritico = 40; cout << ">> ¡Bebiste Monster! Probabilidad de critico disparada este turno.\n"; turno_valido = true; }
            else if (item_usado == 3) { buffDefensa = 40; cout << ">> ¡CQC Activo! Defensa impenetrable este turno.\n"; turno_valido = true; }
            else if (item_usado == 4) { cabraJugador->subirNivel(); turno_valido = true; }
            }
        }
        else if (opcion == 3) {
            // Cambio de agente voluntario
            jugador->MostrarEquipo();
            cout << "Selecciona el indice del agente para el relevo: ";
            int nuevoIndice;
            cin >> nuevoIndice;
            
            Pokemones* nuevoPokemon = jugador->obtenerPokemon(nuevoIndice);

            if (nuevoIndice != indice_jugador && nuevoPokemon != nullptr && !nuevoPokemon->estaDebilitado()) {
                indice_jugador = nuevoIndice;
                jugador->setIndiceActivo(nuevoIndice);
                cabraJugador = nuevoPokemon;
                cout << "\n >> ¡Entrando al campo de batalla! " << cabraJugador->obtenerNombre() << endl;
                turno_valido = true;
            } else {
                cout << "Relevo invalido o agente sin energia. Intenta de nuevo." << endl;
            }
        }
        else if (opcion == 4) { 
            
            cout << "\nGuardando el estado actual de la batalla..." << endl;
   
            // Guardamos pasando 'true' en batallaActiva, y mandando los índices de los Pokémon actuales
            if (guardarPartida(jugador, cpu, true, indice_jugador, indice_cpu)) {
                cout << "¡Partida guardada correctamente en 'partida.bin'!" << endl;
                cout << "Saliendo al menu principal..." << endl;
            } else {
                cout << "Error al intentar guardar la partida." << endl;
            }
            return false; // Salimos inmediatamente de la función de combate regresando al menú principal
        }
        // Turno de la CPU
        if (turno_valido && !cabraCpu->estaDebilitado()){
            cout << "\n----------------------------------------" << endl;
            cout << "\n [TURNO ENEMIGO - CPU]" << endl << endl;
            
                bool securo = false; // variable para saber si la CPU uso un objeto de la mochila

                // decision de la CPU para usar objetos o atacar
            if (cabraCpu->getVida() < (cabraCpu->getSalud() / 2)) {

                if (probabilidad(gen) > 50 && cpu->usarObjetoCPU(0)) {

                    cabraCpu->curar(80);
                    cout << ">> El enemigo usa un nesti y recupera 80 HP." << endl;
                    securo = true;
                }
            }
            

            if (!securo) {
            float multCpu = ventaja(cabraCpu->obtenerTipo(), cabraJugador->obtenerTipo());
            int danioCpu = (cabraCpu->getAtaque() - ((cabraJugador->getDefensa() + buffDefensa) / 2)) * multCpu;
            if (danioCpu <= 0) danioCpu = 1;
           
            // Calculando critico de la CPU
            if (probabilidad(gen) < cabraCpu->getVelocidad()/10) {
                danioCpu *= 1.5;
                cout << "CRITICO DEL ENEMIGO\n";
            }

            cabraJugador->recibirGolpes(danioCpu);
         
           cout << ">> " << cabraCpu->obtenerNombre() << " contraataca. Daño recibido en tu agente: " << danioCpu << endl;            
        }
        cout << "\n\n----------------------------------------" << endl;
        buffDefensa = 0;
        }
    
    }
    
    // Evaluacion final del combate
     // Evaluacion final del combate
    cout << "\n";
    string resultado;
    if (!jugador->estasmuerto()){
        cout << "  WIPEOUT! Enemigos eliminados. Victoria Proxy! " << endl;
        resultado = "Victoria de " + jugador->obtenerNombre() + " contra " + cpu->obtenerNombre();
    } else {
        cout << "  MISION FALLIDA. Todos tus agentes han sido eliminados. " << endl;
        resultado = "Victoria de " + cpu->obtenerNombre() + " contra " + jugador->obtenerNombre();
    }

    GuardarHistorial(resultado);
    guardarPartida(jugador, cpu, false, 0, 0);
    return true; // Retornamos true para indicar que la batalla terminó y no se guardó en medio
}
// CAMBIOS NUEVOS 

    void Batalla::Historialbatallas() {  // Leer y mostrar historial de batalla 
	    string linea;
	
        ifstream leer_historial("historial.txt");

	    if(leer_historial.is_open()){
		    cout << "     HISTORIAL DE BATALLAS     " << endl;
		
		    while (getline(leer_historial, linea)){
			cout << " " << linea << endl;
		    }
		    leer_historial.close();
	    }
	    else{
		    // Si no existe el archivo todavía, significa que no han jugado la primera batalla
		    cout << "Aun no hay batallas registradas en el historial" << endl;
	    }   
    }

    //Guardar Historial de batalla 
    void Batalla::GuardarHistorial(string Historial){
    ofstream savehistorial("historial.txt", ios::app);
	    if (savehistorial.is_open()){
		    savehistorial << Historial << endl;
		    savehistorial.close();
		    cout << "Batalla registrada en el historial \n";
	    }
	    else{
		    cout << "ERROR! no se pudo registrar la batalla en el historial \n";
	    }
    }
 //llave de batalla 


//prueba commit 