#include <iostream>
#include <string>
#include "../headers/Juguete.h"
#include "../headers/Mascota.h"

Juguete::Juguete(int i, std::string n) : Item(i, "Juguete", n, -1) {}
void Juguete::usarItem(Mascota &mascota) {
	//std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	//mascota.mostrarMascota();
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;

	int newFelicidad = mascota.getFelicidad() + 30;

	if (newFelicidad > MAX_STATS) {newFelicidad = MAX_STATS;}

	mascota.setFelicidad(newFelicidad);
	mascota.mostrarMascota();
} 

