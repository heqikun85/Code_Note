// Recursive CPP program to recursively insert
// a node and recursively print the list.
#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
class RecList
{
private:
Node * head;
void privateInsert(Node* &head, int item);
void privateTraverse(Node* head);
void privateDeleteItem (Node* &head, int item);
public:
void insertItem (int item);
void deleteItem (int item);
void traverse();
RecList () { head = nullptr;}
~RecList();

};
///public functions implementation
///*********************************
void RecList::insertItem (int item)
{
RecList::privateInsert(head, item);
}
void RecList::deleteItem (int item)
{
privateDeleteItem(head, item);
}
void RecList::traverse( )
{
privateTraverse(head);
}
RecList:: ~RecList()
{
Node *temp;

if(head != nullptr)
{
temp = head;

/// Scan list and free all nodes
while(head != nullptr)
{
temp = head;
head = head->next;
delete temp;
}
}

}
/// private functions implementation
///*******************************************************
void RecList::privateInsert(Node* &head, int item)
{

if ((head == nullptr) || (item < head->data))
{
Node *temp = head;
head = new Node;
head->data = item;
head->next = temp;
}
else
{

privateInsert (head->next, item);
}
}

void RecList::privateTraverse(Node* head)
{
if (head != nullptr)
{
cout << head->data << " ";
privateTraverse(head->next);
}

}
void RecList::privateDeleteItem (Node* &head, int item)
{
if (item == head->data)
{
Node * temp = head;
head = head->next;
delete temp;
}
else
privateDeleteItem(head->next, item);
}

/// Driver code
int main()
{
RecList myList;
myList.insertItem( 16);
myList.insertItem( 8);
myList.insertItem( 100);
myList.insertItem( 12);
myList.insertItem( 14);
myList.traverse();
cout << endl << endl;
myList.deleteItem( 8);
myList.traverse();
cout << endl << endl;
myList.deleteItem( 100);
myList.traverse();
cout << endl << endl;
myList.deleteItem( 14);
myList.traverse();
cout << endl << endl;

}
