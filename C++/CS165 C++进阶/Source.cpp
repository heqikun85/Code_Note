#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 5;

struct Drink {
	string Name;
	double Cost;
	int Number;
};

void getData(Drink[]);

int main() {
	Drink *Menu;
	Menu = getData();

	system("Pause");
	return 0;
}

void getData(Drink Menu[]) {
	Drink menu[SIZE] = { {"Cola",.75,20},
			{"Root Beer",.75,20},
			{"Lemon-Lime",.75,20},
			{"Grape Soda",.80,20},
			{"Cream Soda",.80,20} };
	Menu = menu;
	for (int i = 0; i < SIZE; i++) {
		cout << i + 1 << ". " << left << setw(15) << Menu[i].Name;
		cout << fixed << setprecision(2) << right << Menu[i].Cost << endl;
	}
}
 /*
Drink *getData() {
	Drink menu [SIZE]  ={ {"Cola",.75,20},
						{"Root Beer",.75,20},
						{"Lemon-Lime",.75,20},
						{"Grape Soda",.80,20},
						{"Cream Soda",.80,20} };

return menu;
}
 */