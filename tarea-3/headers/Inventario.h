#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <memory>
#include <vector>
#include "Item.h"
#include "Mascota.h" 

// Definición de la clase Inventario
class Inventario {
private:
    //std::vector<Item> items; // Vector de objetos Item
	std::vector<std::shared_ptr<Item>> items; // Vector de objetos Item
    int capacidad;  // Capacidad máxima del inventario
    int cantidad;   // Cantidad actual de elementos en el inventario

public:
    // Constructor
    Inventario(int capacidad);

    // Destructor
    ~Inventario();

    // Método para agregar un nuevo item al inventario
    void agregarItem(std::shared_ptr<Item> item);

    // Método para usar un nuevo item del inventario
    void usarItem(int id, Mascota &mascota);

    // Método para imprimir todos los items del inventario
    void mostrarInventario();
};

#endif // INVENTARIO_H
