#include "batalla.h"
#include <iostream>
#include <string>

using namespace std;

float Batalla::ventaja(string tipo_atacante, string tipo_defensor){
    // Ventajas: Fuego > Hielo > Electrico > Eter > Fisico > Fuego
    if (tipo_atacante == "Fuego" && tipo_defensor == "Hielo") return 2.0;
    if (tipo_atacante == "Hielo" && tipo_defensor == "Electrico") return 2.0;
    if (tipo_atacante == "Electrico" && tipo_defensor == "Eter") return 2.0;
    if (tipo_atacante == "Eter" && tipo_defensor == "Fisico") return 2.0;
    if (tipo_atacante == "Fisico" && tipo_defensor == "Fuego") return 2.0;
    
    // Desventajas (Integradas aqui para no modificar batalla.h)
    if (tipo_atacante == "Hielo" && tipo_defensor == "Fuego") return 0.5;
    if (tipo_atacante == "Electrico" && tipo_defensor == "Hielo") return 0.5;
    if (tipo_atacante == "Eter" && tipo_defensor == "Electrico") return 0.5;
    if (tipo_atacante == "Fisico" && tipo_defensor == "Eter") return 0.5;
    if (tipo_atacante == "Fuego" && tipo_defensor == "Fisico") return 0.5;
    
    // Dano normal
    return 1.0;
}

// Ciclo principal para el combate
void Batalla::inicio_combat(EntrenaCabra* jugador, EntrenaCabra* cpu){
    cout << "\n";
    cout << "  INICIANDO SIMULACION DE COMBATE" << endl;
    cout << "  PROXIES EN LA SIMULACION: " << jugador->obtenerNombre() << " VS " << cpu->obtenerNombre() << endl;
    
    int indice_jugador = 0, indice_cpu = 0;
    
    // Obtenemos los agentes activos iniciales usando las flechas (->)
    Pokemones* cabraJugador = jugador->obtenerPokemon(indice_jugador);
    Pokemones* cabraCpu = cpu->obtenerPokemon(indice_cpu);
    
    while(!jugador->estasmuerto() && !cpu->estasmuerto()){
        
        // Control por si nuestro agente es eliminado 
        if(cabraJugador->estaDebilitado()){
            cout << "[!] El agente " << cabraJugador->obtenerNombre() << " sufrio demasiado danio. Solicitando relevo!" << endl;
            
            // El do-while maneja todo el flujo de entrada de forma limpia
            do {
                jugador->MostrarEquipo();
                cout << "Selecciona el indice del nuevo agente a desplegar: ";
                cin >> indice_jugador;
                cabraJugador = jugador->obtenerPokemon(indice_jugador);
                
                // Validacion por si metes un numero invalido o un agente muerto
                if(cabraJugador == nullptr || cabraJugador->estaDebilitado()) {
                    if (!jugador->estasmuerto()) {
                        cout << "[X] Indice invalido o agente sin energia vital. ¡Elige otro!\n" << endl;
                    }
                }
            } while((cabraJugador == nullptr || cabraJugador->estaDebilitado()) && !jugador->estasmuerto());
            
            continue;
        }
        
        // Control por si el agente enemigo es eliminado
        if(cabraCpu->estaDebilitado()){
            cout << "\n[+] El agente enemigo " << cabraCpu->obtenerNombre() << " fue ELIMINADO" << endl;
            indice_cpu++;
            
            // Validamos que le queden criaturas a la CPU antes de mover el puntero
            if(!cpu->estasmuerto()) {
                cabraCpu = cpu->obtenerPokemon(indice_cpu);
                cout << ">> El rival despliega a su siguiente agente: " << cabraCpu->obtenerNombre() << endl;
            }
            continue;
        }
        
        // Interfaz de estado
        cout << "\n";
        cout << " TU AGENTE:  " << cabraJugador->obtenerNombre() << " [" << cabraJugador->obtenerTipo() << "] | Vida: " << cabraJugador->getVida() << endl;
        cout << " RIVAL CPU:  " << cabraCpu->obtenerNombre() << " [" << cabraCpu->obtenerTipo() << "] | Vida: " << cabraCpu->getVida() << endl;
        
        // Mini Menu para las opciones del proxy
        cout << "1. Ejecutar Ataque Basico / Especial" << endl;
        cout << "2. Desplegar Gadget (Mochila) " << endl;
        cout << "3. Relevo Tactico (Cambiar Agente) " << endl;
        cout << "Selecciona tu comando: ";
        int opcion;
        cin >> opcion;
        
        bool turno_valido = false;
        
        if(opcion == 1){
            // Logica para el dano de los atributos
            float multiplicador = ventaja(cabraJugador->obtenerTipo(), cabraCpu->obtenerTipo());
            int danio = (cabraJugador->getAtaque() - (cabraCpu->getDefensa() / 2)) * multiplicador;
            if (danio <= 0) danio = 1; // Para que no cure si la defensa es muy alta
            
            cabraCpu->recibirGolpes(danio);
            cout << "\n>> " << cabraJugador->obtenerNombre() << " golpea con atributo " << cabraJugador->obtenerTipo() << "!";
            
            if(multiplicador > 1.0) cout << " ANOMALIA APLICADA: EFECTO CRITICO! ";
            if(multiplicador < 1.0) cout << " (El enemigo resistio parcialmente el atributo) ";
            cout << "\n Danio infligido: " << danio << endl;
            
            turno_valido = true;
        }
        else if (opcion == 2) {
            // usarObjeto() ya imprime la mochila y pide el cin por dentro, no hace falta repetirlo aca
            turno_valido = jugador->usarObjeto(); 
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
                cabraJugador = nuevoPokemon;
                cout << "\n >> ¡Entrando al campo de batalla! " << cabraJugador->obtenerNombre() << endl;
                turno_valido = true;
            } else {
                cout << "[X] Relevo invalido o agente sin energia. Intenta de nuevo." << endl;
            }
        }
        
        // Turno de la CPU
        if (turno_valido && !cabraCpu->estaDebilitado()){
            cout << "\n [TURNO ENEMIGO - CPU]" << endl;
            
            float multCpu = ventaja(cabraCpu->obtenerTipo(), cabraJugador->obtenerTipo());
            int danioCpu = (cabraCpu->getAtaque() - (cabraJugador->getDefensa() / 2)) * multCpu;
            if (danioCpu <= 0) danioCpu = 1;
            
            cabraJugador->recibirGolpes(danioCpu);
            cout << ">> " << cabraCpu->obtenerNombre() << " contraataca. Danio recibido en tu agente: " << danioCpu << endl;            
        }
    }
    
    // Evaluacion final del combate
    cout << "\n";
    if (!jugador->estasmuerto()){
        cout << "  WIPEOUT! Enemigos eliminados. Victoria Proxy! " << endl;
    } else {
        cout << "  MISION FALLIDA. Todos tus agentes han sido eliminados. " << endl;
    }

}