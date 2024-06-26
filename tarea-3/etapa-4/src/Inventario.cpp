#include <iostream>
#include <string>
#include <vector>
#include "../headers/Item.h"
#include "../headers/Inventario.h"

Inventario::Inventario(Mascota &mascota) : mascota(mascota) 
{}

Inventario::~Inventario() {
    for (Item *item : items) {
		delete item;
	}
}

void Inventario::agregarItem(Item *item) {
    items.push_back(item);
}

Item * Inventario::buscarPorID(int id) {
	for (Item *item : items) {
		if (item->getId() == id)
		    return item;
	}
	return NULL;
}

void Inventario::usarItem(int id, Mascota &mascota) {
	Item *item = buscarPorID(id);
    item->usar(mascota);

	int index = 0;
	for (Item *item : items) {
		if (item->getId() == id)
            break;
		index++;
	}

	if (item->getCantidad() == 0) {
		items.erase(items.begin() + index);
	}
}

void Inventario::mostrarInventario() const{
	for (Item *item : items) {
		item->mostrarItem();
	}
};
