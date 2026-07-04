#ifndef POKEGOD2_H
#define POKEGOD2_H
#include <string>


class Pokemones { 

    private: // valores que dio el profe (notese que me acabo de dar cuenta que tipo y especie es muy parecido XDDDDDD)
    //nombre, especie, tipo, vida, ataque, defensa, velocidad, nivel

    std::string nombre;
    std::string especie;
    std::string tipo;

    int vida; // vida actual
    int salud; // vida total
    int nivel;
    int ataque;
    int defensa;
    int velocidad;
        

    public:                  //nombre, especie, tipo, vida ,salud, ataque, defensa, velocidad, nivel
        Pokemones(std::string nombre, std::string especie, std::string tipo, int vida, int salud, int ataque, int defensa, int velocidad, int nivel);
        
        void mostrarInformacion();
        void recibirGolpes(int cantidad);
        void curar(int cantidad);
        void subirNivel();
        
        std::string obtenerNombre();
        std::string obtenerTipo();

        bool estaDebilitado();

        int getSalud();
        int getVida();
        int getAtaque();
        int getDefensa();
        int getVelocidad();

        //cambios 
        void Leer_poke();

        void BuscarPokemon(std::string nombre);

        //prueba commit 
};

#endif
