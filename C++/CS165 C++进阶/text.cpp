#include <iostream>

using namespace std;

struct LinkedList {
	char value;
	LinkedList *prev;
	LinkedList *next;
};


void appendNode(int);
LinkedList* insertNode(LinkedList *, char, int);
void deleteNode(int);
void displayList();
bool delete_node(LinkedList *&, char);

int main() {

	LinkedList *head = nullptr;
	LinkedList *tail = nullptr;
	
	int number = 3;
	char temp = 'y';
	bool answer;

	for (int i = 0; i < 4; i++) {
		LinkedList *newnode = new LinkedList;
		LinkedList *newptr;
		cin >> newnode->value;
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

	insertNode(head, temp, number);

		while(head) {
			cout << head->value << endl;
			head = head->next;
		}

	system("pause");
	return 0;


}

LinkedList* insertNode(LinkedList *head, char letter, int index) {
	LinkedList *prev = head;
	LinkedList *ptr = new LinkedList;

	ptr->value = letter;

	if (index == 0) {
		ptr->next = head;   // 1
		head = ptr;   //  2
			return head;
	}

	for (int i = 1; i < index; i++)
		prev = prev->next;

	ptr->next = prev->next; // 3.
	prev->next = ptr;// 4.

		return head;
}


bool delete_node(LinkedList *& head, char letter) {
	LinkedList *ptr = head, *temp = nullptr;

	if (head == nullptr)
		return false;

	if (head->value == letter) {
		head = head->next;
		delete ptr;
		ptr = nullptr;
		return true;
	}

	while (ptr->next != nullptr && ptr->next->value != letter)
		ptr = ptr->next;

	if (ptr->next == nullptr)
		return false;

	ptr->next = temp->next;
	temp = ptr->next;


	delete temp;
	temp = nullptr;
	return true;
}