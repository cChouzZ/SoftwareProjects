/*
 * Author: Zachary Chou <zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

import static org.testng.Assert.*;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

/** */
public class FieldNGTest {

  private Field f;
  private Field newField;
  private String value;
  private Field v;
  private Field t;
  private String type;
  private String name;

  public FieldNGTest() {}

  @BeforeMethod
  public void setUpMethod() throws Exception {

    f =
        new Field("Field", name) {
          @Override
          public Field newField(Object newValue) {
            // throw new UnsupportedOperationException(
            //    "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
            return newField;
          }

          @Override
          public String toString() {
            //  throw new UnsupportedOperationException(
            //      "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
            return "";
          }

          @Override
          public Object get() {
            // throw new UnsupportedOperationException(
            //    "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
            return name;
          }

          @Override
          int valueCompareTo(Field f) {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }
        };
    t =
        new Field("Field", type) {
          @Override
          public Field newField(Object newValue) {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }

          @Override
          public String toString() {
            //  throw new UnsupportedOperationException(
            //      "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
            return "";
          }

          @Override
          public Object get() {
            // throw new UnsupportedOperationException(
            //    "Not supported yet."); // To change body of generated methods, choose
            // Tools |
            // Templates.
            return type;
          }

          @Override
          int valueCompareTo(Field f) {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }
        };

    v =
        new Field("Field", value) {
          @Override
          public Field newField(Object newValue) {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }

          @Override
          public String toString() {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }

          @Override
          public Object get() {
            throw new UnsupportedOperationException(
                "Not supported yet."); // To change body of generated methods, choose Tools |
            // Templates.
          }

          @Override
          int valueCompareTo(Field v) {
            //	throw new UnsupportedOperationException("Not supported yet."); //To change body of
            // generated methods, choose Tools | Templates.
            // }
            return 0;
          }
        };
  }

  @BeforeMethod
  public void tearDownMethod() throws Exception {}

  /** Test of getName method, of class Field. */
  @Test
  public void testGetName() {

    String expResult = "Field";
    String result = f.getName();
    assertEquals(result, expResult);
  }

  /** Test of newField method, of class Field. */
  @Test
  public void testNewField() {

    Object newValue = null;

    Field expResult = null;
    Field result = f.newField(newValue);
    assertEquals(result, expResult);
  }

  /** Test of isName method, of class Field. */
  @Test
  public void testIsName() {

    String Name = "";

    boolean expResult = false;
    boolean result = f.isName(Name);
    assertEquals(result, expResult);
  }

  /** Test of toString method, of class Field. */
  @Test
  public void testToString() {

    String expResult = "";
    String result = f.toString();
    assertEquals(result, expResult);
  }

  /** Test of getTaggedString method, of class Field. */
  @Test
  public void testGetTaggedString() {

    String expResult = "Field: ";
    String result = f.getTaggedString();
    assertEquals(result, expResult);
  }

  /** Test of getType method, of class Field. */
  @Test
  public void testGetType() {

    String expResult = "unknown";
    String result = t.getType();
    assertEquals(result, expResult);
  }

  /** Test of get method, of class Field. */
  @Test
  public void testGet() {

    Object expResult = value;
    Object result = f.get();
    assertEquals(result, expResult);
  }

  /** Test of compareTo method, of class Field. */
  @Test
  public void testCompareTo() {

    int expResult = 0;
    int result = v.compareTo(f);
    assertEquals(result, expResult);
  }

  /** Test of valueCompareTo method, of class Field. */
  @Test
  public void testValueCompareTo() {

    int expResult = 0;
    int result = v.valueCompareTo(f);
    assertEquals(result, expResult);
  }

  public class FieldImpl extends Field {

    public FieldImpl() {
      super("", "");
    }

    @Override
    public Field newField(Object newValue) {
      return null;
    }

    @Override
    public String toString() {
      return "";
    }

    @Override
    public Object get() {
      return null;
    }

    @Override
    public int valueCompareTo(Field f) {
      return 0;
    }
  }
}
