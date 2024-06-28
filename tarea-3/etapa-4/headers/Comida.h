#ifndef COMIDA_H
#define COMIDA_H
#include "Item.h"

class Comida : public Item { 

public:
    Comida(int id, std::string nombre, int cantidad);/**Constructor Comida */

    ~Comida() override = default;/**Destructor Comida */

    void usar(Mascota &mascota) override;/** Funcion para utilizar alimentar a la mascota*/
};

#endif //COMIDA_H
