#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Item.h"
#include "Mascota.h" 

// Definición de la clase Inventario
class Inventario {
private:
	std::vector<Item*> items;
    Mascota &mascota;

public:
    // Constructor
    Inventario(Mascota &mascota);

    // Destructor
    ~Inventario();

    // Método para agregar un nuevo item al inventario
    void agregarItem(Item *item);

    // Método para buscar Item por ID
    Item * buscarPorID(int id);

    // Método para usar un nuevo item del inventario
    void usarItem(int id, Mascota &mascota);

    // Retorna inventario.items
    std::vector<Item*> getItems();

    // Método para imprimir todos los items del inventario
    void mostrarInventario() const;
};

#endif // INVENTARIO_H
