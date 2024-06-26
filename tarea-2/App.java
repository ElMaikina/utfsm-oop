import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import GUI.Controller;
import Program.Inventario;
import Program.Mascota;
import Program.Items.Comida;
import Program.Items.Item;
import Program.Items.Juguete;
import Program.Items.Medicina;

public class App extends Application {
    private static Mascota mascota;
    private static Inventario inventario;
    private static String toy1;
    private static String toy2;
    private static Controller controller;


    @Override
    public void start(Stage primaryStage) throws IOException{

        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource("GUI/Scene.fxml"));
        Scene scene = new Scene(fxmlLoader.load());

        controller = fxmlLoader.getController();
        controller.iniciarMascota(mascota);
        controller.iniciarInventario(inventario,toy1,toy2);
        controller.setStage(primaryStage);
    
        primaryStage.setTitle("JavaFX Interface");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        mascota = new Mascota(null);
        inventario = new Inventario(mascota);

        String csvFile = "config.csv";
        String line = "";
        String cvsSplitByComa = ",";
        String cvsSplitBySemiColon = ";";

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                String[] data = line.split(cvsSplitByComa);

                for (String field : data) {
                    if (mascota.getNombre() == null) {
                        mascota.setNombre(field);
                }
                else {
                    String[] subdata = line.split(cvsSplitBySemiColon);
                    int id = Integer.parseInt(subdata[0]);
                    String tipo = subdata[1];
                    String nombre = subdata[2];
                    int cantidad;
                    String imagen;
            
                    Item newItem;
                    switch (tipo) {
                        case "Juguete":
                            imagen = subdata[3];
                            if(App.toy1==null){
                                App.toy1 = imagen;                                
                            }
                            else {
                                App.toy2 = imagen;
                            }
                            newItem = new Juguete(id, nombre);
                            inventario.agregarItem(newItem);
                            break;
                        case "Alimento":
                            cantidad = Integer.parseInt(subdata[3]);
                            newItem = new Comida(id, nombre, cantidad);
                            inventario.agregarItem(newItem);
                            break;
                        case "Medicina":
                            cantidad = Integer.parseInt(subdata[3]);
                            newItem = new Medicina(id, nombre, cantidad);
                            inventario.agregarItem(newItem);
                            break;
                    }
                }
            }
        }
    } catch (IOException e) {
        e.printStackTrace();
    }
        
        launch(args);   
    }
}

