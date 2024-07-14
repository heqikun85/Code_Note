#include <iostream>

using namespace std;

struct LinkedList {
	int value;
	LinkedList *prev;
	LinkedList *next;
};

void appendNode(LinkedList *&, int);
void insertNode(LinkedList *);
void deleteNode(LinkedList *);
void searchNode(LinkedList *, int);
void displayList(LinkedList *);

int main() {
	LinkedList *head = nullptr;
	LinkedList *tail = nullptr;
	int Size = 0;
	
	do {
		cout << "Enter the number of initial nodes (must be at least 1):";
		cin >> Size;
	} while (Size < 1);

	cout << "\n";

	for (int i = 0; i < Size; i++) {
		
		appendNode(head, Size);

	}

	cout << "\nHere are the initial values in the linked list:" << endl;

	displayList(head);

	insertNode(head);

	cout << "\nHere is the updated the linked list:" << endl;

	displayList(head);

	deleteNode(head);

	cout << "\nHere is the updated the linked list:" << endl;

	displayList(head);

	searchNode(head, Size);

	system("pause");
	return 0;

	
}

void appendNode(LinkedList *&head, int value) {
	LinkedList *newnode = new LinkedList;
	LinkedList *newptr;
	int number;

	cout << "Enter a number:";
	cin >> number;

	newnode->value = number;
	newnode->next = nullptr;

	if (!head)
		head = newnode;

	else {
		newptr = head;

		while (newptr->next)
			newptr = newptr->next;

		newptr->next = newnode;

	}
}

void insertNode(LinkedList *head) {
	LinkedList *p = new LinkedList;
	LinkedList *temp = head;
	LinkedList *n = nullptr;

	int number = 0;
	int count = 0;

	cout << "\nEnter a number for a new node to insert to the linked list: ";
	cin >> number;

	p->value = number;
	p->next = nullptr;

	while (temp->value < number) {
		n = temp;
		temp = temp->next;
	}
	p->next = temp;
	n->next = p;
}


void deleteNode(LinkedList *head) {
	LinkedList *temp = head;
	LinkedList *n = nullptr;
	int number = 0;

	cout << "\nEnter the number of node that you want to delete from the linked list: ";
	cin >> number;

	while (temp->value != number) {
		n = temp;
		temp = temp->next;
	}

	n->next = temp->next;

}


void displayList(LinkedList *head) {
	LinkedList *N = head;

	while (N) {
		cout << N->value << endl;
		N = N->next;
	}

}

void searchNode(LinkedList *head, int Size) {
	LinkedList *temp = head;
	int value = 0;
	int count = 1;

	cout << "\nEnter the number that you want to search for in the list: ";
	cin >> value;


	while (temp != nullptr && temp->value != value) {
		temp = temp->next;
		count++;
	}

	if (temp)
		cout << "\nNumber found at index " << count - 1 << " in the linked list." << endl;

	else
		cout << "\nNumber can't be found in the linked list." << endl;
}