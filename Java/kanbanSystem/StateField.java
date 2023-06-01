/*
 * Author: Zachary Chou<zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Summer 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

/**
 * A Field where the value can be one of several string values
 *
 * <p>TBD: Enforce staying to the supplied value list
 *
 * @author dgreen
 */
public class StateField extends Field {

  String state;
  String[] states;

  /**
   * Create a StateField object
   *
   * @param name name of the field
   * @param values the complete list of values
   * @param value the present value of the field
   */
  public StateField(String name, String[] values, String value) {
    super(name, "state");
    states = values;
    state = value;
  }

  /**
   * Returns present state
   *
   * @return string state name
   */
  @Override
  public final String get() {
    return state;
  }

  /**
   * Provide a string representation of the state of the StateField
   *
   * @return the present state
   */
  @Override
  public String toString() {
    return state;
  }

  /**
   * Compare the order of this object's state to the supplied Field's state based on the order of
   * the states
   *
   * <p>If the field has an illegal value (as defined in present object), it will be signaled as
   * "later"
   *
   * @param f Field to compare to
   * @return sorting order of CompareTo
   */
  @Override
  int valueCompareTo(Field f) {
    return orderOf(state) - orderOf(f.toString());
  }

  /**
   * Create a new StateField with same name and same list of legal values with supplied state.
   *
   * @param newValue supplied state (will use the toString value of the supplied object)
   * @return new StateField
   */
  @Override
  public Field newField(Object newValue) {
    return new StateField(this.getName(), states, (String) newValue);
  }

  // provides the index number of the supplied state relative to the list of states,
  // returning -1 if the supplied state is not in the list of states
  private int orderOf(String aState) {
    for (int i = 0; i < states.length; i++) {
      if (state.equals(aState)) {
        return i;
      }
    }
    return -1;
  }
}
