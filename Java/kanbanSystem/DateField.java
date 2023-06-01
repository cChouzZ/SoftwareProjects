/*
 * Author: Zachary Chou <zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Summer 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

/**
 * A field which holds dates. Dates are of type KanbanDate which is a YYYYMMDD string or "TBD"
 *
 * @author dgreen
 */
public class DateField extends Field {

  private final KanbanDate kd;

  /**
   * Create a DateField
   *
   * @param name name of the field
   * @param kd the date as a KanbanDate
   */
  public DateField(String name, KanbanDate kd) {
    super(name, "date");
    this.kd = new KanbanDate(kd); // clone it
  }

  /**
   * Returns the KanbanDate
   *
   * @return kanban date
   */
  public final KanbanDate get() {
    return kd;
  }

  /**
   * Returns a string representation of the date value
   *
   * @return the string date
   */
  @Override
  public String toString() {
    return kd.toString();
  }

  /**
   * Compares the date in the DateField to another DateField.
   *
   * @param f
   * @return
   */
  @Override
  int valueCompareTo(Field f) {
    return kd.toString().compareTo(f.toString());
  }

  /**
   * Create a new field with same name as present field with a new value.
   *
   * @param newValue
   * @return new field
   */
  @Override
  public Field newField(Object newValue) {
    return new DateField(this.getName(), ((KanbanDate) newValue));
  }
}
