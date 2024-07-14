#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
#define FILENAME "price.csv"

int Findthename(string *, int, string);

class priceApp {

private:
	string name;
	double price;


public:

	priceApp(string,double);


	~priceApp();

	priceApp();


	string getName();
	double getPrice();
	
	void setName(string);
	void setPrice(double);

};



priceApp::priceApp(string n, double p) {
		name = n;
		price = p;


}



priceApp::~priceApp() {

}


string priceApp::getName() 
{
		return name;
}

double priceApp::getPrice()
{
		return price;
}



// Setter for name
void priceApp::setName(string n) {
	name = n;
}


void priceApp::setPrice(double p)
{
	price = p;
}


priceApp* read_csv_row(string ln)
{
	string name, temp;
	double price;

	stringstream s(ln);
	getline(s,name,',');


	getline(s,temp,',');
	stringstream sd2(temp);
	sd2 >> price;

	return new priceApp(
		name,price);
} 


int Findthename(string array[], int a, string thename){
		
		int position = -1;
		
		for(int i = 0; i < a; i++){
		   if( thename == array[i])
			   position = i + 1;
		}
		return position;
		
}



int main(int argc, char *argv[]) {
	
	char choice;
	string symbol;
	string vectorApp;
	string filename = "price.csv";
	string name;
	int result;
	const int SIZE = 10000;
	string words[SIZE];
	string myname;
	
	
	ifstream f("prices.csv");

	vector<priceApp*> vectApp;

	string inputLine;

	while (getline(f, inputLine))
		{
		priceApp* pApp = read_csv_row(inputLine);
		vectApp.push_back(pApp);
		}
		
		
		
		

    result = Findthename(words, SIZE, myname);
	// Syntax is <key type, value type>


	// With a map, you can use the array syntax to assign
	// (key, value) pairs in the map.
	// The syntax is map[key] = value;

		
		
		
		
		
		
		
	
	
	while(choice !='Q'){
		     cout << endl;
			 cout << "MENU" << endl;
			 cout << "L Load a data file" << endl;
			 cout << "G Get the last closing price of a stock" << endl;
			 cout << "Q quit" << endl;
			 cout << "Enter your choice: ";
			 cin >> choice;
			 
		
			 cin.ignore();
		
			 if(choice == 'L'){
						cout << "Filename to load? " << filename << endl;
						cout << "File loaded, read " << vectApp.size() << " entries."<< endl;
						
			}
				 
			 if(choice == 'G'){
				
				        result = show(vectorApp, vectApp.size(), myname);
						cout << "Which stock symbol?";
						getline(cin, symbol);
						cout << "Yesterday's closing price of AAPL was " << endl;		
			} 
		}
		return 0;
}