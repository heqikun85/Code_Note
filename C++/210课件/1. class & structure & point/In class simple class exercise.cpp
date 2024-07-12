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
