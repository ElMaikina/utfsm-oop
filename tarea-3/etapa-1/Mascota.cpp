#include "../headers/Mascota.h"
#include "../headers/Item.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Mascota {
    
private:
    enum Estado {
        NEUTRO,
        FELIZ,
        TRISTE,
        HAMBRIENTO,
        ENOJADO,
        CANSADO,
        MUERTO
    };
    std::string nombre;
    float edad;
    int salud;
    int energia;
    int felicidad;
    Estado estado;

public:
    Mascota(std::string nombre){
        this->nombre = nombre;
        edad = 0;
        salud = 100;
        energia = 100;
        felicidad = 50;
        actualizarEstado();
    }

    void penalizar(){
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

    void dormir(){
        salud += 15;
        if(salud>100){salud=100;}
            felicidad += 15;
        if(felicidad>100){felicidad=100;}
            energia = 100;
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

    void actualizarEstado(){
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

    void Mascota::printEstado(){
        switch(estado){
            case NEUTRO:
                cout << "Estado: (-_-) Meh....." << endl;
                break;
            case FELIZ:
                cout << "Estado: (^_^)/ Weeeeeh!" << endl;
                break;
            case TRISTE:
                cout << "Estado: (._.) snif...." << endl;
                break;
            case HAMBRIENTO:
                cout << "Estado: (0o0) hambre hambre!" << endl;
                break;
            case ENOJADO:
                cout << "Estado: (�w�) grrrr...." << endl;
                break;
            case CANSADO:
                cout << "Estado: (=_=) zzzz...." << endl;
                break;
            case MUERTO:
                cout << "Estado: (x_x) fin del juego" << endl;
                break;
        }
    }

    void mostrarMascota(){
        cout 
        << "Atributos"      
        << "\n-----------"  
        << "\nNombre:"   << nombre 
        << "\nEdad:"     << edad     
        << "\nSalud:"    << salud     
        << "\nfelicidad" << felicidad 
        << estado       
        << endl;
    }
};