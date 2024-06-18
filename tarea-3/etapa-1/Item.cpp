#include <iostream>
#include <string>

// Definición de la clase Item
class Item {
private:
    std::string nombre;
    int cantidad;

public:
    // Constructor
    Item(std::string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}

    // Métodos para acceder a los atributos
    std::string getNombre() const {
        return nombre;
    }

    int getCantidad() const {
        return cantidad;
    }

    void setCantidad(int nuevaCantidad) {
        cantidad = nuevaCantidad;
    }
};