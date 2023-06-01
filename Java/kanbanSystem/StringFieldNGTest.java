/*
 * Author: Zachary Chou <zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

import static org.testng.Assert.*;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

/** */
public class StringFieldNGTest {

  private Field f;
  private Field v;
  private Field newField;
  private String value;
  private String name;

  public StringFieldNGTest() {}

  @BeforeMethod
  public void setUpMethod() throws Exception {

    f =
        new Field("Field", name) {
          @Override
          public Field newField(Object newValue) {
            // throw new UnsupportedOperationException("Not supported yet."); //To change body of
            // generated methods, choose Tools | Templates.
            return newField;
          }

          @Override
          public String toString() {
            // throw new UnsupportedOperationException("Not supported yet."); //To change body of
            // generated methods, choose Tools | Templates.
            return "";
          }

          @Override
          public Object get() {
            // throw new UnsupportedOperationException("Not supported yet."); //To change body of
            // generated methods, choose Tools | Templates.
            return name;
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
          int valueCompareTo(Field f) {
            // throw new UnsupportedOperationException("Not supported yet."); //To change body of
            // generated methods, choose Tools | Templates.
            return 0;
          }
        };
  }

  @AfterMethod
  public void tearDownMethod() throws Exception {}

  /** Test of get method, of class StringField. */
  @Test
  public void testGet() {

    Object expResult = value;
    Object result = f.get();
    assertEquals(result, expResult);
  }

  /** Test of toString method, of class StringField. */
  @Test
  public void testToString() {

    String expResult = "";
    String result = f.toString();
    assertEquals(result, expResult);
  }

  /** Test of valueCompareTo method, of class StringField. */
  @Test
  public void testValueCompareTo() {

    int expResult = 0;
    int result = v.valueCompareTo(f);
    assertEquals(result, expResult);
  }

  /** Test of newField method, of class StringField. */
  @Test
  public void testNewField() {

    Object newValue = null;

    Field expResult = null;
    Field result = f.newField(newValue);
    assertEquals(result, expResult);
  }
}