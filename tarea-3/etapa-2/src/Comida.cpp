#include "../headers/Mascota.h"
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;


Comida::Comida(int id, string nombre, int cantidad) : Item(id, "Comida", nombre, cantidad) {}

void Comida::usar(Mascota &mascota) {
    cout << "Usando comida: " << getNombre() << " en la mascota" << endl;

    mascota.salud += 20;
    if (mascota.salud > MAX_STATS) {
        mascota.salud = MAX_STATS;
    }
    
    mascota.energia += 20;
    if (mascota.energia > MAX_STATS) {
        mascota.energia = MAX_STATS;
    }

    cantidad--;
}

