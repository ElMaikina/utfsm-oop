import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.layout.StackPane;

public class Interfaz extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception 
    {
        // Falta por hacer:
        // 1) Ajustar el "delay" por cada vez que intera el controlador
        // 2) Crear funcion que permita nombrar a la mascota
        // 3) Permitir al jugador salir del juego
        // 4) Crear la interaccion con el interfaz (Usar items, usar menu, etc) OJO: hacerlo fuera del controller
        
        // TODO: Permitir al jugador elegir el nombre de su mascota
        Mascota pet = new Mascota("animal");
        Controller control = new Controller(pet);

        float delay = 0.5f; // Periodo de tiempo en el cual el controlador hace los chequeos
        control.start_timer(delay); // El controlador revisa el estado del juego cada periodo de timepo

        // Vista principal del juego, si necesitan cambiarlo avisarle al Maiki
        Parent root = FXMLLoader.load(getClass().getResource("VistaPrincipal.fxml"));
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
