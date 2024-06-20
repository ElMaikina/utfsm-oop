#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>

class Mascota {
private:
    std::string nombre;
    float edad;
    int salud
    int energia;
    int felicidad;
    Estado estado;
public:
    //Mascota();
    Mascota(std::string nombre, int salud,int energiag, int felicidad);
    //virtual ~mascota();
    void mostrarMascota();
    void penalizar();
    void actualizarEstado();
    void printEstado();
    void dormir();
    void usarItem();
    void pasarTiempo();
};

#endif // MASCOTA_H
