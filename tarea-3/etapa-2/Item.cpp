#include <iostream>
#include <string>
#include "../headers/Item.h"
#include "../headers/Mascota.h"

Item::Item(int i, std::string t, std::string n, int c) {
	id = i;
	tipo = t;
	nombre = n;
	cantidad = c;
}
int Item::getId() const {
	return id;
}
void Item::usarItem(Mascota &mascota) {
	std::cout << "Usando " << tipo << " " << nombre << " en la Mascota" << std::endl;
	mascota.mostrarMascota();
} 
std::string Item::getTipo() {
	return tipo;
}
std::string Item::getNombre() {
	return nombre;
}
int Item::getCant() {
	return cantidad;
}
void Item::setCant(int newCant) {
	cantidad = newCant;
}
void Item::mostrarItem() const {
	std::cout << "ID: " << id << ", Nombre: " << nombre << ", Cantidad " << cantidad << std::endl;
};
