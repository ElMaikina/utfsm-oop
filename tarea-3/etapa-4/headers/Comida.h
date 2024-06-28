#ifndef COMIDA_H
#define COMIDA_H
#include "Item.h"

class Comida : public Item { 
/** @Class Comida */

public:
    Comida(int id, std::string nombre, int cantidad);/**@brief Constructor Comida
    @param id    id numerico del item
    @param nombre    nombre de la comida
    @param cantidad    cantidad total del item
    */

    ~Comida() override = default;/**@brief Destructor Comida */

    void usar(Mascota &mascota) override;/**@brief  Funcion para utilizar alimentar a la mascota
    @param &mascota Puntero de mascota*/
};

#endif //COMIDA_H
