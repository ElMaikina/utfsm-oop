#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include "../headers/Item.h"

#define MAX_STATS 100
#define MIN_STATS 0
#define MAX_EDAD  15

enum Estado {
	NEUTRO,
	FELIZ,
	TRISTE,
	HAMBRIENTO,
	ENOJADO,
	CANSADO,
	MUERTO
};
class Mascota {

friend class Juguete;
friend class Comida;
friend class Medicina;

private:
    std::string nombre;
    float edad;
    int salud;
    int energia;
    int felicidad;
    Estado estado;
    
public:
	Mascota(std::string n);
	~Mascota();
    Estado getEstado();
    int getSalud();
    int getEnergia();
    int getFelicidad();
    void setSalud(int s);
    void setEnergia(int e);
    void setFelicidad(int f);
    void mostrarMascota();
    void penalizar();
    void actualizarEstado();
    void printEstado();
    void dormir();
	void usarItem(Item i);
    void pasarTiempo();
};

#endif // MASCOTA_H
