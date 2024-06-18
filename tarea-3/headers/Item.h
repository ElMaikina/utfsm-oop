#ifndef ITEM_H
#define ITEM_H

#include <string>

// Definición de la clase Item
class Item {
private:
    std::string nombre;
    int cantidad;

public:
    // Constructor
    Item(std::string nombre, int cantidad);

    // Métodos para acceder a los atributos
    std::string getNombre() const;
    int getCantidad() const;
    void setCantidad(int nuevaCantidad);
};

#endif // ITEM_H