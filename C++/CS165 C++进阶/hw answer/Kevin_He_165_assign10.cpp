#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

// Function prototypes
vector<string> getVector(string);
string getName(string);
void selectionSort(vector<string>&);
bool binarySearch(string, vector<string>);
void displayResult(string, string, bool);
void writeToFile(string, vector<string>);
void reverseVector(vector<string>&);

int main()
{
   string boyName, girlName;   // Hold's the boy's/girl's name
   bool boyNameFound, girlNameFound;  // Indicates whether the boy/girl name was found

   // Initialize vectors with the names from the files.
   vector<string> boyNames(getVector("BoyNames.txt"));
   vector<string> girlNames(getVector("GirlNames.txt"));
   
   
   boyName = getName("boy's");   // Get the boy/girl names as input from the user.
   girlName = getName("girl's");
   
   selectionSort(boyNames);   // sort the boy/girl vectors in ascending order
   selectionSort(girlNames);
   
   boyNameFound = binarySearch(boyName, boyNames);  // search for the boy/girl names using binary search
   girlNameFound = binarySearch(girlName, girlNames);
   
   displayResult("boy's", boyName, boyNameFound);    // Display the results for the boy/girl names
   displayResult("girl's", girlName, girlNameFound);
   
   writeToFile("Boynames_asc.txt", boyNames); // write the boy/girl names to their respective files in ascending order
   writeToFile("Girlnames_asc.txt", girlNames);
   
   reverseVector(boyNames); //reverse the boy/girl vectors so they are both in descending order
   reverseVector(girlNames);

   writeToFile("Boynames_desc.txt", boyNames); // write the boy/girl names to their respective files in descending order
   writeToFile("Girlnames_desc.txt", girlNames);
   
   cout<< endl << endl;
   
   system("PAUSE");
   return 0;
}

// ********************************************************
// The getVector function reads data from a file, stores  *
// it in a vector, and returns the vector.                *
// ********************************************************
vector<string> getVector(string filename)
{
	vector<string> name;
	string names;
	ifstream file;
	file.open(filename);
	while(file >> names ){
		name.push_back(names);
	}
	file.close();

	return name;
}

// ********************************************************
// The getName function prompts the user to enter a    *
// boy's/girl's name and returns the value.                      *
// ********************************************************


string getName(string gender)
{
	string name;

	cout << "Enter a " << gender << " name, or N if you";
	cout << "\ndo not wish to enter a " << gender << " name: ";
	cin >> name;
	cout << endl;

	return name;   
}

void selectionSort(vector<string> &arr)
{
	
	int startScan, minIndex;
	string minValue;

   for (startScan = 0; startScan < (arr.size() - 1); startScan++)
   {
      minIndex = startScan;
      minValue = arr[startScan];
      for(int index = startScan + 1; index < arr.size(); index++)
      {
         if (arr[index] < minValue)
         {
            minValue = arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = minValue;
   }
	
}


// ********************************************************
// The binarySearch function returns true if the boy/girl name is found *
// in the boy/girl vector. Otherwise, it returns false.          *
// ********************************************************

bool binarySearch(string name, vector<string> arr)
{
	int i = 0;
	int j = arr.size() - 1;
	int x;

	while (i <= j && !false){
		x = (i + j) / 2;		
		if (arr[x] == name){
			return true;
		}
		else if (arr[x] > name)
			j = x - 1;
		else
			i = x + 1;
	}

	return false;
	}
	
// ********************************************************
// The displayBoyResult function determines if the boy's/girl's  *
// name is popular or not and displays the result.        *
// *******************************************************

void displayResult(string gender, string name, bool nameFound)
{
	if (name == "N")
		cout << "You chose not to enter a " << gender << " name.";
	else if (!nameFound)
		cout << name << " is NOT one of the most popular " << gender << " names.";
	else
		cout << name << " is one of the most popular " << gender << " names.";

	cout << endl;

}


// ********************************************************
// The writeToFile function writes the contents of the specified vector *
// into the specified file *
// ********************************************************

void writeToFile(string filename, vector<string> arr)
{
	ofstream file(filename);

	for (int i = 0; i < arr.size(); i++)
		file << arr[i] << endl;

	file.close();
}

// ********************************************************
// The reverseVector function reverses the order of the specified vector *
// ********************************************************

void reverseVector(vector<string> &arr)
{
	string temp;

	for (int i = 0; i < (arr.size() / 2); i++){
		temp = arr[i];
		arr[i] = arr[(arr.size() - 1) - i];
		arr[(arr.size() - 1) - i] = temp;
	}
}
