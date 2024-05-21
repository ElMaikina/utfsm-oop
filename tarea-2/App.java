import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.layout.StackPane;

public class App extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        /*
        // Create a button
        Button btn = new Button();
        btn.setText("Click me!");
        // Set action when button is clicked
        btn.setOnAction(e -> showMessage());

        // Create a layout and add the button to it
        StackPane root = new StackPane();
        root.getChildren().add(btn);

        // Create the scene and add the layout to it
        Scene scene = new Scene(root, 300, 250);

        // Set the scene to the stage and show the stage
        primaryStage.setScene(scene);
        primaryStage.setTitle("Basic JavaFX App");
        primaryStage.show();
        */
        Parent root = FXMLLoader.load(getClass().getResource("VistaPrincipal.fxml"));
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
