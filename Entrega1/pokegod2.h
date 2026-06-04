#ifndef POKEGOD2_H
#define POKEGOD2_H
#include <string>
using namespace std;

class Pokemones { //la clase para poner a las cabras que voy a crear (su cedula)

    private: // valores que dio el profe (notese que me acabo de dar cuenta que tipo y especie es muy parecido XDDDDDD)
    //nombre, especie, tipo, vida, ataque, defensa, velocidad, nivel

    string nombre;
    string especie;
    string tipo;

    int vida;
    int salud;
    int nivel;
    int ataque;
    int defensa;
    int velocidad;
        

    public:
        Pokemones(string nombre, string especie, string tipo, int vida, int salud, int nivel, int ataque, int defensa, int velocidad);
        
        void mostrarInformacion();
        void recibirGolpes(int cantidad);
        void curar(int cantidad);
       
        string obtenerNombre();
        string obtenerTipo();

        bool estaDebilitado();

        int leerSalud();
        int leerVida();
        int leerAtaque();
        int leerDefensa();
        int leerVelocidad();

        
};









#endif
