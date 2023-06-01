/*
 * Author: Zachary Chou<zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Summer 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

import java.util.Arrays;

/** Additional Tests for P2 */
public class TestP2 {

  /** @param args the command line arguments */
  public static void main(String[] args) {

    Field f1;
    Field f2;
    Field f3;
    Field f4;
    Field f5;
    Field f6;

    System.out.println(
        """
        P2Test for EE333 Fall 2021, Zachary Chou <zchou@uab.edu>

        Try out StringField class
        -------------------------
        """);

    f1 = new StringField("fieldName1", "fieldValue1");
    output("f1 as StringField", f1);
    f2 = new StringField("fieldName2", "fieldValue2");
    output("f2 as StringField", f2);

    System.out.println("Compare f1 to f2: " + f1.compareTo(f2));
    System.out.println("Compare f1 to f1: " + f1.compareTo(f1));
    System.out.println("Compare f2 to f1: " + f2.compareTo(f1));

    String s = (String) f1.get();
    testTrue(s.equals(f1.toString()), "try StringField's get");

    System.out.println(
        """

        Try out DateField class
        ----------------------
        """);

    f3 = new DateField("fieldName3", new KanbanDate("20210816"));
    output("f3 as dateField", f3);
    f4 = new DateField("fieldName4", new KanbanDate("20210817"));
    output("f4 as dateField", f4);

    System.out.println("Compare f3 to f4: " + f3.compareTo(f4));
    System.out.println("Compare f3 to f3: " + f3.compareTo(f3));
    System.out.println("Compare f4 to f3: " + f4.compareTo(f3));

    KanbanDate kd = (KanbanDate) f3.get();
    testTrue(kd.toString().equals(f3.toString()), "try DateField's get");

    System.out.println(
        """

        Try out StateField class
        ----------------------
        """);

    String stateList[] = {"STILL", "RUNNING", "BROKE"};

    f5 = new StateField("fieldName5", stateList, "STILL");
    f6 = new StateField("fieldName6", stateList, "RUNNING");
    System.out.println("Compare f5 to f6: " + f5.compareTo(f6));
    System.out.println("Compare f5 to f5: " + f5.compareTo(f5));
    System.out.println("Compare f6 to f5: " + f6.compareTo(f5));

    f5 = f5.newField("BROKE");

    String st = (String) f5.get();
    testTrue(st.equals(f5.toString()), "try StateField's get");

    System.out.println(
        """

        Try sorting f1 through f6
        -------------------------
        """);

    Field[] array = {f1, f2, f3, f4, f5, f6};
    sortPrintArray(array);

    System.out.println(
        """

        Try sorting f6 through f1
        -------------------------
        """);
    Field[] array2 = {f6, f5, f4, f3, f2, f1};
    sortPrintArray(array2);

    System.out.println(
        """

        Try kanban card with 6 extra fields
        -----------------------------------
        """);

    KanbanCard kc = new KanbanCard("test card with more fields");
    kc.start("start this test card");
    kc.add(f1);
    kc.add(f2);
    kc.add(f3);
    kc.add(f4);
    kc.add(f5);
    kc.add(f6);

    System.out.println(kc);

    System.out.println("The field names are:");
    String fieldNames[] = kc.getFieldNames();
    for (String fieldName : fieldNames) {
      System.out.println("..." + fieldName);
    }

    System.out.println(
        """

        Look at the type of fields for f1 through f6
        --------------------------------------------
        """);

    for (var f : array) {
      System.out.println(f.getType());
    }

    System.out.println(
        """

        Test getting fields by name
        ---------------------------
        """);

    for (var f : array2) {
      var foundField = kc.getField(f.getName());
      testTrue((f == foundField), "testing for " + f.getName());
    }

    testTrue(kc.getField("not findable") == null, "Should not find the unfindable");

    System.out.println(
        """

        Test setting fields by name
        ---------------------------
        """);

    Field originalField = kc.getField("fieldName5");
    System.out.println("original field: " + originalField.getTaggedString());
    Field newField = originalField.newField("RUNNING");
    System.out.println("changed field with RUNNING value: " + newField.getTaggedString());
    kc.set(newField);
    System.out.println("changed field from card: " + kc.getField("fieldName5").getTaggedString());
  }

  private static void sortPrintArray(Field[] array) {
    Arrays.sort(array, (Field a, Field b) -> a.compareTo(b));

    for (Field f : array) {
      System.out.println(f.getTaggedString());
    }
  }

  private static void testTrue(boolean test, String identity) {
    System.out.println(identity + ": " + ((test) ? "passed." : "failed"));
  }

  private static void output(String info, Field f) {
    System.out.println("*** " + info + "***");
    System.out.println("name: " + f.getName());
    System.out.println("type: " + f.getType());
    System.out.println("value: " + f);
    System.out.println("taggedString: " + f.getTaggedString());
    System.out.println("is name fieldName1: " + f.isName("fieldName1"));
    System.out.println("");
  }
}
