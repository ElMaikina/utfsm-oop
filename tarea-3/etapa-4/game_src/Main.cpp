#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include "../headers/Inventario.h"
#include "../headers/Mascota.h"

void leerMascota(const std::string& nombreArchivo, Mascota &mascota, Inventario &inventario) {

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        // Devuelve una instancia de Mascota con valores predeterminados
        exit(-1);
    }

    std::string linea;
    while (std::getline(archivo, linea)) {

        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        if (campos.size() == 1) {
            // Crear y devolver una instancia de Mascota
            std::string nombre = campos[0];
            mascota.nombre = nombre;
            continue;
        }

        int id = std::stoi(campos[0]);
        char type = campos[1][0];
        std::string nombre = campos[2];
        int cantidad = std::stoi(campos[3]);

        Item * newItem;

        switch (type) {
            case 'M':
                newItem = new Medicina(id, nombre, cantidad);
                break;
            
            case 'C':
                newItem = new Comida(id, nombre, cantidad);
                break;

            case 'J':
                newItem = new Juguete(id, nombre);
                break;
        }

        newItem->mostrarItem();

        inventario.agregarItem(newItem);
    }
    archivo.close();
}


int main(int argc, char **argv) {
    //Nombre del archivo CSV
    std::string nombreArchivo = "../config.csv";

    Mascota mascota;
    Inventario inventario(mascota);

    leerMascota(nombreArchivo, mascota, inventario);

	// Ciclo general del juego
	bool playing = true;
	float tiempo = 0.0;

	// Ciclo infinito para recibir comandos del jugador
    while (playing) {
        std::cout << "Tiempo de simulacion: " << tiempo << std::endl;
		mascota.mostrarMascota();

		// Muestra el inventario por pantalla
        std::cout << "Inventario:" << std::endl;
		inventario.mostrarInventario();

        int opcion;
        std::cout << "\nSeleccione un ítem del inventario por su ID: ";
        std::cin >> opcion;
        std::cout << std::endl;

		// Interactua con el item elegido
        while (inventario.buscarPorID(opcion) == NULL) {
            std::cout << "\nOpción Inválida. Seleccione un ítem del inventario por su ID: ";
            std::cin >> opcion;
            std::cout << std::endl;
        }
        
		inventario.usarItem(opcion, mascota);

		// Pasa el tiempo de la Mascota y la penaliza en base a eso
		mascota.pasarTiempo();
		mascota.penalizar();
		mascota.actualizarEstado();

		// A continuacion revisa las condiciones de muerte
		
		// Si el Pou esta muerto terminar el juego
		if (mascota.getEstado() == "Muerto") {
        	std::cout << "La Mascota falleció..." << std::endl;
			mascota.mostrarMascota();
			playing = false;
			return 0;
		}

		// Si se acabo el tiempo terminar el juego
		tiempo += 0.5;
		if (tiempo >= 15.0) {
        	std::cout << "Se acabo el tiempo..." << std::endl;
			playing = false;
			return 0;
		}
    }
    return 0;
}
