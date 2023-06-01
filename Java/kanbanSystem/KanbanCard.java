/*
 * Author: Zachary Chou <zchou@uab.edu>  // replace
 * Assignment:  ee333fallp2 - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */
package edu.uab.dgreen.kanbansys;

import java.util.ArrayList;

/**
 * Model a Kanban Card
 *
 * <p>KanbanCard has any number of Fields. Some are standard - guaranteed to exist in fixed order.
 *
 * <pre>0 - uid (string)
 *    1 - name (String) name of the card
 *    2 - createDate (KanbanDate) date card was created
 *    3 - endDate (KanbanDate) date card (null if not in done, abandoned) otherwise most
 *        recently done or abandoned
 *    4 - notes
 *    5 - state
 * </pre>
 *
 * <p>The system is limited to MAXFIELDS (defined in the class).
 */
public class KanbanCard {

	private ArrayList<Field>fields;
  private /*final*/ Field[] field;
  private int nFields;
  private static long count = 1000000000; // start with 10 digits

  // Fixed location constants for the standard fields
  private static final int UID = 0;
  private static final int NAME = 1;
  private static final int STATE = 2;


  private static final int CREATE = 3;
  private static final int BEGIN = 4;
  private static final int END = 5;
  private static final int NOTES = 6;

  // The number of standard fields
  private static final int NSTDFIELDS = 7;

  // Maximum number of fields.
  private static final int MAXFIELDS = 20;

  /**
   * Create a Kanban card with a unique uid, and Initialize other fields appropriately
   *
   * @param name the name of the card
   */
  public KanbanCard(String name) {


		String[] stateList = {"BACKLOG", "DESIGN", "BUILD", "TEST", "RELEASE", "DONE", "ABANDONED"};

    //fields = new Field[MAXFIELDS];

    if (name == null || name.equals("")) {
      name = "unnamed";
    }

		// The standard fields

		fields.set(UID, new StringField("uid", "" + ++count));
    fields.set(NAME, new StringField("name", name));
    fields.set(STATE, new StateField("state", stateList, "BACKLOG"));
    fields.set(CREATE, new DateField("createDate", Calendar.getDate()));
    fields.set(BEGIN, new DateField("beginDate", new KanbanDate("TBD")));
    fields.set(END, new DateField("endDate", new KanbanDate("TBD")));
    fields.set(NOTES, new StringField("notes", ""));
		nFields = NSTDFIELDS;

		fields = new ArrayList<>();

	}

	public static int getSTATE() {
		return STATE;
	}


  /**
   * get the UID of the card
   *
   * @return long number corresponding to uid of card
   */
  public String getUid() {
    return (fields.get(UID)).toString();
  }

  /**
   * get the name of the task
   *
   * @return String representing name of task
   */
  public String getName() {
    return fields.get(NAME).toString();
  }

  /**
   * Is this task done?
   *
   * @return true if task has been completed
   */
  public boolean isDone() {
    return fields.get(STATE).toString().equals("DONE");
  }

  /**
   * Is this task active?
   *
   * @return true if not in backlog, not done or not abandoned
   */
  public boolean isActive() {
    String state = fields.get(STATE).toString();
    return state.equals("DESIGN")
        || state.equals("BUILD")
        || state.equals("TEST")
        || state.equals("RELEASE");
  }

  /**
   * Is this task abandoned?
   *
   * @return true if task has been abandoned
   */
  public boolean isAbandoned() {
    return fields.get(STATE).toString().equals("ABANDONED");
  }

  /**
   * Create a string representation of the Kanban card
   *
   * <p>Format:
   *
   * <p><code>
   * uid: Name of task Task State
   * state - Create: date (or tbd) Begin: date (or tbd) Completed: date (or TBD)
   * (notes would go here if any)
   * </code>
   *
   * <p>Example:
   *
   * <p><code>
   * 100000000: Demo task Backlog
   * BACKLOG - Create: 20210815 Begin: TBD Completed: TBD
   * </code>
   *
   * @return formatted string
   */
  @Override
  public String toString() {
    String otherFields = "";

    for (int i = NSTDFIELDS; i < nFields; i++) {
      otherFields += System.lineSeparator() + fields.get(i).toString();
    }

    return ""
        + fields.get(UID)
        + ": "
        + fields.get(NAME)
        + System.lineSeparator()
        + fields.get(STATE)
        + " - Create: "
        + fields.get(CREATE)
        + " Begin: "
        + fields.get(BEGIN)
        + " Completed: "
        + fields.get(END)
        + ((fields.get(NOTES).toString().equals(""))
            ? ""
            : (System.lineSeparator() + fields.get(NOTES).toString()))
        + otherFields;
  }

  /** @param newName the new task name */
  public void updateName(String newName) {
    fields.set(NAME, fields.get(NAME).newField(newName));
  }

  /**
   * Mark the task as in design if it is in the backlog (no action otherwise) and capture note if
   * non-null
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void start(String note) {
    nextStateIfValid("BACKLOG", "DESIGN", note);
    if (fields.get(STATE).toString().equals("DESIGN") && fields.get(BEGIN).toString().equals("TBD")) {
      fields.set(BEGIN, fields.get(BEGIN).newField(Calendar.getDate()));
    }
  }

  /**
   * Mark and timestamp (if beginDate null) the task as in build if it was in design (no action
   * otherwise) and capture note if non-null
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void build(String note) {
    nextStateIfValid("DESIGN", "BUILD", note);
  }

  /**
   * Mark the task as in test if it was in build (no action otherwise) and capture note
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void test(String note) {
    nextStateIfValid("BUILD", "TEST", note);
  }

  /**
   * Mark the task as ready to release if it was in test (no action otherwise) and capture note
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void release(String note) {
    nextStateIfValid("TEST", "RELEASE", note);
  }

  /**
   * Mark and timestamp the task as complete if it was in release (no action otherwise) and capture
   * note
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void complete(String note) {
    nextStateIfValid("RELEASE", "DONE", note);
    if (fields.get(STATE).toString().equals("DONE")) {
      fields.set(END, fields.get(END).newField(Calendar.getDate()));
    }
  }

  /**
   * Mark the task as abandoned unless it was completed (no action otherwise) and capture note
   *
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void abandon(String note) {
    if (!fields.get(STATE).toString().equals("DONE") && !fields.get(STATE).toString().equals("ABANDONED")) {
      fields.set(STATE, fields.get(STATE).newField("ABANDONED"));
      append(note);
      if (fields.get(END).toString().equals("TBD")) {
        fields.set(END, fields.get(END).newField(Calendar.getDate()));
      }
    }
  }

  /**
   * Modify the state of the task and capture the note, update the date fields based on present new
   * state
   *
   * @param state the new KCardState for the task
   * @param note a String note or null, if non-null, a newline will be prepended to the added note
   */
  public void move(String state, String note) {
    fields.set(STATE, fields.get(STATE).newField(state));
    append(note);
    if (!fields.get(STATE).toString().equals("BACkLOG") && fields.get(BEGIN).toString().equals("TBD")) {
      fields.set(BEGIN, new DateField("begin", Calendar.getDate()));
    }
    if (fields.get(STATE).toString().equals("ABANDONED") || fields.get(STATE).toString().equals("DONE")) {
      fields.set(END, fields.get(END).newField(Calendar.getDate()));
    } else {
      fields.set(END, fields.get(END).newField(new KanbanDate("TBD")));
    }
  }

  /**
   * Get a field by name
   *
   * @param name name of the field to find
   * @return field if found, null otherwise
   */
  public final Field getField(String name) {
    for (int i = 0; i < nFields; i++) {
      if (fields.get(i).getName().equals(name)) {
        return fields.get(i);
      }
    }
    return null; // did not find field
  }

  /**
   * Returns an array containing the fields of this Kanban Card
   *
   * @return array of fields
   */
  public final String[] getFieldNames() {
    String[] fieldNames = new String[nFields];
    for (int i = 0; i < nFields; i++) {
      fieldNames[i] = fields.get(i).getName();
    }
    return fieldNames;
  }

  /**
   * Adds a field to the Kanban card
   *
   * @param f field to add
   */
  public void add(Field f) {
    if (nFields < MAXFIELDS) {
      fields.set(nFields++, f);
    }
  }

  /**
   * Set field to a new field with a possibly new value
   *
   * @param newField
   */
  public void set(Field newField) {
    var name = newField.getName();

    for (int i = 0; i < nFields; i++) {
      if (fields.get(i).getName().equals(name)) {
        fields.set(i, newField);
        return;
      }
    }
    // TBD: if here, did not find the field, no action
  }

  // Helper methods:

  // if present state meets requirement of being before state,
  //    then change to after state and update note
  private void nextStateIfValid(String before, String after, String note) {
    if (fields.get(STATE).toString().equals(before)) {
      fields.set(STATE, fields.get(STATE).newField(after));
      append(note);
    }
  }

  // Append note to notes after a line separator if there is a note.
  private void append(String note) {
    String notes = fields.get(NOTES).toString();
    if (note != null) {
      if ((notes == null) || notes.equals("")) {
        notes = note;
      } else {
        notes += System.lineSeparator() + note;
      }
      fields.set(NOTES, new StringField("notes", notes));
    }
  }
}

