#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.h" // Incluimos el header de Item

// Definición de la clase Inventario
class Inventario {
private:
    Item* items;    // Arreglo dinámico de objetos Item
    int capacidad;  // Capacidad máxima del inventario
    int cantidad;   // Cantidad actual de elementos en el inventario

public:
    // Constructor
    Inventario(int capacidad);

    // Destructor
    ~Inventario();

    // Método para agregar un nuevo item al inventario
    void agregarItem(const Item& item);

    // Método para imprimir todos los items del inventario
    void mostrarInventario();
};

#endif // INVENTARIO_H
