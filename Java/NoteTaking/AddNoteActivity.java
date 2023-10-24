package com.example.notetaking;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class AddNoteActivity extends AppCompatActivity {

    private Button cancelButton;
    private EditText titleEditText;
    private EditText contentEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.addnoteactivity);

        titleEditText = findViewById(R.id.titleEditText);
        contentEditText = findViewById(R.id.contentEditText);

        Button saveButton = findViewById(R.id.saveButton);
        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String title = titleEditText.getText().toString();
                String Content = contentEditText.getText().toString();
                String note = saveNoteToFile(title, Content);
                Toast.makeText(getApplicationContext(), "Note saved successfully!",
                        Toast.LENGTH_LONG).show();
                finish();
            }
        });

        cancelButton = (Button) findViewById(R.id.cancelButton);
        cancelButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) { finish(); }
        });
    }

    public String saveNoteToFile(String title, String Content) {
        String note = title + "\n";
        try {
            FileOutputStream fos = openFileOutput("notes.txt", Context.MODE_APPEND);
            fos.write(note.getBytes());
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        MainActivity.adapter.add(title);
        MainActivity.adapter.notifyDataSetChanged();


        return note;
    }


}