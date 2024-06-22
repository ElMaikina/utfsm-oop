// Archivo base para pruebas de etapa 3.1
#include <iostream>
#include <string>
#include "../headers/Item.h"
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include "../headers/Mascota.h"

int main(int argc, char **argv) {
    // Crear y mostrar estado inicial de la mascota
    Mascota miMascota("Garfield");
	miMascota.mostrarMascota();

    //// Crear instancias de ítems
    Comida queso(1, "Queso", 5);
    Medicina jarabe(2, "Jarabe", 3);
    Juguete pelota(3, "Pelota");  // Juguete ilimitado

    // Mostrar información de ítems
    queso.mostrarItem();
    jarabe.mostrarItem();
    pelota.mostrarItem();

    // Usar ítems en la mascota y mostrar su estado después de cada uso
    queso.usarItem(miMascota);
    jarabe.usarItem(miMascota);
    pelota.usarItem(miMascota);

    return 0;
}
