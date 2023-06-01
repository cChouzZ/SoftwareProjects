/*
 * Author: Zachary Chou <zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Summer 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

import java.util.Objects;

/**
 * A Date Class representing dates as a string YYYYMMDD or "TBD"
 *
 * @author dgreen
 */
public class KanbanDate implements Comparable<KanbanDate> {

  private final String date;

  /**
   * Construct a date object with date of "TBD"
   *
   * <p>TBD: Eliminate trusting the user of the class.
   */
  public KanbanDate() {
    date = "TBD";
  }

  /**
   * Construct a date object with the supplied information
   *
   * @param s the date value
   */
  public KanbanDate(String s) {
    date = s;
  }

  /**
   * Make a new object with same date as the supplied object. If null is supplied, then use "TBD"
   *
   * @param kd the object to duplicate
   */
  public KanbanDate(KanbanDate kd) {
    date = (kd == null) ? "TBD" : kd.date;
  }

  /**
   * Compared supplied object to this one
   *
   * @param o the KanBan
   * @return true if equal, false otherwise
   */
  @Override
  public boolean equals(Object o) {
    if (!(o instanceof KanbanDate)) {
      return false;
    }
    return date.equals(((KanbanDate) o).date);
  }

  /**
   * Provide a hashCode for this type of object
   *
   * @return hashCode
   */
  @Override
  public int hashCode() {
    int hash = 5;
    hash = 59 * hash + Objects.hashCode(this.date);
    return hash;
  }

  /**
   * Provides a string representation of a KanbanDate.
   *
   * @return date
   */
  @Override
  public String toString() {
    return date;
  }

  /**
   * Compares this date to a supplied one.
   *
   * <p>TBD would always sort to later dates
   *
   * @param d date to compare to
   * @return less than 0 if this earlier than d, 0 if equal, greater than 0 this later than d
   */
  @Override
  public int compareTo(KanbanDate d) {
    if ((d == null) || d.toString().equals("TBD")) {
      return -1;
    }
    if (this.date.equals("TBD")) {
      return +1;
    }
    return date.compareTo(d.date);
  }
}
