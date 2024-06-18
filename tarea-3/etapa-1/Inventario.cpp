#include <iostream>
#include <string>
#include "../headers/Item.h"

// Definición de la clase Inventario
class Inventario {
private:
    Item* items;    // Arreglo dinámico de objetos Item
    int capacidad;  // Capacidad máxima del inventario
    int cantidad;   // Cantidad actual de elementos en el inventario

public:
    // Constructor
    Inventario(int c) {
        capacidad = c;
        items = new Item[c];
        cantidad = 0;
    }

    // Destructor para liberar la memoria del arreglo dinámico
    ~Inventario() {
        delete[] items;
    }

    // Método para agregar un nuevo item al inventario
    void agregarItem(const Item& item) {
        if (cantidad < capacidad) {
            items[cantidad] = item;
            cantidad++;
        }
    }

    // Método para imprimir todos los items del inventario
    void mostrarInventario() {
        for(int i = 0; i < cantidad; i++) {
            items[i].mostrarItem();
        }
    }
};