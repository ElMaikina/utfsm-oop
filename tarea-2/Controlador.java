import java.io.BufferedReader;
import javafx.animation.*;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;
import javafx.util.*;
import javafx.util.Duration;
import java.io.FileReader;
import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.ProgressBar;

public class Controlador 
{
    private Mascota mi_mascota;
    private Inventario inventario;
    private boolean estado_luz = true;
    private Timeline timeline;
    private KeyFrame keyframe;
    private ProgressBar Saludbar;
    
    // RECOMENDACION: Hacer que todos los chequeos y reglas esten separadas por funciones
    // aqui mismo, asi sera mas facil repartir la pega y resolver los errores

    // Constructor
    public Controlador(Mascota mascota) {
        
        this.mi_mascota=mascota;
    }
    public void updateProgressBarSalud() {
        int s=mi_mascota.salud;
        Saludbar.setProgress(s);
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
    //ciclo de seteo de datos del inventario
    public void si(int capacidad){
        var capacidadInventario = capacidad;
        inventario = new Inventario(capacidadInventario);
        String csvFile = "config.csv";
        String line = "";
        String cvsSplitByComa = ",";
        String cvsSplitBySemiColon = ";";
        String nombreMascota = null;

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) 
            {
                // Usa el separador para dividir la línea en campos
                String[] data = line.split(cvsSplitByComa);

                // Imprime cada campo
                for (String field : data) {
                    if (nombreMascota == null) {
                        nombreMascota = field;
                    }
                    else {
                        String[] subdata = line.split(cvsSplitBySemiColon);

                        int id = Integer.parseInt(subdata[0]);
                        String tipo = subdata[1];
                        String nombre = subdata[2];
                        int cantidad = Integer.parseInt(subdata[3]);
            
                        Item newItem = new Item(id, tipo, nombre, cantidad);
                        inventario.agregarItem(newItem);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        
        
        
        
        
        
        
    }
    
}
 
