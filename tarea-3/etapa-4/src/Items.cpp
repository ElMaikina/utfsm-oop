#include "../headers/Mascota.h"
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;


Juguete::Juguete(int id, string nombre) : Item(id, "Juguete", nombre) {}

void Juguete::usar(Mascota &mascota) {
    cout << "Usando juguete: " << getNombre() << " en la mascota" << endl;

    mascota.felicidad += 30;
    if (mascota.felicidad > MAX_STATS) {
        mascota.felicidad = MAX_STATS;
    }
}


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


Medicina::Medicina(int id, string nombre, int cantidad) : Item(id, "Medicina", nombre, cantidad) {}

void Medicina::usar(Mascota &mascota) {
    cout << "Usando medicina: " << getNombre() << " en la mascota\n" << endl;

    mascota.salud += 40;
    if (mascota.salud > MAX_STATS) {
        mascota.salud = MAX_STATS;
    }

    cantidad --;
}
