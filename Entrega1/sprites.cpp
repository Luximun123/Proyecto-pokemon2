#include "sprites.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Muestra el sprite de una especie (busca "sprites/especie.spr")
void mostrarSprite(const string& especie) {
    string filename = "sprites/" + especie + ".spr";
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "No se encontró el sprite para la especie '" << especie << "'\n";
        return;
    }

    int ancho, alto;
    file.read(reinterpret_cast<char*>(&ancho), sizeof(ancho));
    file.read(reinterpret_cast<char*>(&alto), sizeof(alto));
    if (!file) {
        cerr << "Error al leer dimensiones del sprite.\n";
        return;
    }

    int total = ancho * alto;
    vector<char> data(total);
    file.read(data.data(), total);
    if (!file) {
        cerr << "Error al leer los datos del sprite.\n";
        return;
    }

    // Imprimir el sprite
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            cout << data[y * ancho + x];
        }
        cout << '\n';
    }
}

// Muestra los sprites de dos Pokémon lado a lado (para la batalla)
void mostrarSpritesEnBatalla(Pokemones* p1, Pokemones* p2) {
    if (!p1 || !p2) return;

    // Cargar ambos sprites en memoria
    auto cargarSprite = [](const string& especie) -> vector<string> {
        vector<string> lineas;
        string filename = "sprites/" + especie + ".spr";
        ifstream file(filename, ios::binary);
        if (!file) return lineas;
        int ancho, alto;
        file.read(reinterpret_cast<char*>(&ancho), sizeof(ancho));
        file.read(reinterpret_cast<char*>(&alto), sizeof(alto));
        if (!file) return lineas;
        int total = ancho * alto;
        vector<char> data(total);
        file.read(data.data(), total);
        if (!file) return lineas;
        for (int y = 0; y < alto; ++y) {
            string linea;
            for (int x = 0; x < ancho; ++x) {
                linea += data[y * ancho + x];
            }
            lineas.push_back(linea);
        }
        return lineas;
    };

    vector<string> s1 = cargarSprite(p1->obtenerEspecie());
    vector<string> s2 = cargarSprite(p2->obtenerEspecie());

    // Alinear alturas (rellenar con espacios)
    size_t maxLines = max(s1.size(), s2.size());
    if (maxLines == 0) {
        cout << "No se pudieron cargar los sprites.\n";
        return;
    }

    // Ancho fijo para cada sprite (tomamos el máximo de ancho de cada uno)
    size_t ancho1 = 0, ancho2 = 0;
    for (auto& l : s1) ancho1 = max(ancho1, l.size());
    for (auto& l : s2) ancho2 = max(ancho2, l.size());
    if (ancho1 == 0) ancho1 = 10;
    if (ancho2 == 0) ancho2 = 10;

    // Imprimir lado a lado
    cout << "\n";
    for (size_t i = 0; i < maxLines; ++i) {
        string linea1 = (i < s1.size()) ? s1[i] : string(ancho1, ' ');
        string linea2 = (i < s2.size()) ? s2[i] : string(ancho2, ' ');
        cout << left << setw(ancho1 + 2) << linea1 << "   " << linea2 << '\n';
    }

    // Información debajo
    cout << "\n" << p1->obtenerNombre() << " (" << p1->obtenerEspecie() << ") "
         << p1->getVida() << "/" << p1->getSalud() << " Nv." << p1->getNivel()
         << "          "
         << p2->obtenerNombre() << " (" << p2->obtenerEspecie() << ") "
         << p2->getVida() << "/" << p2->getSalud() << " Nv." << p2->getNivel()
         << "\n\n";
}