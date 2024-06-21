#include <iostream>
#include <string>
#include "../headers/Item.h"

Item::Item(int i, std::string t, std::string n, int c) {
	id = i;
	tipo = t;
	nombre = n;
	cantidad = c;
}
int Item::getId() {
	return id;
}
void Item::usar(Mascota &mascota) {} 
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
void Item::mostrarItem() {
	std::cout << id << ": " << nombre << ", cantidad " << cantidad <<  std::endl;
};
