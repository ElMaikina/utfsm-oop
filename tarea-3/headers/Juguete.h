#ifndef JUGUETE_H
#define JUGUETE_H
#include "Item.h"

class Juguete : public Item { 

public:
    Juguete(int i, std::string n);
    void usarItem(Mascota &mascota) override;
};

#endif //JUGUETE_H
