#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int SIZE = 5;

struct drink {
	string name;
	const double cost;
	int number;
}DATA[SIZE] = { { "Cola", .75, 20 },
				{ "Root Beer", .75, 20 },
				{ "Lemon-Lime", .75, 20 },
				{ "Grape Soda", .80, 20 },
				{ "Cream Soda", .80, 20 } };

void print(drink []);
int getchoice();
double getCharge();
double change(double, drink[], int); 
int LEAVE(drink[], int);
double earn(drink[], int);
void result(drink[]);

int main() {

	result(DATA);

	system("pause");
	return 0;
}

void print(drink DATA[]) {
	
	for (int i = 0 ; i < SIZE ; i++) {
		cout << i+1 << ". " << left << setw(15) << DATA[i].name;
		cout << fixed << setprecision(2) << right << DATA[i].cost << endl;
	}
	cout << 6 << ". " << left << "leave the drink machine" << endl;
}

int getchoice() {
	int choice;
	cout << "\nChoose one: ";
	cin >> choice;
	return choice;
}

double getCharge() {
	double charge = 0;
	cout << "Enter an amount of money: ";
	cin >> charge;
	while (charge < 0.75 || charge > 1) {
		cout << "Enter at least 0.75 and not more than 1 dollar.";
		cin >> charge;
	}
	cout << "\nEnjoy your beverage!"<< endl;
	return charge;
}

double change(double charge, drink DATA[],int choice) {
	double change = 0;
	change = charge - DATA[choice-1].cost;
	cout << "\nChange calculated: " << change << endl;
	if(change != 0)
	cout << "Your change, " << change << " has just dropped into the Change Dispenser." << endl;
	return change;
}

double earn(drink DATA[], int choice) {
	return DATA[choice-1].cost;
}
int LEAVE(drink DATA[], int choice) {
	DATA[choice-1].number -= 1;
	cout << "\nThere are " << DATA[choice-1].number << " drinks of that type left" << endl << endl;
	return DATA[choice-1].number;
}

void result(drink DATA[]) {
	int num1 = 0;
	double num2 = 0;
	double sum = 0;

	print(DATA);
	num1 = getchoice();

	while(num1!=6){
		num2 = getCharge();
		change(num2, DATA, num1);
		sum += earn(DATA, num1);
		LEAVE(DATA, num1);
		print(DATA);
		num1 = getchoice();
	}

	cout << "Total earnings: $" << sum << endl;

}