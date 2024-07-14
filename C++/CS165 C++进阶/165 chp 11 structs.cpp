#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string name;
	string address;
	string city;

};

struct Student
{
	Person per;
	char letter_grade;
	double test_score;

};

void show_person(const Person &p);
void show_person2(const Person * const p);
void show_student(const Student &s);

Person get_person();
Student get_student();

Person* create_person_array(int);
Student* create_student_array(int);



int main()
{

	int size;
	Student *ptr = new Student[2];

	Student* stu_ptr= nullptr;
	Person* per_ptr = nullptr;

	Person PER;
	Student STU;

	PER.name = "Wayne";
	PER.city = "Gotham";
	STU.per = PER;

	cout << STU.per.name << endl;

	PER.name = "Null";

	cout << STU.per.name << endl;



	cout << &PER << endl;
	cout << &PER.name << endl;
	cout << &PER.address << endl;
	cout << &PER.city << endl;



	(*ptr).test_score = 85;
	(*ptr).letter_grade = 'B';
	(*ptr).per.name = "Adam";

	ptr->per.name = "Bob";
	ptr->test_score = 97;
	ptr->letter_grade = 'A';
	

	cout << ptr->per.name << endl;
	cout << ptr->test_score << endl;
	cout << ptr->letter_grade << endl;

	Student stuarr[2];

	stuarr[0].per.name = "Peter parker";
	stuarr[0].per.city = "New York";
	stuarr[0].per.address = "321 Golf Club rd";

	stuarr[0].letter_grade = 'A';
	stuarr[0].test_score = 98;

	show_student(stuarr[0]); // call show_student

	Person perarr[2];

	perarr[0].name = "Bruce Wayne";
	perarr[0].city = "Gotham";
	perarr[0].address = "987 Wayne Manor dr";


	show_person(perarr[0]); // call show_person
	show_person2(perarr); // call show_person


	//stuarr[1] = get_student();
	//cin.ignore();
	//perarr[1] = get_person();

	//show_student(stuarr[1]);
	//show_person(perarr[1]);


	cout << "Enter the number of elements: ";
	cin >> size;
	cin.ignore();

	per_ptr = create_person_array(size);

	stu_ptr = create_student_array(size);


	cout << "------------------\n\n";

	for (int i = 0; i < size; i++)
		*(per_ptr + i) = get_person();


	for (int i = 0; i < size; i++)
	{
		*(stu_ptr + i) = get_student();
		cin.ignore();
	}

	for (int i = 0; i < size; i++)
		show_person(*(per_ptr+i));


	for (int i = 0; i < size; i++)
		show_student(*(stu_ptr + i));


	//create a student structure instance
	
	/* const int SIZE = 5;
	Student stuarr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter name: ";
		getline(cin, stuarr[i].name);

		cout << "Enter letter grade: ";
		cin.get(stuarr[i].letter_grade);

		cout << "Enter test score: ";
		cin >> stuarr[i].test_score;

		cin.ignore();

	}


	for (int i = 0; i < SIZE; i++)
	{
		cout << "Name: " << stuarr[i].name << endl;
		cout << "Letter grade: " << stuarr[i].letter_grade << endl;
		cout << "Test score: " << stuarr[i].test_score << endl << endl;
	}
		
	Student stu1, stu2;

	Student stu3 = { "Peter Parker", 'B', 82 };

	stu1.name = "Bruce Wayne";
	stu1.letter_grade = 'A';
	stu1.test_score = 97.0;

	cout << stu1.name << endl;
	cout << stu1.letter_grade << endl;
	cout << stu1.test_score << endl << endl;


	cout << "Enter name: ";
	getline(cin, stu2.name);

	cout << "Enter letter grade: ";
	cin.get(stu2.letter_grade);

	cout << "Enter test score: ";
	cin >> stu2.test_score;

	cout << endl << endl;


	cout << stu2.name << endl;
	cout << stu2.letter_grade << endl;
	cout << stu2.test_score << endl << endl;


	cout << endl << endl;


	cout << stu3.name << endl;
	cout << stu3.letter_grade << endl;
	cout << stu3.test_score << endl << endl; */

	system("PAUSE");
	return 0;
}


void show_person(const Person &p)
{

	cout << p.name << endl;
	cout << p.city << endl;
	cout << p.address << endl << endl;

}

void show_person2(const Person * const p)
{
	cout << p->name << endl;
	cout << p->city << endl;
	cout << p->address << endl << endl;

}

void show_student(const Student &s)
{

	cout << s.per.name << endl;
	cout << s.per.city << endl;
	cout << s.per.address << endl;
	cout << s.letter_grade << endl;
	cout << s.test_score << endl << endl;

}


Person get_person()
{
	Person p; //local person object
	          // will be destroyed once get_person returns

	cout << "Enter name: ";
	getline(cin, p.name);

	cout << "Enter city: ";
	getline(cin, p.city);

	cout << "Enter address: ";
	getline(cin, p.address);

	


	return p;

}


Student get_student()
{
	Student s; //local student object
			  // will be destroyed once get_student returns

	cout << "Enter name: ";
	getline(cin, s.per.name);

	cout << "Enter city: ";
	getline(cin, s.per.city);

	cout << "Enter address: ";
	getline(cin, s.per.address);

	
	cout << "Enter letter grade: ";
	cin.get(s.letter_grade);

	cout << "Enter test score: ";
	cin >> s.test_score;

	return s;
}


Person* create_person_array(int size)
{

	return new Person[size];


}


Student* create_student_array(int size)
{

	return new Student[size];


}