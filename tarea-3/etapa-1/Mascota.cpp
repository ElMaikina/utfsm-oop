#include <iostream>
#include <string>
#include "../headers/Item.h"
#include "../headers/Mascota.h"

Mascota::Mascota(std::string n){
	nombre = n;
	edad = 0;
	salud = 100;
	energia = 100;
	felicidad = 50;
	actualizarEstado();
}
Mascota::~Mascota(){

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
	};
	if(energia<0){
		energia=0;
	};
	if(felicidad<0){
		felicidad=0;
	};

}
void Mascota::dormir(){
	salud += 15;
	if(salud>100){salud=100;}
		felicidad += 15;
	if(felicidad>100){felicidad=100;}
		energia = 100;
}
void Mascota::usarItem(Item i){
	std::string type = i.getTipo();
	if (type.compare("Medicina")) {
		salud +=40;
		std::cout<<"Aplicando medicina"<<type<<std::endl;
		return;
	}
	if (type.compare("Comida")) {
		salud +=20;
		energia+=20;
		std::cout<<"Dando comida"<<type<<std::endl;
		return;
	}
	if (type.compare("Juguete")) {
		felicidad +=30;
		std::cout<<"Jugando con"<<type<<std::endl;
		return;
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
		estado = MUERTO;
	}
	else if (energia <= 15) {
		estado = CANSADO;
	}
	else if (edad>=5 && salud<=30 && energia<=30) {
		estado = ENOJADO;
	}
	else if ((edad<=5 && salud <= 20) || (5<edad && edad<10 && salud <= 50)) {
		estado = HAMBRIENTO;
	}
	else if (felicidad<=20) {
		estado = TRISTE;
	}
	else if (felicidad>=60) {
		estado = FELIZ;
	}
	else {
		estado = NEUTRO;
	};
}
void Mascota::printEstado(){
switch(estado){
	case NEUTRO:
		std::cout << "Estado: (-_-) Meh....." << std::endl;
		break;
	case FELIZ:
		std::cout << "Estado: (^_^)/ Weeeeeh!" << std::endl;
		break;
	case TRISTE:
		std::cout << "Estado: (._.) snif...." << std::endl;
		break;
	case HAMBRIENTO:
		std::cout << "Estado: (0o0) hambre hambre!" << std::endl;
		break;
	case ENOJADO:
		std::cout << "Estado: (�w�) grrrr...." << std::endl;
		break;
	case CANSADO:
		std::cout << "Estado: (=_=) zzzz...." << std::endl;
		break;
	case MUERTO:
		std::cout << "Estado: (x_x) fin del juego" << std::endl;
		break;
	default:
		std::cout << "Estado desconocido" << std::endl;
		break;
	}
}
void Mascota::mostrarMascota(){
	std::cout<<"Atributos"<<std::endl;
	std::cout<<"-----------"<<std::endl;
	std::cout<<"Nombre:"<<nombre<<std::endl;
	std::cout<<"Edad:"<<edad<<std::endl;
	std::cout<<"Salud:"<<salud<<std::endl;
	std::cout<<"felicidad"<<felicidad<<std::endl;
	std::cout<<estado<<std::endl;
};
