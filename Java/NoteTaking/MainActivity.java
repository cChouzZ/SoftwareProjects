package com.example.notetaking;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentTransaction;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private ListView listView;

    static ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = findViewById(R.id.listView);
        adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1);
        listView.setAdapter(adapter);
        updateListView(this);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String note = (String) parent.getItemAtPosition(position);
                String[] parts = note.split("\n");
                String title = parts[0];
                String Content = note.substring(parts[0].length()).trim();

                Intent intent = new Intent(MainActivity.this, NoteDetailActivity.class);
                intent.putExtra("title", title);
                intent.putExtra("Content", Content);
                startActivity(intent);
            }

        });

    }

    protected void onResume() {
        super.onResume();
        updateListView(this);
    }

    public void addNote(View view) {
        Intent intent = new Intent(this, AddNoteActivity.class);
        startActivity(intent);
    }

    public ArrayList<String> readNotesFromFile() {
        ArrayList<String> notes = new ArrayList<>();
        try {
            FileInputStream fis = openFileInput("notes.txt");
            InputStreamReader isr = new InputStreamReader(fis);
            BufferedReader br = new BufferedReader(isr);
            String line;
            while ((line = br.readLine()) != null) {
                notes.add(line);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return notes;
    }

    public void updateListView(Context context) {
        ArrayList<String> notes = readNotesFromFile();
        ArrayList<String> titles = new ArrayList<>();
        for (String note : notes) {
            String[] parts = note.split("\n");
            String title = parts[0];
            titles.add(title);
        }
        adapter.clear();
        adapter.addAll(titles);
        adapter.notifyDataSetChanged();
    }


}