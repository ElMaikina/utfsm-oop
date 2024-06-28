#ifndef MEDICINA_H
#define MEDICINA_H
#include "Item.h"
/** @Class Medicina


@brief Sub clase de Item hereda los elementos publicos de la misma */

class Medicina : public Item { 

public:
    Medicina(int id, std::string nombre, int cantidad);/** @brief Constructor para la clase medicina
    @param id    Numero identificador de item
    @param nombre    Nombre de la medicina
    @param cantidad    Cantidad total de la medicina especifica en el inventario*/

    ~Medicina() override = default;/**@brief Destructor de Medicina*/

    void usar(Mascota &mascota) override; /** @brief Funcion para utilizar la medicina y aumentar sus puntos de salud
    @param &mascota    puntero apuntando a las caracteristicas de la mascota  */
};

#endif //MEDICINA_H
