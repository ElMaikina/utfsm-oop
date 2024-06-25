#ifndef ITEM_H
#define ITEM_H

#include <string>

// Declaración incompleta de Mascota.
class Mascota;

/**
 * @class Item
 * 
 * @brief Clase abstracta padre las subclases: Juguete, Comida y Medicina.
 *
 * Esta clase posee todos los métodos disponibles para cada subclase de Item.
 * Lógica tras la ejecución de funciones miembro (excepto SETers y GETers) varían según sub-clase.
 */
class Item {

private:
    /** Número identificador del Item. */
    int id;

    /** Tipo de Item, define sub-clase. */     
    std::string tipo;

    /** Nombre de Item. */
    std::string nombre;

protected:
    /** Cantidad de Item. */
    int cantidad;
    
public:
    /**
     * @brief Método constructor de Item.
     *
     * @param id        Número identificador del Item.
     * 
     * @param tipo      Tipo de Item, define de sub-clase.
     * 
     * @param nombre    Nombre de Item.
     * 
     * @param cantidad  Cantidad de Item.
     * Default = -1.
     */
    Item(int id, std::string tipo, std::string nombre, int cantidad=-1);

    /**
     * @brief Método destructor de Item.
     *
     * El destructor es virtual para que instancias de subclases de item que se
     * encuentren bajo referencias o punteros de clase Item puedan ser destruidos
     * correctamente.
     */
    virtual ~Item() = default;

    /**
     * @brief Consume Item en Mascota, afectando sus estadísticas.
     *
     * Al consumir: "cantidad" -= 1.
     *
     * @param mascota
     * Mascota que consume el Item.
     */
    virtual void usar(Mascota &mascota) = 0;

    /**
     * @brief Muestra representación de Item en consola.
     *
     * Muestra salida en consola/terminal listado de atributos
     * de instancia de subclase de Item.
     */
    void mostrarItem() const;

    /**
     * @brief Retorna valor entero Id asociado a Item.
     *
     * Id es un identificador numérico para cada Item.
     * 
     * @return Id de Item.
     */
    int getId() const; 

    /**
     * @brief Retorna string Nombre asociado a Item.
     *
     * Nombre es el string que identifica a cada Item.
     * 
     * @return Nombre de Item.
     */
    std::string getNombre() const;

    /**
     * @brief Retorna string Tipo asociado a Item.
     * 
     * Tipo es el string que identifica a qué subclase de Item pertenece la
     * instancia derivada de Item (Juguete, Comida o Medicina).
     * 
     * @return Tipo (subclase) de Item.
     */
    std::string getTipo() const;

    /**
     * @brief Retorna valor entero Cantidad asociado a Item.
     * 
     * Cantidad representa la cantidad de Items disponibles por instancia.
     * 
     * @return Cantidad disponible de Item.
     */
    int getCantidad() const;

    /**
     * @brief Cambia el valor de Cantidad asociada a Item.
     * 
     * Cantidad representa la cantidad de Items disponibles por instancia.
     * 
     * @param nuevaCantidad Número entero que reemplazará valor de Cantidad.
     */
    void setCantidad(int nuevaCantidad);
};

#endif // ITEM_H
