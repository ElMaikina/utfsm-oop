#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Item.h"
#include "Mascota.h" 

/* @class Inventario 
@brief Definición de la clase Inventario */
class Inventario {
private:
	std::vector<Item*> items;
    Mascota &mascota;

public:
    // Constructor
    Inventario(Mascota &mascota);/*@brief Constructor de inventario 
    @param &mascota	puntero a la mascota
    */

    // Destructor
    ~Inventario();/*@brief destructor */

    // Método para agregar un nuevo item al inventario
    void agregarItem(Item *item);/* @brief Agrega un item al inventario 
    @param *item	Operador punterio de item	
    */

    // Método para buscar Item por ID
    Item * buscarPorID(int id);/* @brief busca el item por id numerico 
    @param id	id numerico del item
    */

    // Método para usar un nuevo item del inventario
    void usarItem(int id, Mascota &mascota); /* @brief utiliza un Item del inventario 
@param id	id numerico del item
@param &mascota	referencia a la mascota
*/

    // Método para imprimir todos los items del inventario
    void mostrarInventario() const;/*@brief imprime todos los item del inventario*/
};

#endif // INVENTARIO_H
