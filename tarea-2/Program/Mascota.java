package Program;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;

public class Mascota {
    // salud, energía y felicidad maxima
    public static final int MAX_STATS = 100;
    // salud energía y felicidad mínima
    public static final int MIN_STATS = 0;
    // edad máxima => fin del juego
    public static final int EDAD_MAX = 15;

    private String nombre;
    private float edad = 0;
    private DoubleProperty salud;
    private DoubleProperty energia;
    private DoubleProperty felicidad;
    private String estado;

    public Mascota(String nombre){
        this.nombre = nombre;
        this.salud = new SimpleDoubleProperty(100);
        this.energia = new SimpleDoubleProperty(100);
        this.felicidad = new SimpleDoubleProperty(50);
        this.getEstado();
    }

    public void envejecer(){
        salud.set(salud.get()-5);
        if(salud.get()<MIN_STATS) {
            salud.set(MIN_STATS);
        }

        energia.set(energia.get()-5);
        if(energia.get()<MIN_STATS) {
            energia.set(MIN_STATS);
        }

        felicidad.set(felicidad.get()-5);
        if(felicidad.get()<MIN_STATS) {
            felicidad.set(MIN_STATS);
        }

        edad += 0.5;
        getEstado();
    }

    public void dormir(){
        salud.set(salud.get()+2);
        if(salud.get()>MAX_STATS) {
            salud.set(MAX_STATS);
        }
        energia.set(energia.get()+20);
        if(energia.get()<MIN_STATS) {
            energia.set(MIN_STATS);
        }
        felicidad.set(felicidad.get()+2);
        if(salud.get()<MIN_STATS) {
            salud.set(MIN_STATS);
        }

        edad += 0.5;
    }



    // GETers & SETers
    public String getNombre() {return nombre;}
    public void setNombre(String newNombre) {nombre = newNombre;}

    public Float getEdad() {return Float.valueOf(edad);}
    public void setEdad(float newEdad) {edad = newEdad;}

    public DoubleProperty getSalud() {return salud;}
    public void setSalud(double newSalud) {salud.set(newSalud);} 

    public DoubleProperty getEnergia() {return energia;}
    public void setEnergia(double newEnergia) {energia.set(newEnergia);}

    public DoubleProperty getFelicidad() {return felicidad;}
    public void setFelicidad(double newFelicidad) {felicidad.set(newFelicidad);}

    public String getEstado(){
    // El orden de ejecución de las condiciones respeta el orden de prioridad de los estados de mayor a menor. 
    // De esa manera se cumple que la primera condición que sea verdadera será el estado de mayor prioridad.

        // MUERTO -> edad >= 15 o salud = 0 o energía = 0.
        if (edad>=15 || salud.get()==0 || energia.get()==0) {estado = "MUERTO";}

        // CANSADO -> energia <= 15.
        else if (energia.get() <= 15) {estado = "CANSADO";}

        // ENOJADO -> edad >= 5 y salud <= 30 y energia <= 30.
        else if (edad>=5 && salud.get()<=30 && energia.get()<=30) {estado = "ENOJADO";}

        // HAMBRIENTO -> edad <= 5 y salud <= 20,
        // o también -> 5 < edad < 10 y salud <= 50. 
        else if ((edad<=5 && salud.get() <= 20) || 
            (5<edad && edad<10 && salud.get() <= 50)) {estado = "HAMBRIENTO";}

        // TRISTE -> felicidad <= 20.
        else if (felicidad.get()<=20) {estado = "TRISTE";}

        // FELIZ -> felicidad >= 60;
        else if (felicidad.get()>=60) {estado = "FELIZ";}

        // NEUTRO -> default;
        else {estado = "NEUTRO";}

        return estado;
    }
}
