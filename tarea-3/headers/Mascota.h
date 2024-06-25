#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

#define MAX_STATS 100
#define MIN_STATS 0
#define MAX_EDAD  15

class Mascota {

friend class Juguete;
friend class Comida;
friend class Medicina;

private:
    enum Estado {
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
    Mascota(std::string nombre, int salud=50, int energia=50, int felicidad=50);
    void mostrarMascota() const;
    void penalizar();
    void actualizarEstado();
    std::string getEstado() const;
    void pasarTiempo();
};

#endif // MASCOTA_H
