#ifndef COMIDA_H
#define COMIDA_H
#include "Item.h"

class Comida : public Item { 

public:
    Comida(int id, std::string nombre, int cantidad);

    ~Comida() override = default;

    void usar(Mascota &mascota) override;
};

#endif //COMIDA_H
