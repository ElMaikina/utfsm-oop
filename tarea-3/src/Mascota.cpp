#include "../headers/Mascota.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;


Mascota::Mascota(string nombre, int salud, int energia, int felicidad) :
    nombre(nombre),
    salud(salud),
    energia(energia),
    felicidad(felicidad) 
{
    this->edad = 0;
    actualizarEstado();
}

void Mascota::penalizar(){
    if (edad<=5 && salud >=10){
        felicidad-=20;
    }
    if (5<edad && edad<=10 && salud<=50){
        felicidad -= 20; energia -= 10;
    }
    if (edad>10 && salud<=50) {
        felicidad -= 30; energia -= 20;
    }
    if(salud<0){
        salud=0;
    }
    if(energia<0){
        energia=0;
    }
    if(felicidad<0){
        felicidad=0;
    }
}


void Mascota::pasarTiempo(){
    if(salud>100){
        salud=100;
    }
    salud -= 5;
    if(salud<0){
        salud=0;
    }
    if(energia>100){
        energia=100;
    }
    energia -= 5;
    if(energia<0){
        energia=0;
    }
    if(felicidad>100){
        felicidad=100;
    }
    felicidad -= 5;
    if(felicidad<0){
        felicidad=0;
    }
    edad += 0.5;
}

void Mascota::actualizarEstado(){
    if (edad==15 || salud==0 || energia==0) {
        estado = Estado::MUERTO;
    }
    else if (energia <= 15) {
        estado = Estado::CANSADO;
    }
    else if (edad>=5 && salud<=30 && energia<=30) {
        estado = Estado::ENOJADO;
    }
    else if ((edad<=5 && salud <= 20) || (5<edad && edad<10 && salud <= 50)) {
        estado = Estado::HAMBRIENTO;
    }
    else if (felicidad<=20) {estado = Estado::TRISTE;}else if (felicidad>=60) {
        estado = Estado::FELIZ;
    }
    else {
        estado = Estado::NEUTRO;
    }
}

string Mascota::getEstado() const {
    switch (estado) {
        case NEUTRO:
            return "Neutro";
        case FELIZ:
            return "Feliz";
        case TRISTE:
            return "Triste";
        case HAMBRIENTO:
            return "Hambriento";
        case ENOJADO:
            return "Enojado";
        case CANSADO:
            return "Cansado";
        case MUERTO:
            return "Muerto";
    }
}

void Mascota::mostrarMascota() const{
    cout  
    << "Nombre: "      << nombre 
    << "\nEdad: "      << edad     
    << "\nSalud: "     << salud     
    << "\nEnergía: "   << energia
    << "\nFelicidad: " << felicidad 
    << "\nEstado: "    << getEstado()
    << "\n" 
    << endl;
}
