/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package edu.uab.farqani9.gui;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author Ahmed Al Farqani <farqani9@uab.edu>
 */
public class MainController implements Initializable {
  //  private Dispatch dispatch = new Dispatch();
  @FXML private Stage stage;

  @FXML private Button start;
  @FXML private Button submit;
  @FXML private Button back1;
  @FXML private Button back2;
  @FXML private Button back3;
  @FXML private Button back4;
  @FXML private Button back5;
  @FXML private Button back6;
  @FXML private Button submit2;
  @FXML private Button submit3;
  @FXML private TextField voterUidTF;
  @FXML private CheckBox pa1;
  @FXML private CheckBox pb1;
  @FXML private CheckBox pc1;
  @FXML private CheckBox pa2;
  @FXML private CheckBox pb2;
  @FXML private CheckBox pc2;
  @FXML private CheckBox pa3;
  @FXML private CheckBox pb3;
  @FXML private CheckBox pc3;
  @FXML private CheckBox ta1;
  @FXML private CheckBox tb1;
  @FXML private CheckBox tc1;
  @FXML private CheckBox ta2;
  @FXML private CheckBox tb2;
  @FXML private CheckBox tc2;
  @FXML private CheckBox ta3;
  @FXML private CheckBox tb3;
  @FXML private CheckBox tc3;

  @FXML private CheckBox seca1;
  @FXML private CheckBox secb1;
  @FXML private CheckBox secc1;
  @FXML private CheckBox seca2;
  @FXML private CheckBox secb2;
  @FXML private CheckBox secc2;
  @FXML private CheckBox seca3;
  @FXML private CheckBox secb3;
  @FXML private CheckBox secc3;
  @FXML private Text results;

  private ArrayList<String> presidentFC;
  private ArrayList<String> presidentSC;
  private ArrayList<String> presidentTC;

  private ArrayList<String> TreasureFC;
  private ArrayList<String> TreasureSC;
  private ArrayList<String> TreasureTC;

  private ArrayList<String> SecretaryFC;
  private ArrayList<String> SecretarySC;
  private ArrayList<String> SecretaryTC;

  private ArrayList<String> voters;

  private String voterUID;

  /** Construct the controller */
  public MainController() {

    //    voterUidTF.setText("uid");
    voters = new ArrayList<>();

    voters.add("ahmed");
    voters.add("123");

    presidentFC = new ArrayList<>();
    presidentSC = new ArrayList<>();
    presidentTC = new ArrayList<>();

    TreasureFC = new ArrayList<>();
    TreasureSC = new ArrayList<>();
    TreasureTC = new ArrayList<>();

    SecretaryFC = new ArrayList<>();
    SecretarySC = new ArrayList<>();
    SecretaryTC = new ArrayList<>();
  }

  /**
   * @param url
   * @param rb
   */
  @Override
  public void initialize(URL url, ResourceBundle rb) {}

  public void startButton() throws IOException {

    Parent startParent = FXMLLoader.load(getClass().getResource("window2.fxml"));
    Scene LoginScene = new Scene(startParent);

    // This line gets the Stage information
    Stage window = (Stage) start.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
    System.out.println(voters);
  }

  @FXML
  public void appendVoter() { // must press enter to add

    if (voterUidTF.getText() != null) {

      voters.add(voterUidTF.getText());

      System.out.println(voters);
    }
  }
  //	public void setVoted(){
  //
  //
  //
  //		if (voters.contains(voterUID) == false){
  //			voters.add(voterUID);
  //		}
  //		}
  //
  public boolean verifiedVoter() {

    if (voters.contains(voterUidTF.getText()) == true) {
      return true; // passed

    } else {
      return false;
    }
  }

  public void submitButton() throws IOException {

    if (verifiedVoter() == false) {

      Parent submitParent = FXMLLoader.load(getClass().getResource("error1.fxml"));
      Scene errorScene = new Scene(submitParent);

      // This line gets the Stage information
      Stage window = (Stage) submit.getScene().getWindow();

      window.setScene(errorScene);
      window.show();
      System.out.println(voters);

    } else {
      Parent submitParent = FXMLLoader.load(getClass().getResource("window3.fxml"));
      Scene ballotScene = new Scene(submitParent);

      // This line gets the Stage information
      Stage window = (Stage) submit.getScene().getWindow();

      window.setScene(ballotScene);
      window.show();

      System.out.println(voters);
    }
  }

  public void back1Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window1.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back1.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void sumbit2Button() throws IOException {

    if (presidentFC.equals(presidentSC)
        || presidentFC.equals(presidentTC)
        || presidentSC.equals(presidentTC)) {
      Parent BallotParent = FXMLLoader.load(getClass().getResource("error2.fxml"));
      // Include the error2.fxml page becasue this button has two cases. Success, go to window1.fxml
      // and Failure, go to error2.fxml

      Scene startScene = new Scene(BallotParent);

      // This line gets the Stage information
      Stage window = (Stage) submit2.getScene().getWindow();
      window.setScene(startScene);
      window.show();

      //		} else if (TreasureFC.equals(TreasureSC) || TreasureFC.equals(TreasureTC) ||
      // presidentSC.equals(TreasureTC)) {
      //			Parent BallotParent = FXMLLoader.load(getClass().getResource("error2.fxml"));
      //			// Include the error2.fxml page becasue this button has two cases. Success, go to
      // window1.fxml and Failure, go to error2.fxml
      //			Scene startScene = new Scene(BallotParent);
      //
      //			// This line gets the Stage information
      //			Stage window = (Stage) submit2.getScene().getWindow();
      //			window.setScene(startScene);
      //			window.show();
      //		} else if (SecretaryFC.equals(SecretarySC) || SecretaryFC.equals(SecretaryTC) ||
      // SecretarySC.equals(SecretaryTC)) {
      //			Parent BallotParent = FXMLLoader.load(getClass().getResource("error2.fxml"));
      //			// Include the error2.fxml page becasue this button has two cases. Success, go to
      // window1.fxml and Failure, go to error2.fxml
      //			Scene startScene = new Scene(BallotParent);
      //
      //			// This line gets the Stage information
      //			Stage window = (Stage) submit2.getScene().getWindow();
      //			window.setScene(startScene);
      //			window.show();
    } else {
      Parent BallotParent = FXMLLoader.load(getClass().getResource("window4.fxml"));
      // Include the error2.fxml page becasue this button has two cases. Success, go to window1.fxml
      // and Failure, go to error2.fxml
      Scene startScene = new Scene(BallotParent);

      // This line gets the Stage information
      Stage window = (Stage) submit2.getScene().getWindow();

      window.setScene(startScene);
      window.show();

      System.out.println(presidentFC);
      System.out.println(presidentSC);
      System.out.println(presidentTC);

      System.out.println(TreasureFC);
      System.out.println(TreasureSC);
      System.out.println(TreasureTC);

      System.out.println(SecretaryFC);
      System.out.println(SecretarySC);
      System.out.println(SecretaryTC);
    }
  }

  public void sumbit3Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window5.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) submit3.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void back2Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window2.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back2.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void back3Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window2.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back3.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void back4Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window3.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back4.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void back5Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window3.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back5.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void back6Button() throws IOException {

    Parent errorParent = FXMLLoader.load(getClass().getResource("window1.fxml"));
    Scene LoginScene = new Scene(errorParent);

    // This line gets the Stage information
    Stage window = (Stage) back6.getScene().getWindow();

    window.setScene(LoginScene);
    window.show();
  }

  public void FirstPresisdentChoice() {
    if (pa1.isSelected()) {
      presidentFC.add("A");
      pa2.setDisable(true);
      pa3.setDisable(true);

    } else if (pb1.isSelected()) {
      presidentFC.add("B");
      pb2.setDisable(true);
      pb3.setDisable(true);

    } else if (pc1.isSelected()) {
      presidentFC.add("C");
      pc2.setDisable(true);
      pc3.setDisable(true);
    }
  }

  public void SecondPresisdentChoice() {
    if (pa2.isSelected()) {
      presidentSC.add("A");
      pa1.setDisable(true);
      pa3.setDisable(true);

    } else if (pb2.isSelected()) {
      presidentSC.add("B");
      pb1.setDisable(true);
      pb3.setDisable(true);

    } else if (pc2.isSelected()) {
      presidentSC.add("C");
      pc1.setDisable(true);
      pc3.setDisable(true);
    }
  }

  public void ThirdPresisdentChoice() {
    if (pa3.isSelected()) {
      presidentTC.add("A");
      pa1.setDisable(true);
      pa2.setDisable(true);

    } else if (pb3.isSelected()) {
      presidentTC.add("B");
      pb1.setDisable(true);
      pb2.setDisable(true);

    } else if (pc3.isSelected()) {
      presidentTC.add("C");
      pc1.setDisable(true);
      pc2.setDisable(true);
    }
  }

  public void FirstTreasureChoice() {
    if (ta1.isSelected()) {
      TreasureFC.add("A");
      ta2.setDisable(true);
      ta3.setDisable(true);

    } else if (tb1.isSelected()) {
      TreasureFC.add("B");
      tb2.setDisable(true);
      tb3.setDisable(true);

    } else if (tc1.isSelected()) {
      TreasureFC.add("C");
      tc2.setDisable(true);
      tc3.setDisable(true);
    }
  }

  public void SecondTreasureChoice() {
    if (ta2.isSelected()) {
      TreasureSC.add("A");
      ta1.setDisable(true);
      ta3.setDisable(true);

    } else if (tb2.isSelected()) {
      TreasureSC.add("B");
      tb1.setDisable(true);
      tb3.setDisable(true);

    } else if (tc2.isSelected()) {
      TreasureSC.add("C");
      tc1.setDisable(true);
      tc3.setDisable(true);
    }
  }

  public void ThirdTreasureChoice() {
    if (ta3.isSelected()) {
      TreasureTC.add("A");
      ta1.setDisable(true);
      ta2.setDisable(true);

    } else if (tb3.isSelected()) {
      TreasureTC.add("B");
      tb1.setDisable(true);
      tb2.setDisable(true);

    } else if (tc3.isSelected()) {
      TreasureTC.add("C");
      tc1.setDisable(true);
      tc2.setDisable(true);
    }
  }

  public void FirstSecretaryChoice() {
    if (seca1.isSelected()) {
      SecretaryFC.add("A");
      seca2.setDisable(true);
      seca3.setDisable(true);

    } else if (secb1.isSelected()) {
      SecretaryFC.add("B");
      secb2.setDisable(true);
      secb3.setDisable(true);

    } else if (secc1.isSelected()) {
      SecretaryFC.add("C");
      secc2.setDisable(true);
      secc3.setDisable(true);
    }
  }

  public void SecondSecretaryChoice() {
    if (seca2.isSelected()) {
      SecretarySC.add("A");
      seca1.setDisable(true);
      seca3.setDisable(true);

    } else if (secb2.isSelected()) {
      SecretarySC.add("B");
      secb1.setDisable(true);
      secb3.setDisable(true);

    } else if (secc2.isSelected()) {
      SecretarySC.add("C");
      secc1.setDisable(true);
      secc3.setDisable(true);
    }
  }

  public void ThirdSecretaryChoice() {
    if (seca3.isSelected()) {
      SecretaryTC.add("A");
      seca2.setDisable(true);
      seca1.setDisable(true);

    } else if (secb3.isSelected()) {
      SecretaryTC.add("B");
      secb2.setDisable(true);
      secb1.setDisable(true);

    } else if (secc3.isSelected()) {
      SecretaryTC.add("C");
      secc2.setDisable(true);
      secc1.setDisable(true);
    }
  }

  public void setResult() {
    results.setText(String.join(", ", presidentFC));
    System.out.println(results.getText());
  }

  //      Parent BallotParent = FXMLLoader.load(getClass().getResource("window3.fxml"));
  //      Scene startScene = new Scene(BallotParent);
  //
  //      // This line gets the Stage information
  //      Stage window = (Stage) submit2.getScene().getWindow();
  //
  //      window.setScene(startScene);
  //      window.show();

}
