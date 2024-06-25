// Archivo base para pruebas de etapa 3.1
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include "../headers/Item.h"
#include "../headers/Juguete.h"
#include "../headers/Comida.h"
#include "../headers/Medicina.h"
#include "../headers/Inventario.h"
#include "../headers/Mascota.h"

// Función para leer el archivo CSV y crear una única instancia de Mascota
Mascota leerMascota(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        // Devuelve una instancia de Mascota con valores predeterminados
        return Mascota("");
    }
    std::string linea;
    if (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string campo;
        std::vector<std::string> campos;

        while (std::getline(ss, campo, ',')) {
            campos.push_back(campo);
        }
        if (campos.size() == 1) {
            // Crear y devolver una instancia de Mascota
            std::string nombre = campos[0];
            return Mascota(nombre);
        } else {
            std::cerr << "Línea con formato incorrecto: " << linea << std::endl;
        }
    }
    archivo.close();
    // Devuelve una instancia de Mascota con valores predeterminados en caso de error
    return Mascota("");
}


// Función para leer el archivo CSV desde la segunda línea y crear una lista de Items
//std::vector<Item> leerItems(const std::string& nombreArchivo) {
std::vector<std::shared_ptr<Item>> leerItems(const std::string& nombreArchivo) {
    //std::vector<Item> items;
	std::vector<std::shared_ptr<Item>> items;

    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return items;
    }

    std::string linea;
    // Leer la primera línea y descartarla (asumimos que es el encabezado)
    std::getline(archivo, linea);

    // Leer el resto de las líneas
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string campo;

        std::vector<std::string> campos;
        while (std::getline(ss, campo, ';')) {
            campos.push_back(campo);
        }

        if (campos.size() == 4) {
            // Convertir los campos al tipo adecuado
            int id = std::stoi(campos[0]);
            std::string type = campos[1];
            std::string nombre = campos[2];
            int cantidad = std::stoi(campos[3]);

            // Crear una instancia de Item y añadirla al vector
			if (type == "Medicina") {
            	items.push_back(std::make_shared<Medicina>(id, nombre, cantidad));
			}
			else if (type == "Comida") {
            	items.push_back(std::make_shared<Comida>(id, nombre, cantidad));
			}
			else if (type == "Juguete") {
            	items.push_back(std::make_shared<Juguete>(id, nombre));
			}
        } else {
            std::cerr << "Línea con formato incorrecto: " << linea << std::endl;
        }
    }

    archivo.close();
    return items;
}


int main(int argc, char **argv) {
    // Nombre del archivo CSV
    std::string nombreArchivo = "../config.csv";

    // Leer la mascota desde el archivo CSV
    Mascota mascota = leerMascota(nombreArchivo);

    // Crear instancias de ítems
	//std::vector<Item> items = leerItems(nombreArchivo);
	std::vector<std::shared_ptr<Item>> items = leerItems(nombreArchivo);

	int cantidadItems = (int)items.size();
	Inventario inventario(cantidadItems);

	//for (Item& item : items) {
	for (const auto& item : items) {
		inventario.agregarItem(item);
	}

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
		inventario.usarItem(opcion, mascota);

		// Pasa el tiempo de la Mascota y la penaliza en base a eso
		mascota.pasarTiempo();
		mascota.penalizar();
		mascota.actualizarEstado();

		// A continuacion revisa las condiciones de muerte
		
		// Si el Pou esta muerto terminar el juego
		if (mascota.getEstado() == "MUERTO") {
        	std::cout << "La Mascota falleció..." << std::endl;
			mascota.mostrarMascota();
			playing = false;
			return 0;
		}

		// Si se acabo el tiempo terminar el juego
		tiempo += 0.5;
		if (tiempo > 15.0) {
        	std::cout << "Se acabo el tiempo..." << std::endl;
			playing = false;
			return 0;
		}
    }
    return 0;
}
