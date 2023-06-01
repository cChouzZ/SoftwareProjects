/*
 * Author: Zachary Chou<zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

/** Model a field as a string name with the assumption that subclasses will implement the value */
public abstract class Field implements Comparable<Field> {

  private final String name;
  private final String type;

  Field(String name, String type) {
    this.name = (name == null) ? "unknown" : name;
    this.type = (type == null) ? "unknown" : type;
  }

  /**
   * Returns the name of the field
   *
   * @return the name of the field
   */
  public String getName() {
    return name;
  }

  /**
   * Creates a new Field of same type with the same parameters but new value. This is intended to
   * allow new fields to replace existing ones when the value changes to prevent anyone who has a
   * reference to a field modifying a collection that uses the replacement protocol.
   *
   * @param newValue new value for the field's value
   * @return a new field with same type with the same parameters but new value
   */
  public abstract Field newField(Object newValue);

  /**
   * Checks to see if this field's name matches supplied argument.
   *
   * @param name supplied name to match against field's name
   * @return true if match, else false
   */
  public boolean isName(String name) {
    return name.equals(this.name);
  }

  /**
   * Returns a string representation of the value of the field.
   *
   * @return representation of value
   */
  @Override
  public abstract String toString();

  /**
   * Returns a string of form: name: value
   *
   * @return string with both name and value
   */
  public String getTaggedString() {
    return name + ": " + toString();
  }

  /**
   * Supplies a string representation of the type of the field
   *
   * @return type of field
   */
  public String getType() {
    return type;
  }

  /**
   * Get the value of the field
   *
   * @return value
   */
  public abstract Object get();

  /**
   * Implementation of the Comparable Interface for Fields.
   *
   * <p>Fields of the same type are compared on values. Fields of different types are compared based
   * on their tagged string representation.
   *
   * @see getTaggedString()
   * @see Comparable
   * @param f the field to compare to this object
   * @return less than 0 if this lower than f, 0 if equal, greater than 0 this higher than f
   */
  @Override
  public int compareTo(Field f) {
    if (f == null) return -1;
    if (f.getType().equals(this.getType())) {
      return this.valueCompareTo(f);
    }
    // if fields are not the same type, compare the tagged string representation
    return this.getTaggedString().compareTo(f.getTaggedString());
  }

  /**
   * Compare (as in compareTo) field values given by the fields
   *
   * @param f the field whose value is to be compare this object's value
   * @return less than 0 if this lower than f, 0 if equal, greater than 0 this higher than f
   */
  abstract int valueCompareTo(Field f);
}
