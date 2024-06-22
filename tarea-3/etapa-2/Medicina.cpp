#include <iostream>
#include <string>
#include "../headers/Medicina.h"
#include "../headers/Mascota.h"

Medicina::Medicina(int i, std::string n, int c) : Item(i, "Medicina", n, c) {}
void Medicina::usarItem(Mascota &mascota) {
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	mascota.mostrarMascota();
} 

