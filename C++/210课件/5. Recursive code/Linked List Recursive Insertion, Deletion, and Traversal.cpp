// Recursive CPP program to recursively insert
// a node and recursively print the list.
#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};


void insert(Node* &head, int item)
{

if ((head == nullptr) || (item < head->data))
{
Node *temp = head;
head = new Node;
head->data = item;
head->next = temp;
}
else{
insert (head->next, item);
}


}

void traverse(Node* head)
{
if (head != nullptr)
{
cout << head->data << " ";

traverse(head->next);
}

}
void deleteItem (Node* &head, int item)
{
if (item == head->data)
{
Node * temp = head;
head = head->next;
delete temp;
}
else
deleteItem(head->next, item);
}

/// Driver code
int main()
{
Node* head = nullptr;
insert(head, 16);
insert(head, 8);
insert(head, 100);
insert(head, 12);
insert(head, 14);
traverse(head);
cout << endl << endl;
deleteItem(head, 8);
traverse(head);
cout << endl << endl;
deleteItem(head, 100);
traverse(head);
cout << endl << endl;
deleteItem(head, 14);
traverse(head);
cout << endl << endl;

}
