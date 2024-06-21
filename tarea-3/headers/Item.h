#ifndef ITEM_H
#define ITEM_H

#include <string>

// Declaración incompleta de Mascota.
class Mascota;

/* 
 * Item es la clase abstracta padre las subclases: Juguete, Comida y Medicina.
 * Esta clase posee todos los métodos disponibles para cada subclase de Item.
 * Lógica tras la ejecución de funciones miembro (excepto SETers y GETers) varían según sub-clase.
 */
class Item {

private:
    int id;
    std::string tipo;
    std::string nombre;
    int cantidad;
    
public:
    /*
     * Método constructor.
     *
     * @param id        Número identificador del Item.
     * 
     * @param tipo      Tipo de Item, definidor de sub-clase.
     * 
     * @param nombre    Nombre de Item.
     * 
     * @param cantidad  Cantidad de Item.
     * Si cantidad no se especifica, cantidad = -1.
     */
    Item(int id, std::string tipo, std::string nombre, int cantidad=-1);

    /*
     * Consume Item en Mascota, afectando sus estadísticas.
     * Al consumir: "cantidad" -= 1.
     *
     * @param mascota
     * Mascota que consume el Item.
     */
    virtual void usar(Mascota &mascota);

    // Muestra Item en consola.
    void mostrarItem();

    // @returns id
    int getId() const; 

    // @returns nombre
    std::string getNombre() const;

    // @returns tipo
    std::string getTipo() const;

    // @returns cantidad
    int getCantidad() const;

    /*
     * Cambia el valor de miebro dato "cantidad"
     * 
     * @param  nuevaCantidad
     * Número entero que reemplazará valor de "cantidad".
     */
    void setCantidad(int nuevaCantidad);
};

#endif // ITEM_H
