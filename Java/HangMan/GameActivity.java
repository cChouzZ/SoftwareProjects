package com.example.hangman;

import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.Random;

public class GameActivity extends AppCompatActivity {

    private String[] easyWords = {"bear", "slug", "boar", "wolf", "lion",
            "goat", "clam", "hawk", "toad", "duck"};
    private String[] mediumWords = {"zebra", "mouse", "whale", "snake", "tiger",
            "sloth", "gecko", "raven", "shark", "chimp"};
    private String[] hardWords = {"gopher", "wombat", "badger", "weasel", "walrus",
            "python", "beaver", "beluga", "donkey", "shrimp"};

    private int[] hangmanImages = {R.drawable.image1, R.drawable.image2, R.drawable.image3,
            R.drawable.image4, R.drawable.image5, R.drawable.image6, R.drawable.image7};

    private int currentImageIndex = 0;

    private String word;

    private StringBuilder guessedLetters = new StringBuilder();

    private String difficulty;

    private SharedPreferences sharedPreferences;
    private SharedPreferences.Editor editor;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_game);

        difficulty = getIntent().getStringExtra("difficulty");

        resetGame();

        ImageView imageView = (ImageView) findViewById(R.id.imageView);

        imageView.setImageResource(hangmanImages[currentImageIndex]);

        EditText editText = (EditText) findViewById(R.id.letter);

        Button button = (Button) findViewById(R.id.button);
        Button button1 = (Button) findViewById(R.id.button1);
        Button button2 = (Button) findViewById(R.id.button2);

        sharedPreferences = getSharedPreferences("HangmanStats", MODE_PRIVATE);
        editor = sharedPreferences.edit();

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                PopupMenu popup = new PopupMenu(GameActivity.this, button);

                popup.getMenuInflater().inflate(R.menu.popup_menu, popup.getMenu());

                popup.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                    public boolean onMenuItemClick(MenuItem item) {
                        int id = item.getItemId();
                        if (id == R.id.item1) {

                            int wins = sharedPreferences.getInt(difficulty + "Wins",
                                    0);
                            int losses = sharedPreferences.getInt(difficulty + "Losses",
                                    0);
                            Toast.makeText(GameActivity.this, "Wins: " + wins +
                                    "\nLosses: " + losses, Toast.LENGTH_LONG).show();
                            return true;
                        } else if (id == R.id.item2) {

                            editor.putInt(difficulty + "Wins", 0);
                            editor.putInt(difficulty + "Losses", 0);
                            editor.apply();
                            Toast.makeText(GameActivity.this,
                                    "Wins and losses have been reset to zero.",
                                    Toast.LENGTH_SHORT).show();
                            return true;
                        } else if (id == R.id.item3) {

                            resetGame();
                            return true;
                        } else {
                            return false;
                        }
                    }
                });

                popup.show();
            }
        });

        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String letter = editText.getText().toString();

                if (word.contains(letter)) {

                    guessedLetters.append(letter);

                    boolean wordGuessed = true;
                    for (char c : word.toCharArray()) {
                        if (guessedLetters.indexOf(String.valueOf(c)) == -1) {
                            wordGuessed = false;
                            break;
                        }
                    }

                    if (wordGuessed) {
                        int wins = sharedPreferences.getInt(difficulty + "Wins", 0);
                        editor.putInt(difficulty + "Wins", wins + 1);
                        editor.apply();

                        new AlertDialog.Builder(GameActivity.this)
                                .setTitle("Congratulations!")
                                .setMessage("You win!")
                                .setPositiveButton("Start a new game",
                                        new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int which) {

                                        resetGame();
                                    }
                                })
                                .setNegativeButton(android.R.string.no, null)
                                .setIcon(android.R.drawable.ic_dialog_alert)
                                .show();
                    } else {
                        Toast.makeText(GameActivity.this, "Correct!",
                                Toast.LENGTH_SHORT).show();
                    }
                } else {
                    updateHangmanImage();
                    if (currentImageIndex >= hangmanImages.length - 1) {

                        int losses = sharedPreferences.getInt(difficulty + "Losses",
                                0);
                        editor.putInt(difficulty + "Losses", losses + 1);
                        editor.apply();

                        new AlertDialog.Builder(GameActivity.this)
                                .setTitle("Game Over")
                                .setMessage("You lose! The word was " + word)
                                .setPositiveButton("Start a new game",
                                        new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int which) {

                                        resetGame();
                                    }
                                })
                                .setNegativeButton(android.R.string.no, null)
                                .setIcon(android.R.drawable.ic_dialog_alert)
                                .show();
                        imageView.setImageResource(hangmanImages[currentImageIndex]);
                    } else {
                        Toast.makeText(GameActivity.this, "Choose another word!",
                                Toast.LENGTH_SHORT).show();
                    }
                }

                editText.setText("");
            }

        });

    }

    private void resetGame() {

        guessedLetters.setLength(0);

        currentImageIndex = 0;
        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        imageView.setImageResource(hangmanImages[currentImageIndex]);

        Random random = new Random();
        if ("Easy".equals(difficulty)) {
            word = easyWords[random.nextInt(easyWords.length)];
        } else if ("Medium".equals(difficulty)) {
            word = mediumWords[random.nextInt(mediumWords.length)];
        } else if ("Hard".equals(difficulty)) {
            word = hardWords[random.nextInt(hardWords.length)];
        } else {
            throw new IllegalArgumentException("Invalid difficulty: " + difficulty);
        }
    }

    private void updateHangmanImage() {
        if ("Hard".equals(difficulty) && currentImageIndex < 3) {
            currentImageIndex += 2;
        } else if ("Medium".equals(difficulty) && currentImageIndex < 2) {
            currentImageIndex += 2;
        } else {
            currentImageIndex++;
        }

        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        imageView.setImageResource(hangmanImages[currentImageIndex]);

    }
}

