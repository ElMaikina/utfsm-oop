package GUI;

import javafx.fxml.FXML;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.binding.Bindings;
import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuItem;
import javafx.scene.control.ProgressBar;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.util.Duration;
import Program.Inventario;
import Program.Mascota;
import Program.Items.Item;
import Program.Items.Juguete;
import java.util.ArrayList;
import java.awt.*; 
import javax.swing.*; 
import java.awt.event.*; 
import java.net.*; 
  


public class Controller {

    // STAGE
    private Stage stage;
    public void setStage(Stage stage) {
        this.stage = stage;
    }

    // BACKGROUND
    @FXML
    private ImageView backround;
    private Image light;
    private Image dark;
    private boolean estado_luz = true;

    // MASCOTA
    private Mascota ORIGINALmascota;
    private Mascota mascota;
            // LABELS (NOMBRE, EDAD, ESTADO)
            @FXML
            private Label nombreLabel;            
            @FXML
            private Label edadLabel;            
            @FXML
            private Label estadoLabel;

            // BARRAS DE PROGRESIÓN (VIDA, ENERGÍA, FELICIDAD)
            @FXML
            private ProgressBar healthBar;
            @FXML
            private ProgressBar energyBar;
            @FXML
            private ProgressBar happinessBar;

            public void iniciarMascota(Mascota mascota) {
                ORIGINALmascota = mascota;
                this.mascota = ORIGINALmascota.clone();
        
                nombreLabel.setText(mascota.getNombre());
                edadLabel.setText(mascota.getEdad().toString());
                estadoLabel.setText(mascota.getEstado());
                healthBar.progressProperty().bind(Bindings.divide(this.mascota.getSalud(), Mascota.MAX_STATS));
                energyBar.progressProperty().bind(Bindings.divide(this.mascota.getEnergia(), Mascota.MAX_STATS));
                happinessBar.progressProperty().bind(Bindings.divide(this.mascota.getFelicidad(), Mascota.MAX_STATS));
        
                light = new Image(Controller.class.getResourceAsStream("Imagenes/backyard.jpg"));
                dark = new Image(Controller.class.getResourceAsStream("Imagenes/black.jpg"));
            }

    // INVENTARIO
    private Inventario ORIGINALinventario;
    private Inventario inventario;

            // ID PAD (IMAGINAR COMO CASILLAS EN CADA ESPACIO BOTÓN-LABEL)
                // idList[0][n] = id Comida
                // idList[1][n] = id Medicinas
            private int idPad[][] = new int[2][3];
            public void iniciarIdPad() {
                int i = 0;
                int j = 0;
                for(Item item : inventario.abrirInventario()){
                    if (item.getTipo().equals("COMIDA")) {
                        idPad[0][i] = item.getId();
                        i++;
                    }
                    else if (item.getTipo().equals("MEDICINA")) {
                        idPad[1][j] = item.getId();
                        j++;
                    }
                }
            }

            // BOTONES (COMIDA Y MEDICINA)
            @FXML
            private Button food1;
            @FXML
            private Button food2;
            @FXML
            private Button food3;
            @FXML
            private Button med1;
            @FXML
            private Button med2;
            @FXML
            private Button med3;
            ArrayList<Button> foodButtons = new ArrayList<>();
            ArrayList<Button> medButtons = new ArrayList<>();

            // LABELS (CANTIDAD DE COMIDA Y MEDICINA)
            @FXML
            private Label foodLabel1;  
            @FXML
            private Label foodLabel2;
            @FXML
            private Label foodLabel3;
            @FXML
            private Label medLabel1;
            @FXML
            private Label medLabel2;
            @FXML
            private Label medLabel3;
            ArrayList<Label> foodLabels = new ArrayList<>();
            ArrayList<Label> medLabels = new ArrayList<>();

            // JUGUETES (SON IMAGENES CON UN ACTIONEVENT, FUNCIONAN COMO BOTONES)
            @FXML
            private ImageView toyViewer1 = new ImageView();
            private Image toy1;
            private String toy1URL;
            @FXML
            private ImageView toyViewer2 = new ImageView();
            private Image toy2;
            private String toy2URL;

            public void iniciarInventario(Inventario inventario,String image1, String image2) {
                ORIGINALinventario = inventario;
                this.inventario = new Inventario(mascota);
                
                for(Item i : ORIGINALinventario.abrirInventario()){
                    this.inventario.agregarItem(i.clone());
                } 
                toy1URL = image1;
                toy2URL = image2;
                toy1 = new Image(Controller.class.getResourceAsStream(image1));
                toy2 = new Image(Controller.class.getResourceAsStream(image2));
                toyViewer1.setImage(toy1);
                toyViewer2.setImage(toy2);
                iniciarIdPad();
        
                //Labels
                foodLabels.add(foodLabel1);
                foodLabels.add(foodLabel2);
                foodLabels.add(foodLabel3);
                medLabels.add(medLabel1);
                medLabels.add(medLabel2);
                medLabels.add(medLabel3);
                actualizarLabels();

                //Buttons
                foodButtons.add(food1);
                foodButtons.add(food2);
                foodButtons.add(food3);
                medButtons.add(med1);
                medButtons.add(med2);
                medButtons.add(med3);
                for (Button b : foodButtons) {b.setOnAction(null);}
                for (Button b : medButtons) {b.setOnAction(null);}         
                nombrarBotones();
            }

            public void actualizarLabels() {       
                for(int i=0; i<=2; i++){
                    if(idPad[0][i]!=0){
                        int cantidad = inventario.buscarItem(idPad[0][i]).getCantidad();
                        String text = String.format("%d",cantidad);
                        foodLabels.get(i).setText(text);
                    }
                    else{
                        foodLabels.get(i).setText("0");
                    }
                }
                for(int j=0; j<=2; j++){
                    if(idPad[1][j]!=0){
                        int cantidad = inventario.buscarItem(idPad[1][j]).getCantidad();
                        String text = String.format("%d",cantidad);
                        medLabels.get(j).setText(text);
                    }
                    else{
                        medLabels.get(j).setText("0");
                    }
                }
            }

            public void asignarBotones() {
                for(int i=0; i<=2; i++){
                    //Local variable i defined in an enclosing scope must be final or effectively finalJava(536871575)
                    final int index = i;
                    foodButtons.get(index).setOnAction((e)->{
                        if(inventario.buscarItem(idPad[0][index]).getCantidad()==1) {
                            inventario.consumirItem(inventario.buscarItem(idPad[0][index]));
                            idPad[0][index]=0;
                            foodButtons.get(index).setOnAction(null);
                        }
                        else {
                            inventario.consumirItem(inventario.buscarItem(idPad[0][index]));
                        }
                        actualizarLabels();
                        nombrarBotones();
                    });
                }
                for(int j=0; j<=2; j++){
                    final int index = j;
                    medButtons.get(j).setOnAction((e)->{
                        if(inventario.buscarItem(idPad[1][index]).getCantidad()==1){
                            inventario.consumirItem(inventario.buscarItem(idPad[1][index]));
                            idPad[1][index]=0;
                            medButtons.get(index).setOnAction(null);
                        }
                        else {
                            inventario.consumirItem(inventario.buscarItem(idPad[1][index]));
                            
                        }
                        actualizarLabels();
                        nombrarBotones();
                    });
                }
                
            }

            public void nombrarBotones() {
                for(int i=0; i<=2; i++){
                    if(idPad[0][i]!=0){
                        String text = inventario.buscarItem(idPad[0][i]).getNombre();
                        foodButtons.get(i).setText(text);
                    }
                    else{
                        foodButtons.get(i).setText("  ----  ");
                    }
                }
                for(int j=0; j<=2; j++){
                    if(idPad[1][j]!=0){
                        String text = inventario.buscarItem(idPad[1][j]).getNombre();
                        medButtons.get(j).setText(text);
                    }
                    else{
                        medButtons.get(j).setText("  ----  ");
                    }
                }
            }

            private Item placeHolder = new Juguete(0, null);
            public void jugar(MouseEvent e){
                if(timeline!=null) {inventario.consumirItem(placeHolder);}
            }



    // MENÚ
            // MENU_ITEMS
            @FXML
            private MenuItem luzItem;
            @FXML
            private MenuItem start;    
            @FXML
            private MenuItem restart;
            @FXML
            private MenuItem close;

            // TIMELINE
            private Timeline timeline;
            private KeyFrame keyframe;
            public void start() {
                if (timeline==null) {
                    asignarBotones();
                    keyframe = new KeyFrame(Duration.millis(500), event -> {
                        if (!estado_luz) {
                            mascota.dormir();
                        } else {
                            mascota.envejecer();
                        }
                        estadoLabel.setText(mascota.getEstado().toString());
                        edadLabel.setText(mascota.getEdad().toString());
                        if (mascota.getEstado().equals("MUERTO")) {
                            timeline.stop();
                        }
                    });
        
                    timeline = new Timeline(keyframe);
                    timeline.setCycleCount(Timeline.INDEFINITE);
        
                    timeline.play();
                }
            }
        
            public void reset(ActionEvent e) {
                if(timeline!=null){timeline.stop();}
                
                mascota = ORIGINALmascota.clone();
                inventario = ORIGINALinventario.clone();
                iniciarMascota(mascota);
                iniciarInventario(inventario,toy1URL,toy2URL);

                timeline = null;
            }
        
            public void close(ActionEvent e) {
                stage.close();
            }
            
            public void actionLuz(ActionEvent e) {
                if (estado_luz) {
                    estado_luz = false;
                    luzItem.setText("Encender");
                    backround.setImage(dark);
                } else {
                    estado_luz = true;
                    luzItem.setText("Apagar");
                    backround.setImage(light);
                }
            }
            // El boton de ayuda abrira una ventana en el navegador con el repositorio
            public void actionHelp() {
                try {
                    Desktop.getDesktop().browse(new URL("https://github.com/ElMaikina/utfsm-oop/tree/main/tarea-2").toURI());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

    // TEST
        // TEST_BUTTON
        @FXML
        private Button testButton;
        public void test(ActionEvent e){
            for (Item item : ORIGINALinventario.abrirInventario()) {
                System.out.println(item.getNombre() + " - Cantidad: " + item.getCantidad());
            }
            System.out.println(idPad[1][2] + "--------------------");
            for(int i=0; i<=2; i++){
                for(int j=0; j<=2; j++){
                    System.out.println(idPad[1][2]);
                }
            }
        }
}
    

