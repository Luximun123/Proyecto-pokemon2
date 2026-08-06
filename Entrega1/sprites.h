#ifndef SPRITES_H
#define SPRITES_H

#include "pokegod2.h" // Importante para que el compilador sepa qué es la clase Pokemones
#include <string>
#include <vector>

// Muestra el sprite individual de una especie cargándolo desde la carpeta "sprites/"
void mostrarSprite(const std::string& especie);

// Dibuja los sprites de ambos Pokémon frente a frente en la interfaz de la batalla
void mostrarSpritesEnBatalla(Pokemones* p1, Pokemones* p2);

//cambios 

void crearsprite(const std::string& especie, const std::vector<std::string>& lineas);    

void dibujosprites();
#endif // SPRITES_H