#include <iostream>
#include <string>

using namespace std;

const int Size1 = 5;

struct Employee
{
    string name;
    double hour[Size1];
    double wage;
    double paycheck;
};

void initialize(Employee[],int);
void compute(Employee &,double &);
void result(Employee,double);

int main()
{
    const int Size2 = 4;
    double totalhours[Size2] = {0};
    Employee staff[Size2];


    initialize (staff,Size2);

    for(int i = 0; i < Size2; i++){

        compute(staff[i],totalhours[i]);
        result(staff[i],totalhours[i]);
    }
    system("pause");
    return 0;
}

void initialize(Employee staff[], int Size)
{
    for (int i = 0; i < Size; i++){
        cout << "Please enter the employee's Last name. ";
        cin >> staff[i].name;
        cout << "Please enter the employee's hours of work by every single day. ";
        for (int j = 0; j < Size1; j++){
            cin >> staff[i].hour[j];
        }
        cout << "Please enter the employee's wage. ";
        cin >> staff[i].wage;
		cout << endl;
    }
}

void compute(Employee &staff, double &totalhours)
{


    for(int i = 0; i < Size1; i++)
            totalhours += staff.hour[i];
    if(totalhours > 40)
        staff.paycheck = 40 * staff.wage + (totalhours - 40)*staff.wage*1.5;

    else
        staff.paycheck = totalhours * staff.wage;
}

void result(Employee staff, double hours){
    cout << "Employee's name: " << staff.name << endl;
    cout << "Employee's total hours of work in one week: " << hours << endl;
    cout << "Employee's hourly rate: " << staff.wage << endl;
    cout << "Employee's pay for the week: " << staff.paycheck << endl <<endl;
}
