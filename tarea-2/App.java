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
    //public Mascota mascota = new Mascota("animal");
    // public Mascota mascota = new Mascota(null);
    // public Inventario inventario = new Inventario(mascota);

    public static Mascota mascota;
    public static Inventario inventario;
    public static String toy1 = null;
    public static String toy2 = null;

    @Override
    public void start(Stage primaryStage) throws IOException{

        FXMLLoader fxmlLoader = new FXMLLoader(App.class.getResource("GUI/Scene.fxml"));
        Scene scene = new Scene(fxmlLoader.load());


        Controller controller = fxmlLoader.getController();
        controller.iniciarMascota(mascota);
        controller.iniciarInventario(inventario,toy1,toy2);
    

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
            while ((line = br.readLine()) != null) 
            {
                // Usa el separador para dividir la línea en campos
                String[] data = line.split(cvsSplitByComa);

                // Imprime cada campo
                for (String field : data) {
                    if (mascota.getNombre() == null) {
                        mascota.setNombre(field);
                    }
                    else {
                        String[] subdata = line.split(cvsSplitBySemiColon);
                        System.out.println(subdata[0] + "  " + subdata[1] + "   " + subdata[2] + "  " + subdata[3]);

                        int id = Integer.parseInt(subdata[0]);
                        String tipo = subdata[1];
                        String nombre = subdata[2];
                        int cantidad;
                        String imagen;

                        System.out.println("holaaaaaaaaaa");
            
                        Item newItem;
                        switch (tipo) {
                            case "Jueguete":
                                imagen = subdata[3];
                                if(toy1==null){
                                    toy1 = imagen;
                                }
                                else {
                                    toy2 = imagen;
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
                    for (Item i : inventario.abrirInventario()){
                        System.out.println(i);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        launch(args);
    }
}

