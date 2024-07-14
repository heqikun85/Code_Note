#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctype.h>
using namespace std;

const int SIZE = 3;

struct Customer{
     string CustomerID;
	 int StreamingMovies;
	 int StreamingTV;
	 int MultipleLines;
	 double MonthlyCharges;
};



void input(Customer customers[])
{
		Customer data;
	    
		for(int i = 0; i < SIZE; i++)
		{
			cout << "Enter the imformation for a customer " << endl;
			cout << "Customer ID: ";
			
			getline(cin, data.CustomerID);
			
						
				 if(data.CustomerID[0] >= 'A' && data.CustomerID[0] <= 'Z' && data.CustomerID[1] <= '9' && data.CustomerID[1] >= '0'&& data.CustomerID[2] <= '9' && data.CustomerID[2] >= '0'&& data.CustomerID[3] <= '9' && data.CustomerID[3] >= '0')
				{
                   
                             cout <<  "StreamingMovies: ";
                             cin >> data.StreamingMovies;
                             cout << "StreamingTV: ";
                             cin >> data.StreamingTV;
                             cout << "MultipleLine: ";
                             cin >> data.MultipleLines;
                             cout << "MonthlyCharges: ";
                             cin >> data.MonthlyCharges;
                             cout << endl;
                             cin.ignore();
                       
				}
				else
				{
					        cout << "invalid id, please re-enter" <<endl;
					        cout << endl;
					        
			    }
			customers[i] = data;
			    continue;
			
			
		};
        
       
   
}

void output(Customer data, ofstream &of)
{
	of << data.CustomerID << endl;
	of << data.StreamingMovies << endl;
	of << data.StreamingTV << endl;
	of << data.MultipleLines << endl;
	of << data.MonthlyCharges << endl;
}

int main() {
	
	ofstream of("customers.txt");
	Customer customers[SIZE];
	input(customers);
	cout << endl;
	cout << setw(20) << left << "Customers";
	cout << setw(20) << left << "StreamingMovies";
	cout << setw(20) << left << "StreamingTV";
	cout << setw(20) << left << "MultipleLine";
	cout << setw(20) << left << "MonthlyCharges" << endl;
	
	for(int i = 0; i < SIZE; i++)
{
	
    cout << setw(20) << left << customers[i].CustomerID;
    cout << setw(20) << left << customers[i].StreamingMovies;
    cout << setw(20) << left << customers[i].StreamingTV;
    cout << setw(20) << left << customers[i].MultipleLines;
    cout << setw(20) << left << customers[i].MonthlyCharges;
	cout << endl;

    output(customers[i], of);
}
    of.close();
    return 0;

}


		

											 













