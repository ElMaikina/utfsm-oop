import javafx.animation.*;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.util.*;
import javafx.util.Duration;

public class Controller 
{
    private Mascota mi_mascota;
    private Inventario inventario;
    private boolean estado_luz = true;
    private Timeline timeline;
    private KeyFrame keyframe;
    public Controller (Mascota mascota){
        this.mi_mascota=mascota;
    
    }
 

    public void start_timer(){
        keyframe = new KeyFrame(Duration.seconds(0.5),event -> {
            mi_mascota.pasarTiempo();
        });
        timeline = new Timeline(keyframe);
        timeline.setCycleCount(Timeline.INDEFINITE);
        timeline.play();
        

    };
    public void actionLuz(){
        if (estado_luz=true){
            estado_luz=false;
            mi_mascota.dormir();
        }
        else{
            estado_luz=true;
        }
    }}
 
