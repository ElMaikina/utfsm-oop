#include <iostream>
#include <string>
#include <vector>
#include "../headers/Item.h"
#include "../headers/Inventario.h"

Inventario::Inventario(int c) {
	capacidad = c;
	cantidad = 0;
}
Inventario::~Inventario() {

}
void Inventario::agregarItem(Item item) {
	if (cantidad < capacidad) {
        items.push_back(item);
		cantidad++;
	}
}
void Inventario::usarItem(int id, Mascota &mascota) {
	for (const Item& item : items) {
		if (item.getId() == id) {
			std::cout << "Usando item..." << std::endl;
			item.mostrarItem();
			std::cout << std::endl;
			//item.usarItem(mascota);
		}
	}
}
void Inventario::mostrarInventario() {
	for (const Item& item : items) {
		item.mostrarItem();
	}
};
