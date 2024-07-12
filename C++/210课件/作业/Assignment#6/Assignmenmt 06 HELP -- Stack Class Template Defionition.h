//Header File: linkedStack.h

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>


using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
Type info;
nodeType<Type> *link;
};

template <class Type>
class linkedStackType
{
public:

//Overload the assignment operator.
const linkedStackType<Type>& operator=
(const linkedStackType<Type>&);


//Function to determine whether the stack is empty.
//Postcondition: Returns true if the stack is empty;
// otherwise returns false.

bool isEmptyStack() const;


//Function to determine whether the stack is full.
//Postcondition: Returns false.

bool isFullStack() const;


//Function to initialize the stack to an empty state.
//Postcondition: The stack elements are removed;
// stackTop = nullptr;

void initializeStack();


//Function to add newItem to the stack.
//Precondition: The stack exists and is not full.
//Postcondition: The stack is changed and newItem
// is added to the top of the stack.

void push(const Type& newItem);

Type top();
//Function to return the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: If the stack is empty, the program
// terminates; otherwise, the top
// element of the stack is returned.

Type top() const;

//Function to remove the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: The stack is changed and the top
// element is removed from the stack.

void pop();

//Default constructor
//Postcondition: stackTop = nullptr;

linkedStackType();


//Copy constructor

linkedStackType(const linkedStackType<Type>& otherStack);


~linkedStackType();
//Destructor
//Postcondition: All the elements of the stack are
// removed from the stack.

private:
nodeType<Type> *stackTop; //pointer to the stack

void copyStack(const linkedStackType<Type>& otherStack);
//Function to make a copy of otherStack.
//Postcondition: A copy of otherStack is created and
// assigned to this stack.
};

template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = NULL;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return (stackTop == NULL);
}

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{
    return false; //stack never full
}

template <class Type>
void linkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp; //create an temp pointer
    while (stackTop != NULL)
    {
        temp = stackTop;  //set temp to point to the current node
        stackTop = stackTop->link;   //move the stackTop to next node.
        delete temp;
    }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>; //create a new node
   assert(newNode != NULL);
	  
   newNode->info = newItem;   //store newItem in the node
   newNode->link = stackTop;     //move the newNode before stackTop
   stackTop = newNode;
}

template<class Type>
Type linkedStackType<Type>::top()
{
	assert(stackTop != NULL);
		
   	return stackTop->info; //return the top element
}

template<class Type>
void linkedStackType<Type>::pop()
{
   nodeType<Type> *temp;       //pointer to deallocate memory

   if(stackTop != NULL)
   {
   		temp = stackTop;            //set temp to point to the top node
   		stackTop = stackTop->link;  //advance stackTop to the next node
   		delete temp;	            //delete the top node
   }
   else
		cout<<"It's empty"<<endl;
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL)
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;  //create the node

        stackTop->info = current->info;
        stackTop->link = NULL;
        last = stackTop;
        current = current->link;

        //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template<class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

template<class Type>
linkedStackType<Type>::~linkedStackType()
{
	initializeStack();
}

template<class Type>   //overloading the assignment operator
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack)
{
 	if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}

#endif
