/*
 * Author: David Green <DGreen@uab.edu>
 * Assignment:  ee333fallp1 - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

/** Fake calendar (Static data, static methods only */
public class Calendar {

  private static String theDate = "TBD";

  Calendar() {}

  /**
   * Sets the calendar to specified date
   *
   * @param date representation of data as String
   */
  public static void setDate(String date) {
    if (date != null) {
      theDate = date;
    }
  }

  /**
   * Provides the fake calendar date
   *
   * @return KanbanDate representation of date from calendar
   */
  public static KanbanDate getDate() {
    return new KanbanDate(theDate);
  }
}
