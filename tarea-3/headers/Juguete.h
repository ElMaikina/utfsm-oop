#ifndef JUGUETE_H
#define JUGUETE_H
#include "Item.h"

class Juguete : public Item { 

public:
    Juguete(int id, std::string nombre);

    void usar(Mascota &mascota) override;
};

#endif //JUGUETE_Hs
