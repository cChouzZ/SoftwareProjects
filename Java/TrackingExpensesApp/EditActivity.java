package com.example.trackingexpensesapp;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

public class EditActivity extends AppCompatActivity {
    private EditText editExpense;
    private SQLiteDatabase database;
    private String editedExpenseDescription;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.edit);

        SQLiteOpenHelper dbHelper = new SQLiteOpenHelper(this,
                "expenses.db", null, 1) {
            @Override
            public void onCreate(SQLiteDatabase db) {
                db.execSQL("CREATE TABLE expenses (id INTEGER PRIMARY KEY, " +
                        "Expense TEXT, Amount REAL, Date TEXT)");
            }

            @Override
            public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
                db.execSQL("DROP TABLE IF EXISTS expenses");
                onCreate(db);
            }
        };
        database = dbHelper.getWritableDatabase();

        editExpense = (EditText) findViewById(R.id.edit_expense);
        Button buttonSave = (Button) findViewById(R.id.button_save);
        Button buttonCancel = (Button) findViewById(R.id.button_cancel);

        String expense = getIntent().getStringExtra("expense");
        editExpense.setText(expense);

        buttonSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editedExpenseDescription = editExpense.getText().toString();

                saveEditedExpense(editedExpenseDescription);
            }
        });

        buttonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }

    private void saveEditedExpense(String editedExpenseDescription) {
        ContentValues values = new ContentValues();
        values.put("Expense", editedExpenseDescription);
        values.put("Amount", 0.0);
        values.put("Date", "MM/DD/YYYY");

        database.insert("expenses", null, values);

        Intent resultIntent = new Intent();
        resultIntent.putExtra("editedExpense", editedExpenseDescription);
        setResult(RESULT_OK, resultIntent);

        finish();
    }

}

