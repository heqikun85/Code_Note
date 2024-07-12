#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray
{
public:
		DynamicStringArray();
	int getSize()const;
	void addEntry(string);
	bool deleteEntry(string);
	string getEntry(int);
	DynamicStringArray(const DynamicStringArray&);
	DynamicStringArray& operator=(const DynamicStringArray&);
	~DynamicStringArray();

private:
	string *dynamicArray; // A private member variable called dynamicArray that references a dynamic array of type string.
	int Size; // A private member variable called size that holds the number of entries in the array.

};

int main()
{
	DynamicStringArray names;

	// List of names
	names.addEntry("Frank");
	names.addEntry("Wiggum");
	names.addEntry("Nahasapeemapetilon");
	names.addEntry("Quimby");
	names.addEntry("Flanders");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	// Add and remove some names
	names.addEntry("Spuckler");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	names.deleteEntry("Nahasapeemapetilon");
	cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	names.deleteEntry("Skinner");
	cout << "After removing a name that isn't on the list:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	names.addEntry("Muntz");
	cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	// Remove all of the names by repeatedly deleting the last one
	while (names.getSize() > 0) {
		names.deleteEntry(names.getEntry(names.getSize() - 1));
	}

	cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	names.addEntry("Olivia");
	cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Olivia from names
	names.deleteEntry("Olivia");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Olivia from names2
	names2.deleteEntry("Olivia");
	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;

}

//A default constructor that sets the dynamic array to NULL ( or nullptr) and sets size to 0.
DynamicStringArray::DynamicStringArray()
{
	dynamicArray = NULL;
	Size = 0;
}

// A function that returns size.
int DynamicStringArray::getSize()const
{
	return Size;
}

//A function named addEntry that takes a string as input
//The function should create a new dynamic array one element larger than dynamicArray,
//copy all elements from dynamicArray into the new array,
//add the new string onto the end of the new array, increment size,
//delete the old dynamicArray,and then set dynamicArray to the new array.
void DynamicStringArray::addEntry(string name)
{
	string *dynamicArray2;
	Size++;
	if (dynamicArray == NULL) {
		dynamicArray = new string[Size];
		for (int i = 0; i < Size; i++)
			dynamicArray[i] = name;
	}
	else {
		dynamicArray2 = new string[Size];
		for (int i = 0; i < Size - 1; i++)
			dynamicArray2[i] = dynamicArray[i];
		dynamicArray2[Size - 1] = name;
		delete[] dynamicArray;
		dynamicArray = dynamicArray2;
	}
}

//A function named deleteEntry that takes a string as input.
//The function should search dynamicArray for the string.
//If not found, return false.
//If found, create a new dynamic array one element smaller than dynamicArray.
//Copy all elements except the input string into the new array,
//delete  dynamicArray, decrement size, and return true.
bool DynamicStringArray::deleteEntry(string name)
{
	for (int i = 0; i < Size; i++) {
		if (name == dynamicArray[i]) {
			Size--;
			string *dynamicArray2 = new string[Size];
			for (int j = 0; j < Size; j++) {
				if (i > j)
					dynamicArray2[j] = dynamicArray[j];
				else
					dynamicArray2[j] = dynamicArray[j + 1];
			}
			delete[] dynamicArray;
			dynamicArray = new string[Size];
			for (int i = 0; i < Size; i++)
				dynamicArray[i] = dynamicArray2[i];
			return true;
		}
	}
	return false;
}

//A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray.
//Return NULL if the index is out of dynamicArray¡¯s bounds.
string DynamicStringArray::getEntry(int num)
{
	if (num < Size)
		return dynamicArray[num];
	else
		return NULL;
}

//A copy constructor that makes a copy of the input object¡¯s dynamic array.
DynamicStringArray::DynamicStringArray(const DynamicStringArray& copy)
	:Size(copy.getSize())
{
	dynamicArray = new string[Size];
	for (int i = 0; i < Size; i++)
		dynamicArray[i] = copy.dynamicArray[i];
}

//Overload the assignment operator so that the dynamic array is properly copied to the target object.
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& assignment) {
	if (Size != assignment.Size) {
		delete[]dynamicArray;
		dynamicArray = new string[assignment.Size];
	}
	Size = assignment.Size;
	for (int i = 0; i < Size; i++) {
		dynamicArray[i] = assignment.dynamicArray[i];
		return *this;
	}
}

//A destructor that frees up the memory allocated to the dynamic array.
DynamicStringArray::~DynamicStringArray() {
	delete[]dynamicArray;
}