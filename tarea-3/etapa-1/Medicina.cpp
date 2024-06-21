#include <iostream>
#include <string>
#include "../headers/Medicina.h"

Medicina::Medicina(int i, std::string n, int c) : Item(i, "Medicina", n, c) {}
void Medicina::usarItem(Mascota &mascota) {};
