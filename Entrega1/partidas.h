#ifndef PARTIDAS_H
#define PARTIDAS_H
#include "entrenacabra.h"

bool guardarPartida(EntrenaCabra* e1, EntrenaCabra* e2, bool batallaActiva, int idx1, int idx2);
bool cargarPartida(EntrenaCabra*& e1, EntrenaCabra*& e2, bool& batallaActiva, int& idx1, int& idx2);


#endif // PARTIDAS_H