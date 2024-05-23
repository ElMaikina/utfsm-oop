<<<<<<< HEAD
import javafx.util.Duration;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
=======
import javafx.animation.*;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.util.*;
import javafx.util.Duration;
>>>>>>> 4a8f90621dc8e7586698b4865fce07166addcab2

public class Controller 
{
    private Mascota mi_mascota;
    private Inventario inventario;
    private boolean estado_luz = true;
    private Timeline timeline;
<<<<<<< HEAD

    public void start_timer(){

    };
    public void update_status (){};
}
=======
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
        }
        else{
            estado_luz=true;
        }
    }}
 
>>>>>>> 4a8f90621dc8e7586698b4865fce07166addcab2
