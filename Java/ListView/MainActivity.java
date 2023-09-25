package com.example.listview;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {
    public final static String MESSAGE = "FruitDescription";
    ListView simpleList;
    ArrayList<Item> fruitList = new ArrayList<>();
    HashMap<String, String> Data = new HashMap<String, String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Data.put("Apple","One apple has around 6-10 apple seeds");
        Data.put("Orange", "Brazil grows more oranges than anywhere else in the world");
        Data.put("Pineapple", "A pineapple is not an apple or pine – it’s actually a berry");
        Data.put("Blueberry", "Blueberries freeze in just 4 minutes");
        Data.put("Strawberry", "Strawberries are a type of rose");
        Data.put("Watermelon", "There are more than 1,200 varieties of different watermelons");
        Data.put("Raspberry", "Raspberries can be red, purple, golden and black in color");
        Data.put("Kiwi", "Kiwis can help improve the function of your immune system");
        Data.put("Dragon Fruit", "Dragon fruit has high vitamin C, iron, fiber, and antioxidants");
        Data.put("Grapefruit", "The term was invented by a Jamaican farmer in the 1800s");

        fruitList.add(new Item("Apple", R.drawable.apple));
        fruitList.add(new Item("Orange", R.drawable.orange));
        fruitList.add(new Item("Pineapple", R.drawable.pineapple));
        fruitList.add(new Item("Blueberry", R.drawable.blueberry));
        fruitList.add(new Item("Strawberry", R.drawable.strawberry));
        fruitList.add(new Item("Watermelon", R.drawable.watermelon));
        fruitList.add(new Item("Raspberry", R.drawable.raspberry));
        fruitList.add(new Item("Kiwi", R.drawable.kiwi));
        fruitList.add(new Item("Dragon Fruit", R.drawable.dragon_fruit));
        fruitList.add(new Item("Grapefruit", R.drawable.grapefruit));

        simpleList = (ListView) findViewById(R.id.simpleListView);
        MyAdapter myAdapter =
                new MyAdapter(this, R.layout.list_view_item, fruitList);
        simpleList.setAdapter(myAdapter);
        simpleList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Item item = (Item)simpleList.getItemAtPosition(position);
                Toast.makeText(getBaseContext(), item.getFruitName(),
                        Toast.LENGTH_SHORT).show();
                try {
                    Intent intent = new Intent(MainActivity.this, Description.class);
                    intent.putExtra(MESSAGE, Data.get(item.getFruitName()));
                    startActivity(intent);
                } catch (Exception e) {/* Log error messages */}
            }
        }); //end of setOnClickListener()
    } // end of onCreate()
} // end of class MainActivity