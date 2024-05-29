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


/**
 * Controller es la clase que toma justamente el rol de "controlador" en
 * el modelo implementado para esta aplicación, el modelo MVC.
 * Controller se encarga, a grandes rasgos, de mantener una relación directa entre la lógica
 * del modelo y los "request" del usuario, con el resultado de dicha interacción reflejada
 * en nuestra interfaz gráfica.
 * Para ello cuenta con métodos orientados a la interacción entre inventario/mascota y usuario,
 * asignación de acciones para la interfaz y control del flujo del tiempo durante la ejecución.
 */
public class Controller {
    // STAGE
    /**
     * Inicializa el atributo stage.
     * @param stage    referencia de App.primaryStage.
     */
    private Stage stage;
    public void setStage(Stage stage) {
        this.stage = stage;
    }

    // BACKGROUND
    /**
     * @param background    visualizador de la imagen de fondo en la interfaz.
     * @param light         imagen de fondo con luz encendida.
     * @param dark          imagen de fondo con luz apagada.
     * @param estado_luz    estado de luz (true = luz prendida / false = luz apagada).
     */
    @FXML
    private ImageView backround;
    private Image light;
    private Image dark;
    private boolean estado_luz = true;

    // MASCOTA
    /**
     * @param ORIGINALmascota   copia de la mascota creada al iniciar el 
     *                          juego (no usada, guaradada como referencia).
     * @param mascota           instancia de mascota usada para la lógica 
     *                          del juego.
     * @param nombreLabel       nombre de mascota en escena.
     * @param edadLabel         edad de mascota en escena.
     * @param estadoLabel       estado de mascota en escena.
     * @param healthBar         vida de mascota en escena.
     * @param energyBar         energia de mascota en escena.
     * @param happinesBar       felicidad de mascota en escena.
     */
    private Mascota ORIGINALmascota;
    private Mascota mascota;

    @FXML
    private Label nombreLabel;            
    @FXML
    private Label edadLabel;            
    @FXML
    private Label estadoLabel;
    @FXML
    private ProgressBar healthBar;
    @FXML
    private ProgressBar energyBar;
    @FXML
    private ProgressBar happinessBar;

    /**
     * Inicializa todas los nodos relacionados con el display de mascota
     * (vida, energía, felicidad, estado, edad, imagen fondo).
     * Bindea progresión de barras con stats de mascota.
     * Crea copia de la mascota original clonando objeto en referencia
     * ORIGINALmascota.
     * Conecta clase Controller con instancia Mascota (modelo).
     * 
     * @param mascota       mascota original inicializada con config.csv
     */
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
    /**
     * @param ORIGINALinventario   copia del inventario creado al iniciar 
     *                             el juego (no usada, guaradada como referencia).
     * @param inventario           instancia de Inventario usada para lógica del juego.
     * @param idPad                casilleros que guardan los IDs de cada item respecto
     *                             a su Button/Label en interfaz.
     */
    private Inventario ORIGINALinventario;
    private Inventario inventario;
    private int idPad[][] = new int[2][3];

    /**
     * Inicializa idPad tal que así =
     * idPad[0][n] = IDs comida, idPad[1][n] = IDs medicina.                   
     */
    public void iniciarIdPad() {
        int i = 0;                
        int j = 0;
        for(Item item : inventario.abrirInventario()){
            if (item.getTipo().equals("COMIDA")) {
                idPad[0][i] = item.getId();
                i++;                    }
            else if (item.getTipo().equals("MEDICINA")) {
                idPad[1][j] = item.getId();
                j++;
            }
        }
    }

    // BOTONES (COMIDA Y MEDICINA)
    /** 
     * @param food1         = botón de comida 1 (idPad[0][0]).
     * @param food2         = botón de comida 2 (idPad[0][1]).
     * @param food3         = botón de comida 3 (idPad[0][2]).
     * @param med1          = botón de medicina 1 (idPad[1][0]).
     * @param med2          = botón de medicina 2 (idPad[1][1]).
     * @param med3          = botón de medicina 3 (idPad[1][2]).
     * @param foodButtons   = lista de botones de comida.
     * @param medButtons    = lista de botones de medicina.
    */
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
        /** 
     * @param foodLabel1   = display cantidad de comida 1 (idPad[0][0]).
     * @param foodLabel2   = display cantidad de comida 2 (idPad[0][1]).
     * @param foodLabel3   = display cantidad de comida 3 (idPad[0][2]).
     * @param medLabel1    = display cantidad de medicina 1 (idPad[1][0]).
     * @param medLabel2    = display cantidad de medicina 2 (idPad[1][1]).
     * @param medLabel3    = display cantidad de medicina 3 (idPad[1][2]).
     * @param foodLabels   = lista de labels de comida.
     * @param medLabels    = lista de labels de medicina.
    */
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

    // JUGUETES
    /**
     * Son imágenes con un ActionEvent, funcionan como botones.
     * @param toyViewer1  = display en interfaz de juguete 1.
     * @param toy1        = imagen de juguete 1.
     * @param toy1URL     = dirección de imagen juguete 1.
     * @param toyViewer2  = display en interfaz de juguete 2.
     * @param toy2        = imagen de juguete 2.
     * @param toy1URL2    = dirección de imagen juguete 2.
     */
    @FXML
    private ImageView toyViewer1 = new ImageView();
    private Image toy1;
    private String toy1URL;
    @FXML
    private ImageView toyViewer2 = new ImageView();
    private Image toy2;
    private String toy2URL;

    /**
     * Inicializa todos los nodos relacionados con el display 
     * de inventario (imágenes, botones, labels).
     * Crea copia de la mascota original clonando objeto en referencia
     * ORIGINALmascota.
     * Crea nueva instancia de inventario tomando como argumento el atributo mascota.
     * Conecta clase Controller con instancia Inventario (modelo).
     * 
     * @param inventario  =  inventario original instanciado con config.csv.
     * @param image1      =  dirección de imagen de juguete 1.
     * @param image2      =  dirección de imagen de juguete 2.
     */
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


    /**
     * Actualiza cantidad de comida mostrada en interfaz
     * con cada consumo de item (que no sea juguete).
     */
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

    /**
     * Asigna acción setOnAction a cada botón de comida o medicina.
     * Acción setOnAction consume item, actualiza cantidad y anula
     * handler de un botón si su item tiene cantidad = 0;
     */
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

    /**
     * Asigna texto de cada botón en interfaz según el
     * nombre del item correspondiente al ID al que apuntan.
     * Si su item tiene cantidad = 0, entonces el texto se
     * reemplaza por "  ----  ".
     */
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

    /**
     * Asigna a los ImageViewers de ambos juegutes en
     * inventario un handler de tipo MouseEvent (click).
     * Se utiliza el item juguete.
     * No se puede usar juguete con el tiempo detenido.
     * 
     * @param placeHolder = como juguete no se consume ni tiene
     *                      nombre o cantidad en display, es más
     *                      fácil instanciar un Juguete anónimo.
     * @param e           = se activa al clickear sobre su nodo.
     */
    private Item placeHolder = new Juguete(0, null);
    public void jugar(MouseEvent e){
        if(timeline!=null) {inventario.consumirItem(placeHolder);}
    }


    // MENU_ITEMS
    /**
     * @param luzItem = opción en menú para prender o apagar luz.
     * @param start   = opción en menú para iniciar el juego si
     *                  el tiempo está detenido.
     * @param restart = opción en menú para reiniciar juego.
     * @param close   = opción en menú para cerrar juego.
     */

    @FXML
    private MenuItem luzItem;
    @FXML
    private MenuItem start;    
    @FXML
    private MenuItem restart;
    @FXML
    private MenuItem close;

    // TIMELINE
    /**
     * Comienza el transcurso del tiempo y actualiza el estado de mascota
     * cada KeyFrame.
     * Si la luz está apagada ejecuta dormir (recuperación de stats).
     * Si la luz está encendida ejectua envejecer (pérdida de stats).
     * Aumenta la vida de mascota en 0.5 cada KeyFrame (0.5 segundos).
     * 
     * @param timeline  =  linea de tiempo, ejecuta cada ciertos keyframe.
     * @param keyframe  =  define que se ejecuta y cada cuanto se ejecuta 
     *                     durante el transcurso de timeline.                   
     */
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
    
    /**
     * Reinicia el juego (reestablece stats de mascota e inventario
     * con los clones guardados de la mascota e inventario originales).
     * Reinicia timeLine y keyFrame.
     * 
     * @param e = ActionEvent, se activa al clickear menuItem restart.
     */
    public void reset(ActionEvent e) {
        if(timeline!=null){timeline.stop();}
                
        mascota = ORIGINALmascota.clone();
        inventario = ORIGINALinventario.clone();
        iniciarMascota(mascota);
        iniciarInventario(inventario,toy1URL,toy2URL);

        timeline = null;
    }
    
    /**
     * Cierra el juego.
     * 
     * @param e = ActionEvent, se activa al clickear menuItem close.
     */
    public void close(ActionEvent e) {
        stage.close();
    }
        
    /**
     * Apaga o prende la luz, cambiando la imagen de fondo.
     * estado_luz cambia acorde a la acción.
     * 
     * @param e = ActionEvent, se activa al clickear menuItem Apagar/Encender.
     */
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
}
    

