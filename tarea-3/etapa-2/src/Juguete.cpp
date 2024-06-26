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

