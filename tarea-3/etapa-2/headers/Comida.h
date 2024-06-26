#ifndef COMIDA_H
#define COMIDA_H
#include <string>
#include "Item.h"

class Comida : public Item { 

public:
    Comida(int i, std::string n, int c);
    void usarItem(Mascota &mascota) override;
};

#endif //COMIDA_H
