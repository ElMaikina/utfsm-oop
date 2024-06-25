#include "../headers/Mascota.h"
#include "../headers/Medicina.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;


Medicina::Medicina(int id, string nombre, int cantidad) : Item(id, "Medicina", nombre, cantidad) {}

void Medicina::usar(Mascota &mascota) {
    cout << "Usando medicina: " << getNombre() << " en la mascota\n" << endl;

    mascota.salud += 40;
    if (mascota.salud > MAX_STATS) {
        mascota.salud = MAX_STATS;
    }

    cantidad --;
}

