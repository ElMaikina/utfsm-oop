package Program;

public class Mascota {
    // salud, energía y felicidad maxima
    public static final int MAX_STATS = 100;
    // salud energía y felicidad mínima
    public static final int MIN_STATS = 0;
    // edad máxima => fin del juego
    public static final int EDAD_MAX = 15;

    private String nombre;
    private float edad;
    private int salud;
    private int energia;
    private int felicidad;
    private Estado estado;

    public Mascota(String nombre){
        this.nombre = nombre;
        this.edad = 0;
        this.salud = 100;
        this.energia = 100;
        this.felicidad = 50;
        this.getEstado();
    }

    public void envejecer(){
        salud -= 5;
        energia -= 5;
        felicidad -=5;
    }

    public void dormir(){
        salud += 2;
        energia += 20;
        felicidad += 2;
    }



    // GETers & SETers
    public String getNombre() {return nombre;}

    public float getEdad() {return edad;}
    public void setEdad(int newEdad) {edad = newEdad;}

    public int getSalud() {return salud;}
    public void setSalud(int newSalud) {salud = newSalud;} 

    public int getEnergia() {return energia;}
    public void setEnergia(int newEnergia) {energia = newEnergia;}

    public int getFelicidad() {return felicidad;}
    public void setFelicidad(int newFelicidad) {felicidad = newFelicidad;}

    public Estado getEstado(){
    // El orden de ejecución de las condiciones respeta el orden de prioridad de los estados de mayor a menor. 
    // De esa manera se cumple que la primera condición que sea verdadera será el estado de mayor prioridad.

        // MUERTO -> edad >= 15 o salud = 0 o energía = 0.
        if (edad==15 || salud==0 || energia==0) {estado = Estado.MUERTO;}

        // CANSADO -> energia <= 15.
        else if (energia <= 15) {estado = Estado.CANSADO;}

        // ENOJADO -> edad >= 5 y salud <= 30 y energia <= 30.
        else if (edad>=5 && salud<=30 && energia<=30) {estado = Estado.ENOJADO;}

        // HAMBRIENTO -> edad <= 5 y salud <= 20,
        // o también -> 5 < edad < 10 y salud <= 50. 
        else if ((edad<=5 && salud <= 20) || (5<edad && edad<10 && salud <= 50)) {estado = Estado.HAMBRIENTO;}

        // TRISTE -> felicidad <= 20.
        else if (felicidad<=20) {estado = Estado.TRISTE;}

        // FELIZ -> felicidad >= 60;
        else if (felicidad>=60) {estado = Estado.FELIZ;}

        // NEUTRO -> default;
        else {estado = Estado.NEUTRO;}

        return estado;
    }

    private enum Estado {
        NEUTRO,     
        FELIZ,       
        TRISTE,     
        HAMBRIENTO,
        ENOJADO,     
        CANSADO,     
        MUERTO                       
    }
}
