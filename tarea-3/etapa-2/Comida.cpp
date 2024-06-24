#include <iostream>
#include <string>
#include "../headers/Comida.h"
#include "../headers/Mascota.h"

Comida::Comida(int i, std::string n, int c) : Item(i, "Comida", n, c) {}
void Comida::usarItem(Mascota &mascota) {
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;

	int newSalud = mascota.getSalud() + 20;
	int newEnergia = mascota.getEnergia() + 20;

	if (newSalud > MAX_STATS) {newSalud = MAX_STATS;}
	if (newEnergia > MAX_STATS) {newEnergia = MAX_STATS;}

	mascota.setSalud(newSalud);
	mascota.setEnergia(newEnergia);
	cantidad--;
	mascota.mostrarMascota();
} 

