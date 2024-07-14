#include <iostream>
#include <string>
using namespace std;

struct Student
{
	int ID;
	string name;
	double GPA;
	int units;

};

int main()
{
	const int size = 5;

	Student stuarr[size] = { {58723, "Bill", 3.75, 12},
							{ 47231, "John", 4.0},
							 { 98531, "Rebecca"}
	};


	for (int i = 0; i < size; i++)
	{
		cout << stuarr[i].ID << endl << stuarr[i].name << endl
			<< stuarr[i].GPA << endl << stuarr[i].units << endl;

    }

	cout << endl << endl;

	stuarr[0].name = "Steven";
	stuarr[1].units = 15;
	stuarr[2].GPA = 3.2;


	for (int i = 0; i < size; i++)
	{
		cout << stuarr[i].ID << endl << (*(stuarr+i)).name << endl
			<< stuarr[i].GPA << endl << (*(stuarr+i)).units << endl;
		
	}

	cout << endl << endl;


	system("PAUSE");
	return 0;


}