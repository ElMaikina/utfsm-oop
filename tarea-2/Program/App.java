package Program;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class App extends Application {

    @Override
    public void start(Stage primaryStage) {
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
    }

    // Method to show a message dialog
    private void showMessage() {
        Alert alert = new Alert(AlertType.INFORMATION);
        alert.setTitle("Information Dialog");
        alert.setHeaderText(null);
        alert.setContentText("Hello, this is a message dialog!");

        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
