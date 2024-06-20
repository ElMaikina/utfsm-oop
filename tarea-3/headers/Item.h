#ifndef ITEM_H
#define ITEM_H

#include <string>

// Definición de la clase Item
class Item {
private:
    int id;                
    std::string tipo;
    std::string nombre;
    int cantidad;
public:
    Item(int i, std::string t, std::string n, int c);
    int getId();
    std::string getTipo();
    std::string getNombre();
    int getCant();
    void setCant(int newCant);
    void mostrarItem();
};

#endif // ITEM_H