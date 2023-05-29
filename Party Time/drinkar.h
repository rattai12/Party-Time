#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Ingredient {
public:
    string ingredient;
    int price;
    vector <Ingredient> priceList;
    Ingredient(const string& ingredientName, int price) : ingredient(ingredientName), price(price) {}
    Ingredient() : ingredient(""), price(0) {}

    void readPrice();
    void showPricelist();
};

class Drink {
public:
    string name;
    
    vector<Ingredient> ingredientList;
    vector<Drink> drinkList;
    Drink(const string& drinkName, const vector<Ingredient>& ingredients) : name(drinkName), ingredientList(ingredients) {}
    Drink() : name(""), ingredientList(vector<Ingredient>()) {}

    void blendDrink();
    void readDrinks();
    void drinkRead(string filnamn);
    void showDrinks();
    void showSpecificDrink(int number);
};
