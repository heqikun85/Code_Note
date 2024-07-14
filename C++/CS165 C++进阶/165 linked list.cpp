#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	int studentID;
	double test_score;
	char letter_grade;

	// In order to be able to support a linked list, each Student node (object)
	// needs to be able to point to another Student node (object). To do this,
	// The Student structure needs to have a pointer of type Student* as a member variable.
	// This way, each Student node (object) has a pointer that can point to another Student node (object).

	// It is ONLY through these pointers that the Student nodes (objects) in the linked list are connected. 
	//Remember that unlike an array, the nodes in a linked list are NOT stored together in memory. So the only way
	// to move throug the list is by using the next pointers.

	Student* next;
};


int main()
{

	Student* head = nullptr;
	Student* ptr = nullptr;
	Student* ptr2 = nullptr;
	Student* new_node = nullptr;
	int index;

	ptr = new Student;  //create first node in linked list
	ptr->name = "John";
	ptr->studentID = 47823;
	ptr->test_score = 92;
	ptr->letter_grade = 'A';

	head = ptr; // The first node that we create is the head of the linked list, so set the head pointer
	            // to point at this node.

	ptr = new Student; //create second node in linked list 
	ptr->name = "Sarah";
	ptr->studentID = 92436;
	ptr->test_score = 87;
	ptr->letter_grade = 'B';

	// connects first node to second node. This works because head is pointing at the first node, and ptr
	// is pointing at the second node.
	head->next = ptr;

	ptr = new Student; //create third node in linked list
	ptr->name = "Matt";
	ptr->studentID = 34826;
	ptr->test_score = 75;
	ptr->letter_grade = 'C';

	// connects second node to third node
	// note that we have to use next TWO times here, because head is still pointing at the first node,
	// but the goal is to connect the second node to the third node.
	head->next->next = ptr;


	ptr = new Student; //create fourth node in linked list
	ptr->name = "Amanda";
	ptr->studentID = 97523;
	ptr->test_score = 94;
	ptr->letter_grade = 'A';

	// connects third node to fourth node
	// note that we have to use next THREE times here, because head is still pointing at the first node,
	// but the goal is to connect the third node to the fourth node.
	head->next->next->next = ptr;

	//set the last node's next pointer to point at nullptr
	ptr->next = nullptr;

	// traversal algorithm

	// start by pointing ptr at the first node
	ptr = head;

	cout << "Printing linked list BEFORE inserting new node\n\n";

	// Remember that the last node's next pointer points at nullptr, so the loop keeps going until
	// ptr is equal to nullptr.
	while (ptr != nullptr)
	{
		//print out the information for each student (name, ID, etc.)
		cout << "Name: " << ptr->name << endl;
		cout << "Student ID: " << ptr->studentID << endl;
		cout << "Test score: " << ptr->test_score << endl;
		cout << "Letter grade: " << ptr->letter_grade << endl << endl;

		//this moves the ptr pointer up one node in the list. For example, if ptr is initially pointing 
		// at the first node in the list, after doing this statement it will now point at the second
		// node in the list. Or if ptr is pointing at the last node, after doing this statement
		//it will point at nullptr.

		ptr = ptr->next;
	}


	//insertion algorithm

	// new node to be inserted into existing linked list
	new_node = new Student;
	new_node->name = "Steven";
	new_node->studentID = 96427;
	new_node->test_score = 82;
	new_node->letter_grade = 'B';

	ptr = head; // We need to set ptr to point at the head of the list before starting the insertion algorithm

	// we are using the index variable similar to how indexes are used for an array. For example, 
	// index 0 corresponds to the first node in the linked list; index 1 corresponds to the second node in the
	//linked list, and so on. So if index=2, it means that we want the new node to be inserted at index 2 in the 
	// linked list, meaning it will be the third node (since the first node is at index 0).

	index = 2; //you should run the program several times with different values for index (0, 1, 2, etc.) to test several different cases

	cout << "\n\nThe new node with name " << new_node->name << " is being inserted at index " << index << " in the linked list\n\n";

	//for the insertion algorithm it's helpful to handle the case where we want the new node to be first node 
	// in the list separately from all other cases, because in this case we have to change the head pointer.
	// There are two cases in which this happens: if index is less than or equal to 0 or if head is equal to nullptr.
	// Remember that if index<=0 it means that we want to insert the new node at the beginning of the list.
	// Or if head=nullptr, it means the list is currently empty, which means the new node will be inserted
	// to the beginning of the list and will be the only node in the linked list.

	// NOTE: index<=0 is being used here rather than index==0 to account for negative values for index.
	// If index has a negative value (-1, -2, etc.), it will be treated as if it were 0, meaning the new node
	//will still be inserted at the beginning of the linked list.

	if (index <= 0 || head == nullptr)
	{

		//first step: connect the new node to the OLD first node by setting the new node's
		//next poitner to point at head. Note that if the list was empty at this point, then
		// the new node's next pointer will be pointing at nullptr.

		// second step: the new node is now the head of the list, so set the head pointer to point at it.

		new_node->next = head;
		head = new_node;

	}

	// this else block is for all of the other cases, where we are inserting somewhere into the middle of the linked list
	// or to the end of the linked list.
	else
	{

		// the goal of this for loop is that when the loop finishes, the ptr pointer will be pointing at the node
		// BEFORE the node where we want to insert the new node. For example, suppose we have the following 
		//linked list, where each node is storing a letter ('A', 'B', 'C', etc.):

		// A->B-C->D->E
		// And the goal is to insert the new node 'X' into index 2 (making it the third node)
		//This means when the loop finishes, we need the ptr pointer to be pointing at the 'B' node (at index 1)
		// This will set us up to be able to insert the new node into the linked list

		//The number of loop iterations needed to do this is one less than the value of index
		for (int i = 0; i < (index - 1); i++)
		{
			//In case the user enters a value for index that is larger than the number of nodes
			// (e.g., index=100 but there are only five nodes) this if statement will ensure
			// that ptr still points at the correct node (the node before the node where we want to
			//insert the new node) when the loop finishes.
			
			if(ptr->next != nullptr)
			    ptr = ptr->next;

		}


		// Continuing the example from above, the linked list is A->B-C->D->E
		// and we want to insert the new node X into index 2, which is where the 'C' node currently is.
		// When the loop finishes, ptr will be pointing at the 'B' node (at index 1).

		// First step: we need to connect the new node (X)'s next pointer to the C node. Since ptr is pointing at B
		//rather than C, the statement new_node->next = ptr->next will connect the new node (X) to node C.

		// Second step: we need to connect node B to the new node (X). Since ptr is pointing at B, 
		// the statement ptr->next = new_node will connect node B to the new node (X).

		// So now the linked list is A->B->X->C->D->E
		// Where the X node has been correctly inserted into index 2 in the linked list
		// And the C, D, and E nodes have all moved down one position in the linked list.

		new_node->next = ptr->next;
		ptr->next = new_node;


	}


	// traversal algorithm (again)

	cout << "----------------------------\n\n";

	cout << "Printing linked list AFTER inserting new node\n\n";

	// start by pointing ptr at the head node (first node)
	ptr = head;

	while (ptr != nullptr)
	{
		cout << "Name: " << ptr->name << endl;
		cout << "Student ID: " << ptr->studentID << endl;
		cout << "Test score: " << ptr->test_score << endl;
		cout << "Letter grade: " << ptr->letter_grade << endl << endl;

		ptr = ptr->next;
	}


system("PAUSE");
return 0;

}