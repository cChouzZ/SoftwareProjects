/*
 * Author: Zachary Chou <zchou@uab.edu>
 * Assignment:  kanbansys - EE333 Fall 2021
 *
 * Credits:  (if any for sections of code)
 */

package edu.uab.dgreen.kanbansys;

import java.util.ArrayList;
import java.util.HashMap;

/** */
public class KanbanBoard {

  private /*final*/ Field[] field;
  private int nFields;
	private static HashMap<String, KanbanCard> KanbanBoard;


  // Fixed location constants for the standard fields
  private static final int UID = 0;
  private static final int NAME = 1;
  private static final int STATE = 2;
  private static final int CREATE = 3;
  private static final int BEGIN = 4;
  private static final int END = 5;
  private static final int NOTES = 6;

	public KanbanBoard(){

}
	/**
	 * This collects Kanban Cards into a HashMap using UID as the key
	 * @param args
	 */
  public static void main(ArrayList<KanbanCard> args) {

    KanbanBoard = new HashMap<>();
		for(int n = 0; n< args.size(); n++){
			KanbanCard kc = args.get(n);
			String uid = kc.getUid();
			KanbanBoard.put(uid, kc);
		}
	}

	/**
	 * Find all Kanban Cards of a particular state
	 * @param s
	 * @param args
	 */
	private static ArrayList<KanbanCard> Kanban(int s, ArrayList<KanbanCard> args){
		KanbanBoard = new HashMap<>();
		for(int n = 0; n< args.size(); n++){
			KanbanCard kc = args.get(n);
			String uid = kc.getUid();
			KanbanBoard.put(uid, kc);
			for (String key : KanbanBoard.keySet()){
			KanbanBoard.get(key);
			int set = kc.getSTATE();
			if (set == s){
				args.add(kc);
			}

		}


}

	return args;
	}
}

