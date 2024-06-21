#include <iostream>
#include <string>
#include "../headers/Comida.h"

Comida::Comida(int i, std::string n, int c) : Item(i, "Comida", n, c) {}
void Comida::usarItem(Mascota &mascota) {};
