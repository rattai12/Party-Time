#include <iostream>
#include "drinkar.h"

using namespace std;
void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}

int main() {
	
	svenska();
	//extern Ingredient globalIngredients;
	

	bool run = true;
	while (run) {
		Drink drink;
		Ingredient ingredient;
		int menyval;
		
		cout << "1. Blanda drink" << endl;
		cout << "2. Sök på namn" << endl;
		cout << "3. Sök på ingrediens" << endl;
		cout << "4. Visa prislista" << endl;

		cout << "\nAnge val: ";
		cin >> menyval;
		switch (menyval) {

		case 1:
			drink.readDrinks();
			drink.blendDrink();
			


		case 2:
			break;
		case 3:
			break;
		case 4:
			ingredient.readPrice();
			ingredient.showPricelist();
			break;

		case 0:
				run = false;
		}
	}

}
