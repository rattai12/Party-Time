#include "drinkar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;



void Drink::blandaDrink()
{

}

void Drink::readDrinks()
{
    drinkRead("d1.txt");
    drinkRead("d2.txt");
    drinkRead("d3.txt");
    drinkRead("d4.txt");
    drinkRead("d5.txt");
    drinkRead("d6.txt");
    drinkRead("d7.txt");
    drinkRead("d8.txt");
}

void Drink::drinkRead(string filnamn)
{
    ifstream inputFile(filnamn);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string drinkName;
    getline(inputFile, drinkName); // Read the drink name

    // Create a new Drink object
    Drink* myDrink = new Drink();
    myDrink->name = drinkName;

    string ingredientName;
    string ingredientAmount;
    string ingredientLine;
    int linenum = 0;

    while (getline(inputFile, ingredientLine)) {
        if (linenum == 0) {
            drinkName = ingredientLine;
            linenum++;
        }else{
            int index = ingredientLine.find("cl");
            ingredientAmount = ingredientLine.substr(0, index - 1);
            ingredientName = ingredientLine.substr(index + 3);

            // For example, printing the ingredient details
            
            cout << drinkName << " Ingredient: " << ingredientName << ", Amount: " << ingredientAmount << " cl" << endl;

        }
        Drink drink(ingredient, drinkName, ;
        
    }

  

    // Remember to deallocate the memory for the created Drink object
    delete myDrink;

    inputFile.close();
}





void Ingredients::readPrice()
{
	Ingredients ingredient;
	string line;
	ifstream pris("prislista.txt");

	while (getline(pris, line)) {
		stringstream ss(line);
		string price_string;
		ss >> price_string;
		ss >> ingredient.ingredient;

		ingredient.price = stoi(price_string);
		priceList.push_back(ingredient); // lägger in priserna i en prislista med ett objekt av drink. 
	}
	pris.close();
}

void Ingredients::showPricelist()
{
	for (int i = 0; i < size(priceList); i++) {
		cout << (priceList[i].price) << " kr   ";
		cout << priceList[i].ingredient << endl;
	}
}
