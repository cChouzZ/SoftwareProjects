package edu.uab.farqani9.gui;

import java.io.IOException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/** JavaFX App */
public class App extends Application {

  private static Scene scene;
  private static Stage stage;
  /**
   * Read in FXML description and start the GUI
   *
   * @param stage - where to show
   * @throws IOException - if there are IO problems
   */
  @Override
  public void start(Stage stage) throws IOException {
    Parent root = FXMLLoader.load(getClass().getResource("window1.fxml"));

    Scene scene = new Scene(root);

    stage.setScene(scene);
    stage.show();
  }

  /**
   * Provide a reference to the stage
   *
   * <p>Added to support determining when stage gains focus
   *
   * @return stage
   */
  public static void main(String[] args) {
    launch(args);
  }
}