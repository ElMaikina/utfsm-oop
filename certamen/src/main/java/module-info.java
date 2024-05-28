module cl.elo {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.media;
    opens cl.elo to javafx.fxml;
    exports cl.elo;
}