#include <bits/stdc++.h>

using namespace std;

class List {
protected:

    class Node {
    public:
        double data;
        Node *next;
        Node(double d, Node* p = nullptr)
        {   data = d;  next = p;  }
    };

    Node* head;

public:
    List()
    { head = nullptr; }

    ~List();

    void add(double number);

    void displayList() const;

    void remo(double n);

    void inser(double n);

};


void List::add(double number) {
    if (head == nullptr)
        head = new Node(number);
    else {
        Node *nodePtr = head;
        while (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;

        nodePtr->next = new Node(number);
    }
}

void List::displayList() const {
    Node *nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->data << "    ";
        nodePtr = nodePtr->next;
    }
}


List::~List() {
    Node *nodePtr = head;
    while (nodePtr != nullptr) {
        Node *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

void List::remo(double n)
{

    Node* pre = head;
    Node* curr = head->next;
    if (pre->data == n)
    {
        head = curr;
        delete pre;
        return;
    }

    while  (curr != nullptr)
    {
        if (curr->data == n)
            break;
        else
            {
                pre = curr;
                curr = curr->next;
            }
    }
    if (curr!= nullptr)
    {
        pre->next = curr->next;
        delete curr;
    }
}

void List::inser(double n)
{
    Node* h = new Node(n);
    Node* left = head;
    Node* right = head->next;
    if (left->data > n)
    {
        head = h;
        h->next = left;
        return;
    }

    while (right!= nullptr)
    {
        if (right->data >= n)
            break;
        else
            {
                left = right;
                right = right->next;
            }
    }
    if (right != nullptr)
    {
        left->next = h;
        h->next = right;
    }
    else
    {
        left->next = h;
    }
}


int main() {
    List list;
    list.add(2.5);
    list.add(7.9);
    list.add(12.6);
    list.displayList();

    double tar;
    cout << "Enter value";
    cin >> tar;

    list.remo(tar);
    list.inser(tar);

    list.displayList();



    return 0;
}
