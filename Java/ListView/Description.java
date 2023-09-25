package com.example.listview;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class Description extends AppCompatActivity {

    private Button returnButton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_description);

        Intent intent = getIntent();

        returnButton = (Button) findViewById(R.id.ReturnButton);
        returnButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) { finish(); }
        });
        String message = intent.getStringExtra(MainActivity.MESSAGE);
        TextView textView = (TextView) findViewById(R.id.textDescription);
        textView.setText(message);
    } // end of onCreate()
} // end of class Description
