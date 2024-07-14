#include<iostream>
#include<string>
using namespace std;

void printstudent(const student &);
student Getstudent();

struct PersonInfo {
	string name, address, city;
};

struct student {
	int studentID;
	PersonInfo pData; // structure can contain another structure as a member:
	short yearInSchool;
	double gpa;
};

int main() {
	student s;
	s.pData.name = "Joanne";
	s.pData.city = "Tulsa";

	student s = Getstudent();
	student *ptr = nullptr;
	ptr = &s;
	(*ptr).studentID = 5; // both ok
	ptr->studentID = 5; //   both ok
}

void printstudent(const student &s) {
}

student Getstudent() {
}

/*
struct Person {
	string name, address, city;
};

struct student {
	int studentID;
	Person pDATA;
	short yearlnSchool;
	double gpa;
};
int main()
{
	student s;
	student* s2 = &s;

	s2->pDATA.name = "Bob";


	cout << s2->pDATA.name;
	system("pause");
	return 0;
}


*/