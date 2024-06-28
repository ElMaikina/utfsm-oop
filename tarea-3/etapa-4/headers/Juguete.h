#ifndef JUGUETE_H
#define JUGUETE_H
#include "Item.h"

class Juguete : public Item { 

public:
    Juguete(int id, std::string nombre);/** Constructor de juguete */

    ~Juguete() override = default;/** Destructor de juguete */

    void usar(Mascota &mascota) override; /** Funcion para usar juguete*/
};

#endif //JUGUETE_H
