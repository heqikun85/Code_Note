#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct NodeType;
typedef NodeType * NodePtr;
struct RecType
{
	long id;
	string fname;
	string lname;
	double balance;
};

struct NodeType
{
	long id;
	string fname;
	string lname;
	double balance;
	NodePtr flink;
	NodePtr blink;

};

class AccountList
{
private:
	NodePtr head;
	NodePtr cursor;
public:
	AccountList();
	void addAccountSorted(RecType);
	void updateAccount(RecType);
	void display(ofstream &);
};

AccountList::AccountList()
{
	head = new NodeType;
	head->id = 0;
	head->fname = "";
	head->lname = "";
	head->balance = 1;
	head->flink = head;
	head->blink = head;
	cursor = head;

}
void AccountList::addAccountSorted(RecType target)
{
	//Creat the new node and fill it in.
	NodePtr newPtr = new NodeType;
	newPtr->id = target.id;
	newPtr->fname = target.fname;
	newPtr->lname = target.lname;
	newPtr->balance = target.balance;
	newPtr->flink = NULL;
	newPtr->blink = NULL;
	//find the Node of point of insertion
	NodePtr cur, prev;

	//Using cur, locate the Point of insertion node.
	for (cur = head->flink; cur != head; cur = cur->flink)
	{
		if (target.id < cur->id)//found the Point of Insertion Node
			break;
	}

	//cur is now pointing to the Point of Insertion node.
	//Using cur, initialize prev that will point to the node just before the cur node.
	prev = cur->blink;

	//Now using cur and prev, insert the new node.
	//Create the two forward links
	newPtr->flink = prev->flink;
	prev->flink = newPtr;

	//Create the two back links
	newPtr->blink = cur->blink;
	cur->blink = newPtr;

}
void AccountList::updateAccount(RecType target)
{
	//move the cursor forward if at dummy node
	if (cursor == head)
		cursor = cursor->flink;
	//case: cursor is at the target node
	if (cursor->id == target.id)
	{
		//update the account
		cursor->balance += target.balance;

		//if the account became zero or negative
		//delete the node and move the cursor forward
		if (cursor->balance <= 0) {
			cursor->blink->flink = cursor->flink;
			cursor->flink->blink = cursor->blink;
			cursor = cursor->flink;
		}

	}

	//case: target node is in the forward direction
	else if (cursor->id < target.id)
	{
		//locate the target node or point of insertion node
		while (cursor != head)
		{
			if (cursor->id >= target.id)
				break;
			cursor = cursor->flink;
		}
		//case: found target node
		if (cursor->id == target.id)
		{
			//update the account
			cursor->balance += target.balance;

			//if the account became zero or negative
			//delete the node and move the cursor to before.
			if (cursor->balance <= 0) {
			cursor->flink->blink = cursor->blink;
			cursor->blink->flink = cursor->flink;
			cursor = cursor->flink;
		}

		}
		//case: target node does not exist
		else
		{
			//insert the node prior to cursor.
			NodePtr newPtr = new NodeType;
			newPtr->id = target.id;
			newPtr->fname = target.fname;
			newPtr->lname = target.lname;
			newPtr->balance = target.balance;
			newPtr->flink = NULL;
			newPtr->blink = NULL;
			newPtr->blink = cursor->blink;
			newPtr->flink = cursor;
			cursor->blink->flink = newPtr;
			cursor->flink->blink = newPtr;
		}
	}

	//case: target node is in the backward direction
	else
	{
		//locate target node or point of insertion node
		while (cursor != head)
		{
			if (cursor->id <= target.id)
				break;
			cursor = cursor->blink;
		}
		//case: target node found
		if (cursor->id == target.id)
		{
			//update the account
			cursor->balance += target.balance;

			//if the account became zero or negative
			//delete the node and move the cursor forward.
			if (cursor->balance <= 0) {
				cursor->blink->flink = cursor->flink;
				cursor->flink->blink = cursor->blink;
				cursor = cursor->flink;
			}

		}
		//case: target node does not exist
		else
		{
			NodePtr newPtr = new NodeType;
			newPtr->id = target.id;
			newPtr->fname = target.fname;
			newPtr->lname = target.lname;
			newPtr->balance = target.balance;
			newPtr->flink = NULL;
			newPtr->blink = NULL;
			//first move the cursor forward by one
			cursor = cursor->flink;
			//insert the node prior to where cursor.
			newPtr->blink = cursor->blink;
			newPtr->flink = cursor;
			cursor->blink->flink = newPtr;
			cursor->flink->blink = newPtr;
		}
	}
}

//write to log file
void AccountList::display(ofstream & lfout)
{
		for (NodePtr cur = head->flink; cur != head; cur = cur->flink)
			lfout << cur->id << " " << cur->fname << " " << " " << cur->lname << " " << cur->balance << endl;
}


int main()
{
	RecType data;
	AccountList account;
	ifstream infile;
	string file;
	ofstream lfout("F:\\class\\COMSC\\ASSIGNMENT#4\\log.txt");

	cout << "Enter the master file name: ";
	cin >> file;

	infile.open(file.c_str());
	if (!infile) {
		cout << "Unable to open the Master file";
	}
	else {
		// The loop will work until the file is end
		while(!infile.eof()) {
			infile >> data.id;
			infile >> data.fname;
			infile >> data.lname;
			infile >> data.balance;
			account.addAccountSorted(data);
		}
		lfout << "Write the master account information into the log file" << endl;
		account.display(lfout); // display the result
	}

	infile.close();

	cout << "\nEnter the transaction file name: ";
	cin >> file;

	infile.open(file.c_str());
	if (!infile) {
		cout << "Unable to open the transaction file";
	}
	else {
		while (!infile.eof()) {
			infile >> data.id;
			infile >> data.fname;
			infile >> data.lname;
			infile >> data.balance;
			account.updateAccount(data);
		}
		lfout << "\nUpdate the log file." << endl;
		account.display(lfout);
	}

	infile.close();
	lfout.close();

	lfout.open("F:\\class\\COMSC\\ASSIGNMENT#4\\new master.txt");
		account.display(lfout);
		lfout.close();

	system("pause");
}
 
