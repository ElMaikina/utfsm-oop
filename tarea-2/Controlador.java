import javafx.animation.*;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.util.*;
import javafx.util.Duration;

public class Controlador 
{
    private Mascota mi_mascota;
    private Inventario inventario;
    private boolean estado_luz = true;
    private Timeline timeline;
    private KeyFrame keyframe;

    // RECOMENDACION: Hacer que todos los chequeos y reglas esten separadas por funciones
    // aqui mismo, asi sera mas facil repartir la pega y resolver los errores

    // Constructor
    public Controlador(Mascota mascota) {
        this.mi_mascota=mascota;
    }

    // Duerme o Despieta la Mascota si hay luz
    public void actionLuz() {
        if (estado_luz=true)
        {
            estado_luz=false;
            mi_mascota.dormir();
        }
        else{
            estado_luz=true;
        }
    }

    // Falta por hacer:

    // 1) Tomar el funcionamiento del Main y replicarlo a continuacion
    // 2) Calcular Salud y Energia de la Mascota
    // 3) Chequear los Alimentos y Medicina en el Inventario
    // 4) Calcular el estado de la Mascota

    // Funcion principal del ciclo del juego
    public void start_timer(float delay) {
        keyframe = new KeyFrame(Duration.seconds(delay),event -> {
            mi_mascota.pasarTiempo();
        });
        timeline = new Timeline(keyframe);
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();
    };
}
 
