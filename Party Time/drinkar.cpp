#include "drinkar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>




void Drink::readDrinks() {
    Ingredient ingredients;
    ingredients.readPrice();
    drinkRead("d1.txt");
    drinkRead("d2.txt");
    drinkRead("d3.txt");
    drinkRead("d4.txt");
    drinkRead("d5.txt");
    drinkRead("d6.txt");
    drinkRead("d7.txt");
    drinkRead("d8.txt");
}

void Drink::drinkRead(string filnamn) {
    ifstream inputFile(filnamn);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string drinkName;
    getline(inputFile, drinkName); // Read the drink name
   // cout << "Drink: " << drinkName << endl;
    vector<Ingredient> ingredients;

    string ingredientName;
    string ingredientAmount;
    string ingredientLine;

    while (getline(inputFile, ingredientLine)) {
        int index = ingredientLine.find("cl");
        ingredientAmount = ingredientLine.substr(0, index - 1);
        ingredientName = ingredientLine.substr(index + 3);

        int amount = stoi(ingredientAmount);
        ingredients.push_back(Ingredient(ingredientName, amount));

        // For example, printing the ingredient details
       //cout << "Ingredient: " << ingredientName << ", Amount: " << ingredientAmount << " cl" << endl;
    }

    Drink drink(drinkName, ingredients);
    drinkList.push_back(drink);
    // Add 'drink' to a list of drinks or do something else with it
}

void Drink::showDrinks()
{
    for (int i = 0; i < size(drinkList); i++) {
        cout << i+1 <<". " << drinkList[i].name << endl;
    }

}

void Drink::showSpecificDrink(int number)
{
    Ingredient ingredient;
    Drink drink;
    ingredient.readPrice();
    int tot_pris = 0;
    cout << "Drink: " << drinkList[number].name << endl;
    for (int i = 0; i < size(drinkList[number].ingredientList); i++) {
        int ingredient_price = 0;
        for (int j = 0; j < size(ingredient.priceList); j++) {
            if (drinkList[number].ingredientList[i].ingredient == ingredient.priceList[j].ingredient) {
                ingredient_price += ingredient.priceList[j].price;
                break;
            }
        }
        tot_pris += ingredient_price;
        cout << drinkList[number].ingredientList[i].ingredient << " " << ingredient_price << "kr" << endl;
    }
    cout << "Det totala priset för drinken " << drinkList[number].name << " är " << tot_pris << "kr" << endl;
}

void Ingredient::readPrice() {
    string line;
    ifstream pris("prislista.txt");

    if (!pris.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    while (getline(pris, line)) {
        stringstream ss(line);
        string price_string;
        ss >> price_string;
        ss >> ingredient;

        price = stoi(price_string);
        Ingredient newIngredient(ingredient, price); // create a new Ingredient object
        priceList.push_back(newIngredient); // add the new I
    }
}

void Ingredient::showPricelist()
{
    // Assuming priceList is a vector<Ingredient>
    for (int i = 0; i < size(priceList); i++) {
        cout << priceList[i].price << " kr " << priceList[i].ingredient << endl;
    }
}
void Drink::blendDrink()
{
    int drinkval;
    bool run = true;
    while (run) {
        showDrinks();
        cout << "Ange vilken drink du vill blanda: " << endl;
        cin >> drinkval;
        showSpecificDrink(drinkval-1); // minus one because the for loop starts at index 0.

    }
}

