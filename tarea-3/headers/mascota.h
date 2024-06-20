#ifndef MASCOTA_H
#define MASCOTA_H
using namespace std

class mascota
{
    public:
        mascota();
        mascota(string nombre, int salud,int energia, int felicidad,float edad);
        virtual ~mascota();
        void mostrarMascota();
        void penalizar();
        void actualizarEstado();
        void printEstado();
        void dormir();
        void useItem();
        void pasarTiempo();
        enum Estado{
            NEUTRO,
            FELIZ,
            TRISTE,
            HAMBRIENTO,
            ENOJADO,
            CANSADO,
            MUERTO
            };

    protected:

    private:
        string nombre;
        float edad;
        int salud,energia,felicidad;
        Estado estado;

};

#endif // MASCOTA_H
