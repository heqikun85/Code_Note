#include<cstdio>
#include<cstdlib>
#include<climits>
#include<iostream>

#define CAPACITY 100 // Queue max capacity

using namespace std;

int queuearray[CAPACITY];
int rearptr, frontptr;
unsigned int size = 0;

int enqueue(int);
int dequeue();
int getRear();
int getFront();
void display();
int isEmpty();
int isFull();
string prepMenu();

int main() {
    int option, data;

    int rear, front;

    rearptr = -1;
    frontptr = -1;
    string menu = prepMenu();
    cout << menu << endl;
    cin >> option;
    while (option != 7) {

        switch (option) {
        case 1:
            cout << "\nEnter data to enqueue (-99 to stop): ";
            cin >> data;
            while (data != -99) {
                /// Enqueue function returns 1 on success
                if (enqueue(data))
                    cout << "Element added to queue.";
                else
                    cout << "Queue is full." << endl;
                cout << "\nEnter data to enqueue (-99 to stop): ";
                cin >> data;
            }

            break;

        case 2:
            data = dequeue();

            /// on success dequeue returns element removed
            if (data == INT_MIN)
                cout << "\nQueue is empty." << endl;
            else
                cout << "\nData => " << data << endl;

            break;

        case 3:

            /// isEmpty() function returns 1 if queue is emtpy
            if (isEmpty())
                cout << "\nQueue is empty." << endl;
            else
                cout << "\nQueue size => " << size << endl;

            break;

        case 4:
            data = getRear();

            if (data == INT_MIN)
                cout << "\nQueue is empty." << endl;
            else
                cout << "\nRear => " << data << endl;

            break;

        case 5:

            data = getFront();

            if (data == INT_MIN)
                cout << "\nQueue is empty." << endl;
            else
                cout << "\nFront => " << data << endl;

            break;

        case 6:
            display();
            break;

        default:
            cout << "\nInvalid choice, please input number between (0-5).\n";
            break;
        }

        cout << "\n\n";
        cout << menu << endl;
        cin >> option;
    }
}

int enqueue(int data) {
    if(rearptr > CAPACITY) {
        frontptr=rearptr=-1;
        return 0;
    }
    queuearray[++rearptr]=data;
    size++;
    cout<<rearptr+1<<" ";
    return 1;
}

int dequeue() {
    if(frontptr==rearptr) {
        return INT_MIN;
    }
    int data = queuearray[++frontptr];
    size--;
    return data;
}

int getRear() {
    // Return INT_MIN if queue is empty otherwise rear.
    return (isEmpty()) ?
        INT_MIN :
        queuearray[rearptr];
}

int getFront() {
    // Return INT_MIN if queue is empty otherwise front.
    return (isEmpty()) ?
        INT_MIN :
        queuearray[frontptr+1];
}

int isEmpty() {
    return (frontptr==rearptr);
}

int isFull() {
    return (rearptr > CAPACITY);
}
string prepMenu() {

    string menu = "";

    menu += " \n-------------------------------------------------------------------\n";
    menu += "1.Enqueue 2.Dequeue 3.Size 4.Get Rear 5.Get Front 6.Display 7.Exit\n";
    menu += "----------------------------------------------------------------------\n";
    menu += "Select an option: ";
    return menu;
}
void display() {
    for (int t = frontptr+1; t != rearptr+1; t++)
        cout << queuearray[t] << " ";
    cout << endl << endl;
}
