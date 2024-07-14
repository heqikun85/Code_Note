#include <iostream>
using namespace std;

// Function prototypes
int getMode(int *, int);
int *makeArray(int);

int main()
{
	// Constant for the array size
	const int SIZE = 11;
   
	// An array of test values
	int test[SIZE] = {1, 2, 3, 3, 3, 2, 2, 1, 3, 4, 5};
   
	// A variable to hold the mode of the test values
	int mode;

	// Get the mode of the test values.
	mode = getMode(test, SIZE);
   
	// Display the mode, if any.
	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: " 
		     << mode << endl;

    system("PAUSE");
	return 0;
}

//**********************************************************
// Function getMode                                        *
// This function returns the mode of the array pointed to  *
// by array. If there is no mode, the function returns -1. *
//**********************************************************
int getMode(int *array, int size)
{
	// A pointer to reference a dynamically allocated array
	// to hold the frequencies of each value.
	int *frequencies = nullptr;
	
    // PUT THE REST OF THE VARIABLE DECLARATIONS HERE
    // PUT THE REST OF THE VARIABLE DECLARATIONS HERE
    // PUT THE REST OF THE VARIABLE DECLARATIONS HERE
    // PUT THE REST OF THE VARIABLE DECLARATIONS HERE
    // PUT THE REST OF THE VARIABLE DECLARATIONS HERE

	// Dynamically allocate an array to hold
	// the frequencies of each element in the
	// array. When this function ends, frequencies[0]
	// will hold the frequency of the value in
	// array[0], and so forth.
	frequencies = makeArray(size);
	
	
	// IMPLEMENT THE REST OF THIS FUNCTION STARTING HERE
	// IMPLEMENT THE REST OF THIS FUNCTION STARTING HERE
	// IMPLEMENT THE REST OF THIS FUNCTION STARTING HERE
	// IMPLEMENT THE REST OF THIS FUNCTION STARTING HERE
	// IMPLEMENT THE REST OF THIS FUNCTION STARTING HERE
   
	
	
}

//********************************************************
// Function makeArray                                    *
// This function dynamically allocates an array of ints  *
// and returns a pointer to it. The size parameter is    *
// the number of elements to allocate.                   *
//********************************************************

int* makeArray(int size)
{
	// IMPLEMENT THIS FUNCTION
	// IMPLEMENT THIS FUNCTION
	// IMPLEMENT THIS FUNCTION
	// IMPLEMENT THIS FUNCTION
	// IMPLEMENT THIS FUNCTION
}
