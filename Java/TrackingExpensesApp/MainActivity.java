package com.example.trackingexpensesapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    String[] expense;
    private static final int EDIT_EXPENSE_REQUEST_CODE = 1;
    private int editedItemPosition;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Resources res = getResources();
        expense = res.getStringArray(
                R.array.expenses_array);
        ListView listview = (ListView) findViewById(
                R.id.listview);
        ArrayAdapter<String> adapter =
                new ArrayAdapter<String>(
                        this, R.layout.list_item, expense);
        listview.setAdapter(adapter);
        registerForContextMenu(listview);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu,
                                    View v, ContextMenu.ContextMenuInfo menuInfo) {
        if (v.getId() == R.id.listview) {
            AdapterView.AdapterContextMenuInfo info =
                    (AdapterView.AdapterContextMenuInfo) menuInfo;
            menu.setHeaderTitle(expense[info.position]);
            String[] menuItems = getResources().
                    getStringArray(R.array.menu);
            for (int i = 0; i < menuItems.length; i++) {
                menu.add(Menu.NONE, i, i, menuItems[i]);
            }
        }
    }

    @Override
    public boolean onContextItemSelected(MenuItem item) {
        AdapterView.AdapterContextMenuInfo info =
                (AdapterView.AdapterContextMenuInfo)
                        item.getMenuInfo();
        int menuItemIndex = item.getItemId();
        String[] menuItems =
                getResources().getStringArray(R.array.menu);
        String menuItemName = menuItems[menuItemIndex];
        String listItemName = expense[info.position];

        View itemview = (View) info.targetView;
        if (menuItemName.equals("Edit")) {
            Intent intent = new Intent(this,EditActivity.class);
            intent.putExtra("expense",expense[info.position]);
            editedItemPosition = info.position;
            startActivityForResult(intent,EDIT_EXPENSE_REQUEST_CODE);
        }

        if (menuItemName.equals("Delete")) {
            List<String> list = new ArrayList<String>(Arrays.asList(expense));
            list.remove(info.position);
            expense = list.toArray(new String[0]);

            ArrayAdapter<String> adapter =
                    new ArrayAdapter<String>(
                            this, R.layout.list_item, expense);
            ListView listview = (ListView) findViewById(
                    R.id.listview);
            listview.setAdapter(adapter);
        }

        else if (menuItemName.equals("Cancel"))
            return true;

        return super.onContextItemSelected(item);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == EDIT_EXPENSE_REQUEST_CODE && resultCode == RESULT_OK) {
            String editedExpense = data.getStringExtra("editedExpense");

            if (editedItemPosition >= 0 && editedItemPosition < expense.length) {
                expense[editedItemPosition] = editedExpense;
            }

            ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                    this, R.layout.list_item, expense);
            ListView listview = (ListView) findViewById(R.id.listview);
            listview.setAdapter(adapter);
        }
    }
}