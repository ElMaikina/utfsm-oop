#include <iostream>
#include <string>
#include "../headers/Comida.h"
#include "../headers/Mascota.h"

Comida::Comida(int i, std::string n, int c) : Item(i, "Comida", n, c) {}
void Comida::usarItem(Mascota &mascota) {
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	mascota.mostrarMascota();
} 

