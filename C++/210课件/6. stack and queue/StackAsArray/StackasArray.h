#ifndef STACKASARRAY_H_INCLUDED
#define STACKASARRAY_H_INCLUDED
/// **********************************************
/// File: StackAsArray.h
/// Purpose: Header file for a stack implemented
///	as an array.  Data type: Character
/// **********************************************

#include <iostream>
using namespace std;

#define MAX_SIZE 3               /// Define maximum length of the stack

class StackAsArray
{
	private:
		int top;                  /// Index to top of the stack
		char theStack[MAX_SIZE];  /// The stack

	public:
		StackAsArray();         /// Class constructor
		~StackAsArray();        /// Class destuctor
		void ClearStack();      /// Remove all items from the stack
		bool Push(char ch);     /// Push an item onto the stack
		char Pop();             /// Pop an item from the stack
		bool isEmpty();         /// Return true if stack is empty
		bool isFull();          /// Return true if stack is full
};

#endif // STACKASARRAY_H_INCLUDED
