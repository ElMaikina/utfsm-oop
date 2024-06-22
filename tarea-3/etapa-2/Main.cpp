// Archivo base para pruebas de etapa 3.1
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
std::vector<Item> leerItems(const std::string& nombreArchivo) {
    std::vector<Item> items;
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
			if (type.compare("Medicina")) {
            	items.push_back(Medicina(id, nombre, cantidad));
			}
			else if (type.compare("Comida")) {
            	items.push_back(Medicina(id, nombre, cantidad));
			}
			else if (type.compare("Juguete")) {
            	items.push_back(Juguete(id, nombre));
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
    std::string nombreArchivo = "config.csv";

    // Leer la mascota desde el archivo CSV
    Mascota miMascota = leerMascota(nombreArchivo);
	miMascota.mostrarMascota();

    // Crear instancias de ítems
	std::vector<Item> items = leerItems(nombreArchivo);

    // Imprimir la información de los items
    for (const Item& item : items) {
        item.mostrarItem();
    }
    return 0;
}
