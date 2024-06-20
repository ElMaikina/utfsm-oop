#ifndef ITEM_H
#define ITEM_H

#include <string>

// Definición de la clase Item
class Item {
private:
    std::string nombre;
    int cantidad;
public:
    Item(std::string nombre, int cantidad);
    std::string getNombre() const;
    int getCantidad() const;
    void setCantidad(int nuevaCantidad);
};

#endif // ITEM_H