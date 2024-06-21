// Archivo base para pruebas de etapa 3.1
#include <iostream>
#include <string>
#include "../headers/Mascota.h"
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"

int main(int argc, char **argv) {
    // Crear y mostrar estado inicial de la mascota
    Mascota miMascota("Garfield");
	miMascota.mostrarMascota();
    //miMascota.mostrarEstado();

   	//// Crear instancias de ítems
    //Comida queso(1, "Queso", 5);
    //Medicina jarabe(2, "Jarabe", 3);

    // Crear instancias de ítems
    Comida queso(1, "Queso", 5);
    Medicina jarabe(2, "Jarabe", 3);
    Juguete pelota(3, "Pelota");  // Juguete ilimitado

    //// Mostrar información de ítems
    //queso.mostrarItem();
    //jarabe.mostrarItem();
    //pelota.mostrarItem();

    //// Usar ítems en la mascota y mostrar su estado después de cada uso
    //queso.usar(miMascota);
    //jarabe.usar(miMascota);
    //pelota.usar(miMascota);

    return 0;
}
