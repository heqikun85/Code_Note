#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 5;
	int x = 5, y = 6;
	//int* ptr = &x;
	int arr[SIZE] = { 10, 20, 30, 40, 50 };
	int *ptr = nullptr; //used to initialize pointer
	int* ptr2 = &arr[SIZE - 1];	
	int* ptr3 = arr;

	for (int i = 0; i < SIZE; i++)
	{
		cout << *ptr3<<endl;
		ptr3++;
	}

	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		ptr3--;
		cout << *ptr3 << endl;
	}

	cout << endl;
	
	ptr3 = arr;

	for (int i = 0; i < (SIZE/2+1); i++)
	{
		cout << *ptr3 << endl;
		ptr3 += 2;
	}

	ptr = arr;

	cout << endl;
	cout << ptr2 - arr + 1;

	cout << endl << endl << endl;

	for (int i = 0; i < SIZE; i++)
		cout << *arr + i << endl; //incorrect

	cout << endl;

	for (int i = 0; i < SIZE; i++)
		cout << *(arr + i) << endl; //correct
	
	cout << endl;


	for (int i = 0; i < SIZE; i++)
		cout << *(ptr2 - i) << endl;

	cout << endl;

	ptr = &arr[0]; //or ptr = arr;

	for (int i = 0; i < SIZE; i++)
		cout << ptr[i] << endl;

	cout << endl;


	ptr = &x;


	cout << "the value of x is: " << x << endl;
	cout << "the value of x is: " << *ptr << endl;
	cout << "the address of x is: " << &x << endl;
	cout << "the address of x is: " << ptr << endl;
	cout << "?: " << &ptr << endl << endl;

	*ptr = 99;

	cout << "the value of x is: " << x << endl;
	cout << "the value of x is: " << *ptr << endl;
	cout << "the address of x is: " << &x << endl;
	cout << "the address of x is: " << ptr << endl;
	cout << "?: " << &ptr << endl << endl;

	ptr = &y;

	cout << "the value of y is: " << y << endl;
	cout << "the value of y is: " << *ptr << endl;
	cout << "the address of y is: " << &y << endl;
	cout << "the address of y is: " << ptr << endl;
	cout << "?: " << &ptr << endl << endl;

	*ptr = 165;

	cout << "the value of y is: " << y << endl;
	cout << "the value of y is: " << *ptr << endl;
	cout << "the address of y is: " << &y << endl;
	cout << "the address of y is: " << ptr << endl;
	cout << "?: " << &ptr << endl << endl;

	system("PAUSE");
	return 0;
}