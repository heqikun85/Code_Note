// Identification comments code block
// Programmer: First Last
// Programmer's ID: 1234567
// C++ libraries code block
#include <iostream>
#include <string>
using namespace std;
// C libraries code block
#include <cstdlib> /// for atoi and atof
struct Student
{
  string name;
  int studentID;
  float gpa;
};
Student input( );
void output(const Student&);
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
    x[i] = input( );
  // output each student's data
  for (int i = 0; i < CAPACITY; i++)
    output(x[i]);
}
Student input( ) // a value-returning function that returns an object
{
  Student result;
  cout << "Enter a student's name ";
  getline(cin, result.name);
  char buf[100];
  cout << "Enter " << result.name <<"'s student ID: ";
  cin >> buf; result.studentID = atoi(buf);
  cin.ignore(1000, 10);
  cout << "Enter " << result.name << "'s GPA: ";
  cin >> buf; result.gpa = atof(buf);
  cin.ignore(1000, 10);
  return result;
}
void output(const Student& s) // a void function
{
  cout.width(32);
  cout << s.name;
  cout.width(10);
  cout << s.studentID;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout.width(10);
  cout << s.gpa << endl;
}
What Should you notice from the above code

the struct declaration with its "attributes" (or "fields" or "data members" or "properties"),
the use of the "dot operator" (or "member of") to access attributes of the objects,
the static array declaration with its two objects,
the for-loops to traverse the arrays, reusing "i" as their index,
the value-returning function that returns a Student object,
the void function with a read-only reference parameter,
the user "prompts" with cout,
the console output formatting with width and precision specified, and the use of ios::fixed,
the console input for name, using getline (allowing for first and last name),
the console input for numbers, using the "string buffer" method with buf, atoi, and atof,
the use of cin.ignore(1000, 10); because the program has both cin>> and getline(cin in it,
the function prototype placement, and unnamed parameters,
the code blocks for C++ and C library includes and the placement of using namespace std;,
the code alignment and 2-space indenting, and
the programmer identification code blocks with comments and cout statements.
And here are some formatting specifics you should know:

cout.setf(ios::fixed) says to interpret cout.precision as #of digits after the decimal, and not as the #of "significant digits",
cout.precision says how many significant digits to show for floating point numbers or how many decimal digits depending on whether ios::fixed is set.
To unset a setting, it's cout.unsetf(ios::fixed).
cout.width says how many spaces to allocate to the very next output value only, right justified.
