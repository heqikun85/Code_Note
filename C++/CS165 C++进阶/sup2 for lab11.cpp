#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;
#define FILENAME "apps.csv"
// This class holds information about a single Google Play App,
// including most of the things we would need to display a
// "directory" of applications.

class googlePlayApp 
{

private:
		string name;
		string category;
		float rating;
		int numInstalls;
		int numReviews;
		float price;

public:
		// The constructor
		googlePlayApp(string, string, float, int, int, float);
		
		// The destructor
		~googlePlayApp();

 
		 googlePlayApp();		
		// getters
		string getName();
		string getCategory();
		float getRating();
		string getNumInstalls();
		string getNumReviews();
		string getPrice();
		// also need getters for numReviews and price
		
		// setters
		void setName(string);
		void setCategory(string);
		void setRating(float);
		void setNumInstalls(int);
		void setNumReviews(int);
		void setPrice(float);
		// also need setters for numReviews and price
};

// This constructor accepts arguments to initialize the
// app that we are creating.
googlePlayApp::googlePlayApp(string a, string b, float c, int ni, int nr, float pr) {
				name = a;
				rating = c;
				category = b;
				numInstalls = ni;
				numReviews = nr;
				price = pr;
				


}

// This constructor has no arguments and sets all the
// private members to the default values.
googlePlayApp::googlePlayApp()
{
	
}


googlePlayApp::~googlePlayApp() 
{
		// Clean up any resources when the class is
		// being deleted
}

// Access function (member) to retrieve the private name variable.
string googlePlayApp::getName() 
{
				return name;
}

string googlePlayApp::getCategory()
{
	            return category;
}
// Access function (member) to retrieve the private rating variable.
float googlePlayApp::getRating() 
{
				return rating;
}

// Access function (member) to retrieve the number of installs
string googlePlayApp::getNumInstalls() 
{       string t = "1M+";
				stringstream stream;
				if(numInstalls > 100000)
					{
						return t;
					}
				else 
				{
					 stream << numInstalls;
					 string s = stream.str();
					 return s;
				}
}

string googlePlayApp::getNumReviews()
{
		string t = "1M+";
		stringstream stream;
		if(numReviews > 100000)
			{
				return t;
			}
		else
		 {
			 stream << numReviews;
			 string s = stream.str();
			 return s;
		 }

}

string googlePlayApp::getPrice()
{
		string t = "Free";
		stringstream stream;
		if(price == 0.0)
		{
			return t;
		}
		else 
		{
			stream << fixed << setprecision(2) << price;
			string s = stream.str();
			return s;
		}
}
// Setter for name
void googlePlayApp::setName(string n) 
{
		name = n;
}

void googlePlayApp::setCategory(string c)
{
		category = c;
}
// Setter for rating
void googlePlayApp::setRating(float r) 
{
		rating = r;
}

// Setter for numInstalls
void googlePlayApp::setNumInstalls(int ni) 
{
		numInstalls = ni;
}

void googlePlayApp::setNumReviews(int nr)
{
		numReviews = nr;
}

void googlePlayApp::setPrice(float pr)
{
		price = pr;
}

googlePlayApp *read_single_app (string fields[], int len, string &ln)
{
	stringstream s(ln);
	string tmp;
	int i = 0;
	float rateT;
	int instT;
	int reviT;
	float priT;

	while (getline(s, tmp, ',')&& i < len)
		 {
				fields[i++] = tmp;   
				rateT = atof(fields[2].c_str());
				instT = atoi(fields[3].c_str());
				reviT = atoi(fields[4].c_str());
				priT = atof(fields[5].c_str());		
		 }
		
		googlePlayApp *app = new googlePlayApp(fields[0], fields[1], rateT, instT, reviT,priT);
		return app;
}

int find(googlePlayApp *array[], int a, string b)
{

	int location = -1;
	for(int i = 0; i < a; i++)
	{		 
          string mz = array[i]->getName();
          if(b == mz)
		   {
			  location = i;
		   }
	
	}
	return location;
}


int main() 
{

			const int MAXFIELDS = 10; 
			ifstream f(FILENAME);
			string inputLine;
			string fields[MAXFIELDS];
			int rowcount = 0;
			googlePlayApp *array[25];
			int result;
			string enter;
			
			while (getline(f, inputLine))
			{
                array[rowcount] = read_single_app(fields, MAXFIELDS, inputLine);
				cout << "Row: " << rowcount << endl;
				
				for (int i = 0; i < 10; i++)
				{
					if(fields[i] == "")
					   break;
					cout << "\t Field #" << i << ": " << fields[i] << endl;				
			    }
			    rowcount++;
			}			
		

           cout << "Please enter an application name (X to quit): " ;
           getline(cin, enter);
           while(enter != "X")
              {
	             result = find(array, rowcount, enter);
	             
	            if(result != -1)
	             {
	               cout << endl;
	               cout << "Name: " << array[result]->getName() << endl;
	               cout << "Category: " << array[result]->getCategory() << endl;
	               cout << "Number of installs: " << array[result]->getNumInstalls() << endl;
	               cout << "Rating: " << array[result]->getRating() << endl;
	               cout << "Price: " << array[result]->getPrice() << endl;
	               cout << "Number of reviews: " << array[result]->getNumReviews() << endl;
	               cout << "Please enter an application name (X to quit): " ;
	               getline(cin, enter);
	               cout << endl;
	             }
	 
	            else
	             {
		             cout << endl;
		             cout << "Application not found." << endl;
		             cout << "Please enter an application name (X to quit): " ;
		             getline(cin, enter);
		             cout << endl;
		             
               	 }
	
              }
}


