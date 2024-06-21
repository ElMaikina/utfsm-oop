#ifndef MASCOTA_H
#define MASCOTA_Hs
#include "../headers/Item.h"
#include <string>

class Mascota {
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
    Mascota(std::string nombre);
    void mostrarMascota();
    void penalizar();
    void actualizarEstado();
    void printEstado();
    void dormir();
    void pasarTiempo();
};

#endif // MASCOTA_H
