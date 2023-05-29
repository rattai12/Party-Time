#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Ingredients {
public:
	vector <Ingredients> priceList;
	string ingredient;
	int price;

	void readPrice();
	void showPricelist();
};

class Drink: public Ingredients{
public:
	vector<Drink>drinklista;
	int cl;
	string name;

	
	Drink(Ingredients ingredient, Drink name, int amount){} //konstruktor för drinkar
	Drink() : cl(0), name("") {}
	void blandaDrink();
	void readDrinks();
	void drinkRead(string filnamn);
};
