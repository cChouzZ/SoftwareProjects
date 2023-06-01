module edu.uab.farqani9.gui {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.base;

    opens edu.uab.farqani9.gui to javafx.fxml;
    exports edu.uab.farqani9.gui;
}
