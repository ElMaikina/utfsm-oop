#include <iostream>
#include <string>

// Definición de la clase Item
class Item {
private:
    int id;
    std::string tipo;
    std::string nombre;
    int cantidad;

public:
    // Constructor
    Item(int i, std::string t, std::string n, int c) {
        id = i;
        tipo = t;
        nombre = n;
        cantidad = c;
    }
    // Métodos para acceder a los atributos
    int getId() {
        return id;
    }
    std::string getTipo() {
        return tipo;
    }
    std::string getNombre() {
        return nombre;
    }
    int getCant() const {
        return cantidad;
    }
    void setCant(int c) {
        cantidad = c;
    }
    void mostrarItem() {
        std::cout << id << ": " << nombre << ", cantidad " << cantidad <<  std::endl;
    }
};