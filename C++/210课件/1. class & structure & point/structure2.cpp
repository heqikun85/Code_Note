Review Structures 2
// identifying comments code block
// Programmer: First Last
// Programmer's ID: 1234567

// C++ libraries code block
#include <iostream>
#include <string>
using namespace std;

// C libraries code block
#include <cstdlib> // for atoi and atof

struct Student
{
  string name; // a data member
  int studentID; // a data member
  float gpa; // a data member
  void output( ) const; // a member function
  void input( ); // a member function
};

int main( )
{
  // identification output code block
  cout << "Programmer: First Last\n";
  cout << "Programmer's ID: 1234567\n";
  cout << "File: " << __FILE__ << endl;

  // create an array of student objects
  const int CAPACITY = 2;
  Student x[CAPACITY]; // an array of objects

  // enter data for each student
  for (int i = 0; i < CAPACITY; i++)
    x[i].input( );

  // output each student's data
  for (int i = 0; i < CAPACITY; i++)
    x[i].output( );
}

void Student::input( ) // a value-returning function that returns an object
{
  cout << "Enter a student's name ";
  getline(cin, name);

  char buf[100];
  cout << "Enter " << name <<"'s student ID: ";
  cin >> buf; studentID = atoi(buf);
  cin.ignore(1000, 10);

  cout << "Enter " << name << "'s GPA: ";
  cin >> buf; gpa = atof(buf);
  cin.ignore(1000, 10);
}

void Student::output( ) const
{
  cout.width(32);
  cout << name;
  cout.width(10);
  cout << studentID;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout.width(10);
  cout << gpa << endl;
}

