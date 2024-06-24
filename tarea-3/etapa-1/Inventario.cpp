#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "../headers/Item.h"
#include "../headers/Inventario.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include "../headers/Juguete.h"

Inventario::Inventario(int c) {
	capacidad = c;
	cantidad = 0;
}
Inventario::~Inventario() {

}
void Inventario::agregarItem(std::shared_ptr<Item> item) {
	if (cantidad < capacidad) {
        items.push_back(item);
		cantidad++;
	}
}
void Inventario::usarItem(int id, Mascota &mascota) {
	//for (Item& item : items) {
	//	if (item.getId() == id) {
	//		std::cout << "Usando item..." << std::endl;
	//		item.mostrarItem();
	//		std::cout << std::endl;
	//		item->usarItem(mascota);
	//	}
	//}
	for (const auto& item : items) {
        if (item->getId() == id) {
			std::cout << "Usando item..." << std::endl;
			item->mostrarItem();
			std::cout << std::endl;
			item->usarItem(mascota);
        }
    }
}
void Inventario::mostrarInventario() {
	//for (const Item& item : items) {
	for (const auto& item : items) {
		item->mostrarItem();
	}
};
