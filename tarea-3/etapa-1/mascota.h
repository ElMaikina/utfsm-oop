#ifndef MASCOTA_H
#define MASCOTA_H


class mascota
{
    public:
        mascota();
        mascota(string nombre, int salud,int energiag, int felicidad);
        virtual ~mascota();
        void mostrarM();
        void penalizar();
        void actEstado();
        void prntEstado();
        void dormir();
        void useItem();
        void pTime();

    protected:

    private:
        string nombre;
        float edad;
        int salud,energia,felicidad;
        //Estado estado;
};

#endif // MASCOTA_H
