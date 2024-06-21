#ifndef MEDICINA_H
#define MEDICINA_H
#include "Item.h"

class Medicina : public Item { 

public:
    Medicina(int id, std::string nombre);

    void usar(Mascota &mascota) override;
};

#endif //MEDICINA_Hs
