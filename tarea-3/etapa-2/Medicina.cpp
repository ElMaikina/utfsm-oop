#include <iostream>
#include <string>
#include "../headers/Medicina.h"
#include "../headers/Mascota.h"

Medicina::Medicina(int i, std::string n, int c) : Item(i, "Medicina", n, c) {}
void Medicina::usarItem(Mascota &mascota) {
	//std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	//mascota.mostrarMascota();
	if (getCant() > 0) {
		std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;

		int newSalud = mascota.getSalud() + 40;

		if (newSalud > MAX_STATS) {newSalud = MAX_STATS;}

		mascota.setSalud(newSalud);
		cantidad--;
		mascota.mostrarMascota();
	}
	else {
		std::cout << "No queda mas " << tipo << " " << nombre << "..." << std::endl;
	}
} 

