#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

#define MAX_STATS 100
#define MIN_STATS 0
#define MAX_EDAD  15

class Inventario;
/*@Class Mascota 
    @Brief Clase de la mascota del programa*/

class Mascota {

friend class Juguete;/*La clase juguete,comida y medicina pueden acceder a los atributos de mascota*/
friend class Comida;
friend class Medicina;
friend void leerMascota(const std::string& nombreArchivo, Mascota &mascota, Inventario &inventario);/*@brief funcion prototipo para cargar a la mascota 
@param nombreArchivo    nombre del archivo con los datos de mascota
@param &mascota referencia a la mascota cargada
@param &inventario    referencia al inventario de la mascota,cargado desde el archivo*/

private:
    enum Estado {/*@brief enum para establecer los estados de las mascota*/
        NEUTRO,
        FELIZ,
        TRISTE,
        HAMBRIENTO,
        ENOJADO,
        CANSADO,
        MUERTO
    };
    std::string nombre;
    float edad;
    int salud;
    int energia;
    int felicidad;
    Estado estado;
    
public:
    Mascota(std::string nombre="NN", int salud=50, int energia=50, int felicidad=50);/*@brief constructor de la mascota*/
    void mostrarMascota() const;/*@brief imprime los datos de la mascota*/
    void penalizar();/*@brief reduce ciertas estadisticias dependiendo si una está por debajo de lo optimo*/
    void actualizarEstado();/*@brief actualiza el estado de la mascota dependiendo de las estadisticas actuales*/
    std::string getEstado() const;/*@brief imprime el estado en el que se encuentra la mascota actualmente*/
    void pasarTiempo();/*@brief reduce las estadisticas de la mascota a medida que pasa el tiempo*/
};

#endif // MASCOTA_H
