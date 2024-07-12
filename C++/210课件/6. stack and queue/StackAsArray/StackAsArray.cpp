#include "StackAsArray.h"


/// *********************************
/// Function: StackAsArray()
/// Purpose: Class constructor
/// Returns: nothing
/// *********************************
StackAsArray::StackAsArray()
{
	top = -1;
}

/// *********************************
/// Function: StackAsArray()
/// Purpose: Class destructor
/// Returns: noyhing
/// *********************************
StackAsArray::~StackAsArray()
{
	/// Nothing to do here since the memory used
	/// for the stack is freed automatically.
}

/// *********************************
/// Function: ClearStack()
/// Purpose: Remove all items from the stack
/// Returns: nothing
/// *********************************
void StackAsArray::ClearStack()
{
	top = -1; /// Reset count to start over
}

/// *********************************
/// Function: Push()
/// Purpose: Push an item onto the stack.
/// Returns: true if push was successful
///		or false if the push failed.
/// *********************************
bool StackAsArray::Push(char ch)
{
	/// Check to see if the stack if full
	if(isFull()) return false;

	/// Increment head index
	top++;
	/// Add the item to the stack
	theStack[top] = ch;
	return true;
}

/// *********************************
/// Function: Pop()
/// Purpose: Pop an item from the Stack.
/// Returns: true if pop was successful
///		or false if the pop failed.
/// *********************************
char StackAsArray::Pop()
{
	char ch;

	/// Check for empty Stack
	if(isEmpty()) return '\0'; /// Return null character if stack is empty
	else
	{
		ch = theStack[top]; /// Get character to return
		top--;              /// Decrement top index
		return ch;          /// Return popped character
	}
}

/// *********************************
/// Function: isEmpty()
/// Purpose: Return true if the stack is empty
/// Returns: true if empty, otherwise false
/// *********************************
bool StackAsArray::isEmpty()
{
	return (top == -1);
}

/// *********************************
/// Function: isFull()
/// Purpose: Return true if the stack is full
/// Returns: true if full, otherwise false
/// *********************************
bool StackAsArray::isFull()
{
	return (top >= MAX_SIZE - 1);
}

