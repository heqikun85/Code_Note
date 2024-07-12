#include "StackAsLList.h"

/// ************************************
/// Function: StackAsLList()
/// Purpose: Class constructor.
/// ************************************
StackAsLList::StackAsLList()
{
	top = NULL;
}

/// ************************************
/// Function: ~StackAsLList()
/// Purpose: Class destructor
/// ************************************
StackAsLList::~StackAsLList()
{
	ClearStack();
}

/// ************************************
/// Function: ClearStack()
/// Purpose: Remove all items from the stack
/// Returns: nothing
/// ************************************
void StackAsLList::ClearStack()
{
	struct StackNode *temp;

	if(!isEmpty())
	{
		temp = top;

		/// Scan stack and free all nodes
		while(top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
	}
	top = NULL;
}

/// ************************************
/// Function: Push()
/// Purpose: Push an item onto the stack.
/// Returns: true if push was successful
///		or false if the push failed.
/// ************************************
bool StackAsLList::Push(char ch)
{
	StackNode *newNode;

	/// Create a new node and insert the data
	newNode = new StackNode();
	/// Check to see if memory allocation failed
	if(newNode == NULL) return false;
	/// If all OK then insert the data
	newNode->ch = ch;
	newNode->next = NULL; /// Very important to init this to NULL

	/// Check to see if the stack is empty
	if(isEmpty())
	{
		/// Push new node as first in the stack
		top = newNode;
	}
	else
	{
		/// Push on top of the stack
		/// head insertion
		newNode->next = top;
		top = newNode;
	}
	return true; /// Signal successful push
}

/// ************************************
/// Function: Pop()
/// Purpose: Pop an item from the Stack.
/// Returns: true if pop was successful
///		or false if the pop failed.
/// ************************************
char StackAsLList::Pop()
{
	char ch;
	struct StackNode *temp;

	/// Check for empty stack
	if(isEmpty()) return '\0'; /// Return null character if empty

	/// Remove the top item from the stack
	temp = top;
	top = top->next;

	/// Copy the data from the top item for return
	ch = temp->ch;

	/// Free the removed node
	delete temp;
	temp = NULL;

	/// Return the popped character
	return ch;
}

/// ************************************
/// Function: isEmpty()
/// Purpose: Return true if the stack is empty
/// Returns: true if empty, otherwise false
/// ************************************
bool StackAsLList::isEmpty()
{
	return (top == NULL);
}

/// ************************************
/// Function: isFull()
/// Purpose: Return true if the stack is full.
///		A linked structure can't be full unless
///		you run out of memory.
/// Returns: true if full, otherwise false
/// ************************************
bool StackAsLList::isFull()
{
	return false;
}
