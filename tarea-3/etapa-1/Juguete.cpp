#include <iostream>
#include <string>
#include "../headers/Juguete.h"

Juguete::Juguete(int i, std::string n) : Item(i, "Juguete", n, -1) {}
void Juguete::usarItem(Mascota &mascota) {};
