#include <iostream>
#include "drinkar.h"

using namespace std;
void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}

int main() {
	Drink drink;
	svenska();
	drink.readPrice();
	drink.readDrinks();

	bool run = true;
	while (run) {
		int menyval;

		cout << "1. Blanda drink" << endl;
		cout << "2. S�k p� namn" << endl;
		cout << "3. S�k p� ingrediens" << endl;
		cout << "4. Visa prislista" << endl;

		cout << "\nAnge val: ";
		cin >> menyval;
		switch (menyval) {

		case 1:
			break;


		case 2:
			break;
		case 3:
			break;
		case 4:
			drink.showPricelist();
			break;

		case 0:
				run = false;
		}
	}

}