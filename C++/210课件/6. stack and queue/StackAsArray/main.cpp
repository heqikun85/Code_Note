/// ******************************************************
/// File: main.cpp
/// Purpose: Main file tests for an unsorted
///	stack implemented as an array.
/// ******************************************************
#include "StackAsArray.h"

int main()
{
	char testString[MAX_SIZE];
	int	i;
	char ch;
	StackAsArray * theStack;


	cout << "\n\tSimple Stack Demonstration\n\n\n";
	cout << "\t(Stack implemented as an Array - Stack data type is character.)\n\n";
	cout << "\tCreating a stack...\n\n";

	theStack = new StackAsArray(); /// Instantiate a stack object

	cout << "\tStack created...\n\n";

	/// Test pushing and popping first/last item on a stack
	cout << "\tTesting push and pop of single item ( push and pop A ).\n\n";
	cout << theStack->Push('A') << endl;
	cout << theStack->Push('B') << endl;
	cout << theStack->Push('C') << endl;
	cout << theStack->Push('D') << endl;
	cout << theStack->Push('E') << endl;

	cout << "\tPopped: " << theStack->Pop() << "\n\n";
	cout << "\t\t...done\n\n";
/*
	/// Test stack by reversing the order of letters in a string
	cout << "\tEnter a string to be reversed :::   ";
	/// Use get() so we can input spaces
	cin.getline(testString,MAX_SIZE); // Assume user is smart enought to not exceed the limit

	/// Push all letters on the stack
	i = 0;
	while(testString[i] != '\0')
	{
		theStack->Push(testString[i]);
		i++;
	}
*//*
	/// Pop letters and print in reverse
	cout << "\n\tYour string printed in reverse is ::: \t";
	while((ch = theStack->Pop()) != '\0') // Pop returns null terminator when stack is empty
		cout << ch;

	cout << "\n\n\t...done.\n";
	*/
	return 0;
}

