package com.example.hangman;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        String[] difficulties = {"Easy", "Medium", "Hard"};

        ListView listView = (ListView) findViewById(R.id.difficulty_list);

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, difficulties);

        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String selectedDifficulty = (String) parent.getItemAtPosition(position);

                Intent intent = new Intent(MainActivity.this, GameActivity.class);

                intent.putExtra("difficulty", selectedDifficulty);

                startActivity(intent);
            }
        });
    }
}