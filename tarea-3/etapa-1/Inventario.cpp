#include <iostream>
#include <string>
#include "../headers/Item.h"
#include "../headers/Inventario.h"

Inventario::Inventario(int c) {
	capacidad = c;
	items = (Item*)malloc(sizeof(Item) * c);
	cantidad = 0;
}
Inventario::~Inventario() {
	delete[] items;
}
void Inventario::agregarItem(const Item& item) {
	if (cantidad < capacidad) {
		items[cantidad] = item;
		cantidad++;
	}
}
void Inventario::mostrarInventario() {
	for(int i = 0; i < cantidad; i++) {
		items[i].mostrarItem();
}
};
