
#include <iostream>
using namespace std;
class Box {
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
};

int main() {
   Box Box1;        // Declare Box1 of type Box
   Box Box2;        // Declare Box2 of type Box
   double volume = 0.0;     // Store the volume of a box here
 
   // box 1 specification
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;

   // box 2 specification
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;
   
   // volume of box 1
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}









class Student
{
private:
string name ;
int age;
public:
/// constructors
Student();
Student(string, int);
Student(string);
Student( int);
~Student();
///getters
string getNanme()const;
int getAge()const;
///setters
void setName(string);
void setAge(int);

};
Student:: ~Student()
{
cout <<" The object is now being destroyed... " << endl;
}
Student::Student()
{
name = "";
age = 0;
}
Student::Student(string s, int a)
{
name = s;
age = a;
}
Student::Student(string s)
{
name = s;
}
Student::Student( int a)
{
age = a;
}
///get
string Student::getNanme()const
{
return name;
}
///getter
int Student::getAge()const
{
return age;
}
///setter
void Student::setName(string s)
{
name = s;
}
void Student::setAge(int a)
{
age = a;
}
int main()
{
Student joe;
Student adam("Adam", 20);
Student mike(25);
Student lily("Lily");
cout << joe.getAge() << endl;
cout << adam.getAge() << endl;

return 0;
}



