package com.example.listview;

public class Item {
    String fruitName;
    int fruitImage;
    public Item(String fruitName, int fruitImage) {
        this.fruitImage = fruitImage;
        this.fruitName = fruitName;
    }
    public String getFruitName() {
        return fruitName;
    }
    public int getFruitImage() {
        return fruitImage;
    }
}
