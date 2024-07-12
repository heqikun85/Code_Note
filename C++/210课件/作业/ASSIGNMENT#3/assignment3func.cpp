#include <iostream>
#include "assignment3.h"

using namespace std;

//A default constructor that sets the dynamic array to NULL ( or nullptr) and sets size to 0.
template <class T>
DynamicArray<T>::DynamicArray()
{
	dynamicArray = NULL;
	Size = 0;
}

// A function that returns size.
template <class T>
int DynamicArray<T>::getSize()const
{
	return Size;
}

//A function named addEntry that takes a string as input
//The function should create a new dynamic array one element larger than dynamicArray,
//copy all elements from dynamicArray into the new array,
//add the new string onto the end of the new array, increment size,
//delete the old dynamicArray,and then set dynamicArray to the new array.
template <class T>
void DynamicArray<T>::addEntry(T name)
{
	T *dynamicArray2;
	Size++;
	if (dynamicArray == NULL) {
		dynamicArray = new T[Size];
		for (int i = 0; i < Size; i++)
			dynamicArray[i] = name;
	}
	else {
		dynamicArray2 = new T[Size];
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
template <class T>
bool DynamicArray<T>::deleteEntry(T name)
{
	for (int i = 0; i < Size; i++) {
		if (name == dynamicArray[i]) {
			Size--;
			T *dynamicArray2 = new T[Size];
			for (int j = 0; j < Size; j++) {
				if (i > j)
					dynamicArray2[j] = dynamicArray[j];
				else
					dynamicArray2[j] = dynamicArray[j + 1];
			}
			delete[] dynamicArray;
			dynamicArray = new T[Size];
			for (int i = 0; i < Size; i++)
				dynamicArray[i] = dynamicArray2[i];
			return true;
		}
	}
	return false;
}

//A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray.
//Return NULL if the index is out of dynamicArray¡¯s bounds.
template <class T>
T DynamicArray<T>::getEntry(int num)
{
	if (num < Size)
		return dynamicArray[num];
	else
		return NULL;
}

//A copy constructor that makes a copy of the input object¡¯s dynamic array.
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copy)
	:Size(copy.getSize())
{
	dynamicArray = new T[Size];
	for (int i = 0; i < Size; i++)
		dynamicArray[i] = copy.dynamicArray[i];
}

//Overload the assignment operator so that the dynamic array is properly copied to the target object.
template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& assignment) {
	if (Size != assignment.Size) {
		delete[]dynamicArray;
		dynamicArray = new T[assignment.Size];
	}
	Size = assignment.Size;
	for (int i = 0; i < Size; i++) {
		dynamicArray[i] = assignment.dynamicArray[i];
		return *this;
	}
}

//A destructor that frees up the memory allocated to the dynamic array.
template <class T>
DynamicArray<T>::~DynamicArray() {
	delete[]dynamicArray;
}
