#include <iostream>
#include "../game_headers/Item.h"

using std::string;
using std::cout;
using std::endl;

Item::Item(int id, string tipo, string nombre, int cantidad) :
    id(id), 
    tipo(tipo), 
    nombre(nombre), 
    cantidad(cantidad)
    {}

void Item::mostrarItem() const {
    cout 
    << "ID: "         << id
    << "\nNombre: "   << nombre
    << "\nCantidad: " << cantidad
    << "\n" 
    << endl;
}

int Item::getId() const {
    return id;
}

string Item::getTipo() const {
    return tipo;
}

string Item::getNombre() const {
    return nombre;
}

int Item::getCantidad() const {
    return cantidad;
}

void Item::setCantidad(int nuevaCantidad) {
    this->cantidad = nuevaCantidad;
}
