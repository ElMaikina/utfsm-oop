#include "mascota.h"

mascota::mascota()
{
    felicidad=0;
    energia=0;
    salud=0;
    estado.NEUTRO


}
mascota::mascota(string n,int hp, int Rng, int f,float e){
    nombre=n;
    salud=hp;
    energia=Rng;
    felicidad=f;
    edad=e;
    actEstado();
}
void mascota::penalizar(){
    if (edad<=5 && salud >=10){
       felicidad-=20;
    };
    else if (5<edad && edad<=10 && salud<=50) {
            felicidad -= 20; energia -= 10;};
    else if (edad>10 && salud<=50) {felicidad -= 30; energia -= 20;};
    if(salud<0){salud=0;};
    if(energia<0){energia=0;};
    if(felicidad<0){felicidad=0;};

}
void mascota::dormir(){
     salud += 15;
     if(salud>100){salud=100;}
     felicidad += 15;
     if(felicidad>100){felicidad=100;}
     energia = 100;




}
void mascota::useItem(Item item){
    string type= item.get_type;
    switch(type){
        case "Medicina"{
            salud +=40;
            cout<<"Aplicando medicina"<<type<<endl;
            break;
        }
        case "Comida"{
            salud +=20;
            energia+=20;

            cout<<"Dando comida"<<type<<endl;
            break;
        }
        case "Juguete"{
            felicidad +=30;
            cout<<"Jugando con"<<type<<endl;
            break;
        }
    }
}
void mascota::pasarTiempo(){
        if(salud>100){salud=100;}
        salud -= 5;
        if(salud<0){salud=0;}

        if(energia>100){energia=100;}
        energia -= 5;
        if(energia<0){energia=0;}

        if(felicidad>100){felicidad=100;}
        felicidad -= 5;
        if(felicidad<0){felicidad=0;}

        edad += 0.5;

}
void mascota::actualizarEstado{
    if (edad==15 || salud==0 || energia==0) {estado = Estado.MUERTO;}
    else if (energia <= 15) {estado = Estado.CANSADO;}
    else if (edad>=5 && salud<=30 && energia<=30) {estado = Estado.ENOJADO;}
    else if ((edad<=5 && salud <= 20) || (5<edad && edad<10 && salud <= 50)) {estado = Estado.HAMBRIENTO;}
    else if (felicidad<=20) {estado = Estado.TRISTE;}else if (felicidad>=60) {estado = Estado.FELIZ;}
    else {estado = Estado.NEUTRO;};
}
void mascota::printEstado(){
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
            cout << "Estado: (ôwô) grrrr...." << endl;
            break;
        case CANSADO:
            cout << "Estado: (=_=) zzzz...." << endl;
            break;
        case MUERTO:
            cout << "Estado: (x_x) fin del juego" << endl;
            break;
        default:
            cout << "Estado desconocido" << endl;
            break;
    }
}





void mascota::mostrarMascot(){
      cout<<"Atributos"<<endl;
      cout<<"-----------"<<endl;
      cout<<"Nombre:"<<+nombre<<endl;
      cout<<"Edad:"<<edad<<endl;
      cout<<"Salud:"<<salud<<endl;
      cout<<"felicidad"<<felicidad<<endl;
      cout<<estado<<endl;
}








mascota::~mascota()
{
    //dtor
}
