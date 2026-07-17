#include "partidas.h"
#include "pokegod2.h"
#include "entrenacabra.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

const unsigned int MAGIC_NUMBER = 0x504B4D4E; 

static unsigned char calcularChecksum(const char* data, size_t len) {
    unsigned char cs = 0;
    for (size_t i = 0; i < len; ++i) cs ^= static_cast<unsigned char>(data[i]);
    return cs;
}

// Estructura para serializar un Pokémon
struct PokemonData {
    char nombre[50];
    char especie[50];
    char tipo[20];
    int vida;
    int salud;
    int nivel;
    int ataque;
    int defensa;
    int velocidad;
};

// Guarda un entrenador en un flujo binario
static bool guardarEntrenador(ostream& out, EntrenaCabra* e) {
    // Nombre (longitud + cadena)
    string nombre = e->obtenerNombre();
    int len = nombre.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(nombre.c_str(), len);

    // Mochila (5 booleanos)
    for (int i = 0; i < 5; ++i) {
        bool usado = e->objetoUsado(i);
        out.write(reinterpret_cast<const char*>(&usado), sizeof(usado));
    }

    // Índice activo
    int activo = e->obtenerIndiceActivo();
    out.write(reinterpret_cast<const char*>(&activo), sizeof(activo));

    // 3 Pokémon
    for (int i = 0; i < 3; ++i) {
        Pokemones* p = e->obtenerPokemon(i);
        PokemonData pd;
        if (p) {
            strncpy(pd.nombre, p->obtenerNombre().c_str(), 49); pd.nombre[49] = '\0';
            strncpy(pd.especie, p->obtenerEspecie().c_str(), 49); pd.especie[49] = '\0';
            strncpy(pd.tipo, p->obtenerTipo().c_str(), 19); pd.tipo[19] = '\0';
            pd.vida = p->getVida();
            pd.salud = p->getSalud();
            pd.nivel = p->getNivel();
            pd.ataque = p->getAtaque();
            pd.defensa = p->getDefensa();
            pd.velocidad = p->getVelocidad();
        } else {
            memset(&pd, 0, sizeof(pd));
        }
        out.write(reinterpret_cast<const char*>(&pd), sizeof(pd));
    }
    return out.good();
}

// Carga un entrenador desde un flujo binario
static EntrenaCabra* cargarEntrenador(istream& in) {
    // Nombre
    int len;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!in.good()) return nullptr;
    char* buf = new char[len + 1];
    in.read(buf, len);
    buf[len] = '\0';
    string nombre(buf);
    delete[] buf;

    EntrenaCabra* e = new EntrenaCabra(nombre, 0);

    // Mochila
    for (int i = 0; i < 5; ++i) {
        bool usado;
        in.read(reinterpret_cast<char*>(&usado), sizeof(usado));
        e->setObjetoUsado(i, usado);
    }

    // Índice activo
    int activo;
    in.read(reinterpret_cast<char*>(&activo), sizeof(activo));
    e->setIndiceActivo(activo);

    // 3 Pokémon
    for (int i = 0; i < 3; ++i) {
        PokemonData pd;
        in.read(reinterpret_cast<char*>(&pd), sizeof(pd));
        if (pd.vida > 0) {
            Pokemones* p = new Pokemones(
                string(pd.nombre),
                string(pd.especie),
                string(pd.tipo),
                pd.vida,
                pd.salud,
                pd.ataque,
                pd.defensa,
                pd.velocidad,
                pd.nivel
            );
            e->AgregarPokemon(p, i);
        } else {
            e->AgregarPokemon(nullptr, i);
        }
    }
    return e;
}


bool guardarPartida(EntrenaCabra* e1, EntrenaCabra* e2,
                    bool batallaActiva, int idx1, int idx2) {
    ofstream out("partida.bin", ios::binary);
    if (!out) {
        cerr << "Error: no se pudo crear partida.bin\n";
        return false;
    }

    // Escribir magic
    unsigned int magic = MAGIC_NUMBER;
    out.write(reinterpret_cast<const char*>(&magic), sizeof(magic));

    // Usamos un buffer para calcular checksum
    stringstream buffer(ios::binary | ios::in | ios::out);

    // Guardar estado de batalla
    unsigned char flag = batallaActiva ? 1 : 0;
    buffer.write(reinterpret_cast<const char*>(&flag), sizeof(flag));
    buffer.write(reinterpret_cast<const char*>(&idx1), sizeof(idx1));
    buffer.write(reinterpret_cast<const char*>(&idx2), sizeof(idx2));

    // Guardar entrenadores
    if (!guardarEntrenador(buffer, e1)) return false;
    if (!guardarEntrenador(buffer, e2)) return false;

    // Obtener los datos del buffer
    string data = buffer.str();

    // Calcular checksum sobre los datos (sin incluir magic ni checksum)
    unsigned char checksum = calcularChecksum(data.c_str(), data.size());

    // Escribir datos y checksum
    out.write(data.c_str(), data.size());
    out.write(reinterpret_cast<const char*>(&checksum), sizeof(checksum));

    out.close();
    cout << "Partida guardada correctamente.\n";
    return true;
}

bool cargarPartida(EntrenaCabra*& e1, EntrenaCabra*& e2,bool& batallaActiva, int& idx1, int& idx2) {
    ifstream in("partida.bin", ios::binary);
    if (!in) {
        cerr << "Error: no se encontró partida.bin\n";
        return false;
    }

    // Leer magic
    unsigned int magic;
    in.read(reinterpret_cast<char*>(&magic), sizeof(magic));
    if (magic != MAGIC_NUMBER) {
        cerr << "Magic number incorrecto. Archivo corrupto.\n";
        in.close();
        return false;
    }

    // Obtener tamaño total
    in.seekg(0, ios::end);
    streampos size = in.tellg();
    in.seekg(sizeof(magic), ios::beg);

    // Leer el resto (datos + checksum)
    size_t dataSize = size - sizeof(magic) - sizeof(unsigned char);
    char* data = new char[dataSize];
    in.read(data, dataSize);
    if (!in.good()) {
        cerr << "Error al leer datos.\n";
        delete[] data;
        in.close();
        return false;
    }

    unsigned char storedChecksum;
    in.read(reinterpret_cast<char*>(&storedChecksum), sizeof(storedChecksum));
    in.close();

    // Verificar checksum
    unsigned char calc = calcularChecksum(data, dataSize);
    if (calc != storedChecksum) {
        cerr << "Checksum no coincide. Archivo corrupto.\n";
        delete[] data;
        return false;
    }

    cout << "Magic number....OK\nChecksum....OK\n";

    // Reconstruir desde el buffer
    stringstream buffer(string(data, dataSize), ios::binary | ios::in);
    delete[] data;

    // Leer estado de batalla
    unsigned char flag;
    buffer.read(reinterpret_cast<char*>(&flag), sizeof(flag));
    batallaActiva = (flag == 1);
    buffer.read(reinterpret_cast<char*>(&idx1), sizeof(idx1));
    buffer.read(reinterpret_cast<char*>(&idx2), sizeof(idx2));

    // Cargar entrenadores
    delete e1;
    delete e2;
    e1 = cargarEntrenador(buffer);
    e2 = cargarEntrenador(buffer);

    if (!e1 || !e2) {
        cerr << "Error al reconstruir los entrenadores.\n";
        delete e1; delete e2;
        e1 = e2 = nullptr;
        return false;
    }

    cout << "Partida cargada correctamente.\n";
    if (batallaActiva) {
        cout << "La batalla estaba en curso. Índices: jugador=" << idx1 << ", cpu=" << idx2 << "\n";
    }
    return true;
}