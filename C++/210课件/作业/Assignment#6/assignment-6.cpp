/**
* Stack implementation using array in C/procedural language.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Assignmenmt 06 HELP -- Stack Class Template Defionition.h"
//#include <limits.h> // For INT_MIN

using namespace std;


int main()
{
    int choice, data;

    linkedStackType<int> stack;
    linkedStackType<int> newStack;

    stack.initializeStack();

    while(1)
    {
        /* Menu */
        cout <<"------------------------------------\n";
        cout <<" STACK IMPLEMENTATION PROGRAM \n";
        cout <<"------------------------------------\n";
        cout <<"1. Push\n";
        cout <<"2. Print the top\n";
        cout <<"3. Pop\n";
        cout <<"4. Size\n";
        cout <<"5. Print Stack\n";
        cout <<"6. copy the Stack\n";
        cout <<"7. destruct the Stack\n";
        cout <<"8. Exit\n";
        cout <<"------------------------------------\n";
        cout <<"Enter your choice: ";

        cin >>choice;

switch(choice)
{
case 1:
    cout <<"Enter data to push into stack: ";
    cin >> data;

// Push element to stack

    stack.push(data);
    break;

case 2:
	cout << stack.top() << endl;
    break;

case 3:
    stack.pop();
    break;

case 4: {
	int i = 0;
	newStack = stack;
	while (!newStack.isEmptyStack())
	{
		i++;
		newStack.pop();
	}
	cout << "Stack size is " << i << endl;
	break;
}
case 5:{
	newStack = stack;
	if (!newStack.isEmptyStack()) {
		while (!newStack.isEmptyStack())
		{
			cout << newStack.top() << endl;
			newStack.pop();
		}
	}
	else
		cout << "The Stack is empty." << endl;
    break;
}
case 6: {
	linkedStackType<int> otherStack(stack);
	cout << "After the copy constructor, otherStack: " << endl;
	while (!otherStack.isEmptyStack())
	{
		cout << otherStack.top() << endl;
		otherStack.pop();
	}
	break;
}
case 7:{
    stack.~linkedStackType();
    break;
}

case 8:
    cout <<"Exiting from app.\n";
    exit(0);
    break;

default:
    cout <<"Invalid choice, please try again.\n";
}

cout <<"\n\n";
}


return 0;
}



