#ifndef SPRITES_H
#define SPRITES_H

#include "pokegod2.h" // Importante para que el compilador sepa qué es la clase Pokemones
#include <string>

// Muestra el sprite individual de una especie cargándolo desde la carpeta "sprites/"
void mostrarSprite(const std::string& especie);

// Dibuja los sprites de ambos Pokémon frente a frente en la interfaz de la batalla
void mostrarSpritesEnBatalla(Pokemones* p1, Pokemones* p2);

#endif // SPRITES_H