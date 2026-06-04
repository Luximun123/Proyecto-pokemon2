#include "pokegod2.h"
#include <iostream>

using namespace std;



pokemones::Pokemones(string nombre, string especie, string tipo, int vida, int salud, int nivel, int ataque, int defensa, int velocidad) {

}


void Pokemones::aumentarAtaque(int cantidad) { ataque += cantidad; }
void Pokemones::aumentarDefensa(int cantidad) { defensa += cantidad; }
void Pokemones::aumentarVelocidad(int cantidad) { velocidad += cantidad; }