#ifndef MEDICINA_H
#define MEDICINA_H
#include "Item.h"
/** Sub clase de Item hereda los elementos publicos de la misma */

class Medicina : public Item { 

public:
    Medicina(int id, std::string nombre, int cantidad);/** Constructor para la clase medicina*/

    ~Medicina() override = default;/** Destructor de Medicina*/

    void usar(Mascota &mascota) override; /** Funcion para utilizar la medicina y aumentar sus puntos de salud*/
};

#endif //MEDICINA_H
