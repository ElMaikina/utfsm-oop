#ifndef MEDICINA_H
#define MEDICINA_H
#include "Item.h"

class Medicina : public Item { 

public:
    Medicina(int i, std::string n, int c);
    void usarItem(Mascota &mascota) override;
};

#endif //MEDICINA_H
