#ifndef JUGUETE_H
#define JUGUETE_H
#include "Item.h"
/** @Class Juguete
@brief sub clase de item, jugute
*/
class Juguete : public Item { 

public:
    Juguete(int id, std::string nombre);/** @brief Constructor de juguete 
    @param id    numero identificador del item
    @param nombre    nombre del juguete
    */

    ~Juguete() override = default;/** @brief Destructor de juguete */

    void usar(Mascota &mascota) override; /** @brief Funcion para usar juguete
    @param &mascota    direccion para los datos de mascota apuntada
    
    */
};

#endif //JUGUETE_H
