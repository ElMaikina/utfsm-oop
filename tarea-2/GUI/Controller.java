package GUI;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.binding.Bindings;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuItem;
import javafx.scene.control.ProgressBar;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.util.Duration;
import Program.Mascota;
import Program.Items.Item;
import Program.Items.Juguete;

import java.util.ArrayList;


import Program.Inventario;


public class Controller {
    private Mascota mascota;
    private Inventario inventario;
    private Stage stage;
    private int idPad[][] = new int[2][3];
    // idList[0][n] = lista de Comida
    // idList[1][n] = lista de Medicina
    private Timeline timeline;
    private KeyFrame keyframe;   
    private boolean estado_luz = true;

    @FXML
    private MenuItem luzItem;
    @FXML
    private MenuItem start;    
    @FXML
    private MenuItem close;
    @FXML
    private Label stateLabel;
    @FXML
    private Label edadLabel;
    @FXML
    private Label nombreLabel;
    @FXML
    private ImageView backround;
    private Image light;
    private Image dark;
    @FXML
    private ProgressBar healthBar;
    @FXML
    private ProgressBar energyBar;
    @FXML
    private ProgressBar happinessBar;

    // Inventario
    @FXML
    private Button food1;
    @FXML
    private Label foodLabel1;
    @FXML
    private Button food2;
    @FXML
    private Label foodLabel2;
    @FXML
    private Button food3;
    @FXML
    private Label foodLabel3;
    @FXML
    private Button med1;
    @FXML
    private Label medLabel1;
    @FXML
    private Button med2;
    @FXML
    private Label medLabel2;
    @FXML
    private Button med3;
    @FXML
    private Label medLabel3;
    @FXML
    private ImageView toyViewer1 = new ImageView();
    private Image toy1;
    @FXML
    private ImageView toyViewer2 = new ImageView();
    private Image toy2;


    @FXML
    private Button testButton;

    public void test(ActionEvent e){
        for (Item item : inventario.abrirInventario()) {
            System.out.println(item.getNombre() + " - Cantidad: " + item.getCantidad());
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                System.out.println(idPad[i][j]);
            }
        }
    }


    public void setStage(Stage stage) {
        this.stage = stage;
    }

    public void iniciarMascota(Mascota mascota) {
        this.mascota = mascota;
        nombreLabel.setText(mascota.getNombre());

        healthBar.progressProperty().bind(Bindings.divide(mascota.getSalud(), Mascota.MAX_STATS));
        energyBar.progressProperty().bind(Bindings.divide(mascota.getEnergia(), Mascota.MAX_STATS));
        happinessBar.progressProperty().bind(Bindings.divide(mascota.getFelicidad(), Mascota.MAX_STATS));

        light = new Image(Controller.class.getResourceAsStream("Imagenes/backyard.jpg"));
        dark = new Image(Controller.class.getResourceAsStream("Imagenes/black.jpg"));
    }

    

    ArrayList<Label> foodLabels = new ArrayList<>();
    ArrayList<Label> medLabels = new ArrayList<>();
    ArrayList<Button> foodButtons = new ArrayList<>();
    ArrayList<Button> medButtons = new ArrayList<>();

    public void iniciarInventario(Inventario inventario, String image1, String image2) {
        this.inventario = inventario;   
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

        //Buttons
        foodButtons.add(food1);
        foodButtons.add(food2);
        foodButtons.add(food3);
        medButtons.add(med1);
        medButtons.add(med2);
        medButtons.add(med3);

        actualizarLabels();
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


    public void comer1(ActionEvent e){
        if(inventario.buscarItem(idPad[0][0]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[0][0]));
            idPad[0][0]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[0][0]));
        }
        actualizarLabels();
    }
    public void comer2(ActionEvent e){
        if(inventario.buscarItem(idPad[0][1]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[0][1]));
            idPad[0][1]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[0][1]));
        }
        actualizarLabels();
    }
    public void comer3(ActionEvent e){
        if(inventario.buscarItem(idPad[0][2]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[0][2]));
            idPad[0][2]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[0][2]));
        }
        actualizarLabels();
    }
    public void sanar1(ActionEvent e){
        if(inventario.buscarItem(idPad[1][0]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[1][0]));
            idPad[1][0]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[1][0]));
        }
        actualizarLabels();
    }
    public void sanar2(ActionEvent e){
        if(inventario.buscarItem(idPad[1][1]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[1][1]));
            idPad[1][1]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[1][1]));
        }
        actualizarLabels();
    }
    public void sanar3(ActionEvent e){
        if(inventario.buscarItem(idPad[1][2]).getCantidad()==1){
            inventario.consumirItem(inventario.buscarItem(idPad[1][2]));
            idPad[1][2]=0;
        }
        else {
            inventario.consumirItem(inventario.buscarItem(idPad[1][2]));
        }
        actualizarLabels();
    }

    private Item placeHolder = new Juguete(0, null);
    public void jugar(MouseEvent e){
        inventario.consumirItem(placeHolder);
        actualizarLabels();
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

    // Funcion principal del ciclo del juego
    public void start_timer() {
        keyframe = new KeyFrame(Duration.millis(500), event -> {

            if (!estado_luz) {
                mascota.dormir();
            } else {
                mascota.envejecer();
            }

            stateLabel.setText(mascota.getEstado().toString());
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
    

