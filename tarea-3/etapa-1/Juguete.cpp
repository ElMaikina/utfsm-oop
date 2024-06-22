#include <iostream>
#include <string>
#include "../headers/Juguete.h"
#include "../headers/Mascota.h"

Juguete::Juguete(int i, std::string n) : Item(i, "juguete", n, -1) {}
void Juguete::usarItem(Mascota &mascota) {
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	mascota.mostrarMascota();
} 

