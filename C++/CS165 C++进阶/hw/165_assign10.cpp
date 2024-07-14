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
   
   cout<<endl;
   
   system("PAUSE");
   return 0;
}

// ********************************************************
// The getVector function reads data from a file, stores  *
// it in a vector, and returns the vector.                *
// ********************************************************
vector<string> getVector(string filename)
{
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
}

// ********************************************************
// The getName function prompts the user to enter a    *
// boy's/girl's name and returns the value.                      *
// ********************************************************


string getName(string gender)
{
 
   // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
   
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
	
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  
    // do NOT use a built-in function to do the searching
   // do NOT use a built-in function to do the searching
   // do NOT use a built-in function to do the searching
   // do NOT use a built-in function to do the searching
   // do NOT use a built-in function to do the searching
	
	
	
}

// ********************************************************
// The displayBoyResult function determines if the boy's/girl's  *
// name is popular or not and displays the result.        *
// *******************************************************

void displayResult(string gender, string name, bool nameFound)
{
	
	  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
   
}


// ********************************************************
// The writeToFile function writes the contents of the specified vector *
// into the specified file *
// ********************************************************

void writeToFile(string filename, vector<string> arr)
{

	  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
}

// ********************************************************
// The reverseVector function reverses the order of the specified vector *
// ********************************************************

void reverseVector(vector<string> &arr)
{
	
     // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  // ----- IMPLEMENT THIS -----
  
  
  // do NOT use the built-in reverse function
  // do NOT use the built-in reverse function
  // do NOT use the built-in reverse function
  // do NOT use the built-in reverse function
  // do NOT use the built-in reverse function
  
	
}
