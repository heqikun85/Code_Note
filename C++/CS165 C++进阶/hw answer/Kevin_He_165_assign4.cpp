#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototype
double population(double, double, double, int, int);
void getNum(double &, double &, double &, int &, int &, int &);
void showresult(double, double, double, int, int, int);

int main()
{
	double popula;//The starting size of a population ?
	double birthRate;//The annual birth rate ?
	double deathRate;//The annual death rate ?
    int arrNum;//The number of individuals who move into the area each year ?
	int leaNum;//The number of individuals who leave the area each year
	int year;

    getNum(popula,birthRate,deathRate,arrNum,leaNum,year);

    cout << "\nStarting population: "<< popula << endl << endl;

    showresult(popula,birthRate,deathRate,arrNum,leaNum,year);

}
void getNum(double &popula, double &birthRate, double &deathRate, int &arrNum, int &leaNum, int &year){
	cout <<"This program calculates population change.\n"
         <<"Enter the starting population size: ";
    cin >> popula;
    while(popula < 2){
        cout <<"Starting population must be 2 or more.\n"
             <<"Please re-enter: ";
        cin >> popula;
    }

    cout <<"Enter the annual birth rate (as % of current population): ";
    cin >> birthRate;
    while(birthRate < 0){
        cout <<"Birth rate percent cannot be negative.\n"
             <<"Please re-enter: ";
        cin >> birthRate;
    }

    cout <<"Enter the annual death rate (as % of current population): ";
    cin >> deathRate;
    while(deathRate < 0){
        cout <<"Death rate percent cannot be negative.\n"
             <<"Please re-enter: ";
        cin >> deathRate;
    }

    cout <<"How many individuals move into the area each year?: ";
    cin >> arrNum;
    while(arrNum < 0){
        cout <<"Arrivals cannot be negative.\n"
             <<"Please re-enter: ";
        cin >> arrNum;
    }

    cout <<"How many individuals leave the area each year?: ";
    cin >> leaNum;
    while(leaNum < 0){
        cout <<"Departures cannot be negative.\n"
             <<"Please re-enter: ";
        cin >> leaNum;
    }

    cout <<"For how many years do you wish to view population changes? ";
    cin >> year;
    while(year < 1){
        cout <<"You must be one or more.\n"
             <<"Please re-enter: ";
        cin >> year;
    }
}

double population(double popula, double birthRate, double deathRate, int arrNum, int leaNum){

    popula = popula + round(popula*(birthRate/100)) - round(popula*(deathRate/100)) + arrNum - leaNum;

    return popula;
}

void showresult(double popula, double birthRate, double deathRate, int arrNum, int leaNum, int year)
{
    for(int i=0; i<year ; i++){
            popula = population(popula, birthRate, deathRate, arrNum, leaNum);
            cout << "Population at the end of year " <<i+1 << " is " << popula <<endl;
    }
}
// IMPLEMENT THE POPULATION FUNCTION AND OTHER FUNCTIONS
// IMPLEMENT THE POPULATION FUNCTION AND OTHER FUNCTIONS
// IMPLEMENT THE POPULATION FUNCTION AND OTHER FUNCTIONS
