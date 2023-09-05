package com.example.zacharychou_calculatorapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void add(View v) {
        EditText et = findViewById(R.id.message);
        int opd1 = Integer.parseInt(et.getText().toString());
        EditText et2 = findViewById(R.id.message2);
        int opd2 = Integer.parseInt(et2.getText().toString());
        TextView tv = findViewById(R.id.result);
        tv.setText("" + (opd1 + opd2));
    }

    public void subtract(View v) {
        EditText et3 = findViewById(R.id.message);
        int opd3 = Integer.parseInt(et3.getText().toString());
        EditText et4 = findViewById(R.id.message2);
        int opd4 = Integer.parseInt(et4.getText().toString());
        TextView tv = findViewById(R.id.result2);
        tv.setText("" + (opd3 - opd4));
    }

    public void multiply(View v) {
        EditText et5 = findViewById(R.id.message);
        int opd5 = Integer.parseInt(et5.getText().toString());
        EditText et6 = findViewById(R.id.message2);
        int opd6 = Integer.parseInt(et6.getText().toString());
        TextView tv = findViewById(R.id.result3);
        tv.setText("" + (opd5 * opd6));
    }

    public void divide(View v) {
        EditText et7 = findViewById(R.id.message);
        double opd7 = Double.parseDouble(et7.getText().toString());
        EditText et8 = findViewById(R.id.message2);
        double opd8 = Double.parseDouble(et8.getText().toString());
        TextView tv = findViewById(R.id.result4);
        double answer = opd7 / opd8;
        tv.setText("" + answer);
    }

    public void ShowResult(View view) {
        Intent intent = new Intent(this, SecondActivity.class);
        TextView editText = findViewById(R.id.result);
        TextView editText1 = findViewById(R.id.result2);
        TextView editText2 = findViewById(R.id.result3);
        TextView editText3 = findViewById(R.id.result4);

        String message = editText.getText().toString();
        String message1 = editText1.getText().toString();
        String message2 = editText2.getText().toString();
        String message3 = editText3.getText().toString();

        intent.putExtra("solution", message);
        intent.putExtra("solution1",message1);
        intent.putExtra("solution2", message2);
        intent.putExtra("solution3",message3);

        startActivity(intent);
    }

    public void clear(View v) {
        TextView tv = findViewById(R.id.result);
        tv.setText("");
        TextView tv2 = findViewById(R.id.result2);
        tv2.setText("");
        TextView tv3 = findViewById(R.id.result3);
        tv3.setText("");
        TextView tv4 = findViewById(R.id.result4);
        tv4.setText("");
    }
}