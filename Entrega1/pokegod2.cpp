#include "pokegod2.h"
#include <iostream>

using namespace std;


                    //nombre, especie, tipo, vida ,salud, ataque, defensa, velocidad, nivel
Pokemones::Pokemones(string nombr, string especi, string tip, int vid, int salu, int ataqu, int defens, int velocida, int nive) {

nombre=nombr;
especie=especi;
tipo=tip;
vida=vid;
salud=salu;
nivel=nive;
ataque=ataqu;
defensa=defens;
velocidad=velocida;

}
void Pokemones::subirNivel() {
    nivel += 1;
    salud += 15; // Sube la vida maxima
    vida += 20;  // Se cura un poquito al subir
    ataque += 8;
    defensa += 5;
    velocidad += 3; // criticos

    cout << nombre << " ha subido al nivel " << nivel << "Felicidades mai bro"<< endl;
    cout << "Sus estadísticas han mejorado de manera permanente (Gracias a dios)" << endl;
}

void Pokemones::mostrarInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Especie: " << especie << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Vida: " << vida << "/" << salud << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Defensa: " << defensa << endl;
    cout << "Velocidad: " << velocidad << endl;
}
void Pokemones::recibirGolpes(int cantidad) {
    vida -= cantidad;
    if (vida < 0) {vida = 0;}
}
void Pokemones::curar(int cantidad) {
    vida += cantidad;
    if (vida > salud) {vida = salud;}

}
    bool Pokemones::estaDebilitado() { 
    return vida <= 0;
    }

    int Pokemones::getSalud() {return salud;}
    int Pokemones::getVida() {return vida;}
    int Pokemones::getAtaque() {return ataque;}
    int Pokemones::getDefensa() {return defensa;}
    int Pokemones::getVelocidad() {return velocidad;}
    string Pokemones::obtenerNombre() {return nombre; }
    string Pokemones::obtenerTipo() {return tipo; }