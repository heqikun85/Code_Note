#include<iostream>
using namespace std;


void print_Array(double[]);
void print_Pointer_Array(double *const);
void increase_Pointer_Array(double *const);


int main(int argc, char *argv[])
{

	double number[10] = { 0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };
	double *nPtr = number;

	cout << "Out from Array numbers: " << endl;
	print_Array(number);


	cout << "Output from Pointer nPntr:<array>" << endl;
	print_Pointer_Array(nPtr);


	nPtr = &number[0];

	cout << "Output from Pointer nPtr:<array[0]" << endl;
	print_Pointer_Array(nPtr);


	cout << "Out put from Pointer nPtr: <array> after the increment" << endl;
	increase_Pointer_Array(nPtr);


	cout << "Out from Array number: after the increment" << endl;
	print_Pointer_Array(nPtr);

}


void print_Array(double number[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << number[i] << endl;
	}
}


void print_Pointer_Array(double *nPtr)
{
	for (int a = 0; a < 10; a++)
	{
		cout << nPtr[a] << endl;
	}
}


void increase_Pointer_Array(double *nPtr)
{
	for (int b = 0; b < 10; b++)
	{
		nPtr[b] += 1.1;
		cout << nPtr[b] << endl;
	}
}
