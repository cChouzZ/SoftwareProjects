package com.example.zacharychou_calculatorapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.ViewGroup;
import android.widget.TextView;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        Intent intent = getIntent();

        String message = intent.getStringExtra("solution");
        String message1 = intent.getStringExtra("solution1");
        String message2 = intent.getStringExtra("solution2");
        String message3 = intent.getStringExtra("solution3");

        TextView textView = new TextView(this);
        textView.setTextSize(40);
        TextView textView1 = new TextView(this);
        textView1.setTextSize(35);
        TextView textView2 = new TextView(this);
        textView2.setTextSize(30);
        TextView textView3 = new TextView(this);
        textView3.setTextSize(40);

        textView.setText("Addition solution: " + message);
        textView1.setText("Subtraction solution: " + message1);
        textView2.setText("Multiplication solution: " + message2);
        textView3.setText("Division solution: " + message3);

        ViewGroup layout = (ViewGroup)findViewById(R.id.SecondLayout);
        layout.addView(textView);
        layout.addView(textView1);
        layout.addView(textView2);
        layout.addView(textView3);
    }
}