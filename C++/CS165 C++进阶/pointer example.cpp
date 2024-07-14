#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int x = 5, y = 6;
	int* ptr = &x;
	int arr[5] = { 10,20,30,40,50 };
	int *ptr1 = nullptr; // used to initialize pointer
	int *ptr2 = &arr[5 - 1];
	int *ptr3 = arr;

	cout << "the value of x is: " << x << endl;
	cout << "the value of x is: " << *ptr << endl; // * means to call the value in the address "ptr".
	cout << "the address of x is: " << &x << endl; // & means to show the address about the value.
	cout << "the address of x is: " << ptr << endl;
	cout << "?: " << &ptr << endl << endl;
	
	for (int i = 0; i < 5; i++) {
		cout << *ptr3 << endl;
		ptr3++; // after this line, the address about the array should be arr[5], arr[5] is no value inside.
	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		ptr3--; // after this line, the address about the array should be arr[4], arr[4] is 50.
		cout << *ptr3 << endl;
	}
	cout << endl;

	for (int i = 0; i < (5 / 2 + 1); i++) {
		cout << *ptr3 << endl;
		ptr3 += 2;
	}
	cout << endl;


	
	int val[3] = { 4,7,11 };
	// array is a point already, that's why when we use function to pass a array,
	// we don't need use &array to change the value into the main function
	cout << val << endl; // if we don't add the peremeter after array name, the array name similar to ptr ( reference the before code).
	cout << val[0] << endl;
	cout << *val << endl; // also same as *ptr
	cout << *(val + 1) << endl << endl;

	int vals[] = { 4,7,11 }, *valptr;
	valptr = vals;
	cout << *(valptr + 1) << endl;
	cout << *(valptr + 2) << endl; // change the address and cout it.
	cout << *valptr++ << endl; // only change the address, not change the value, so cout will be 4, but after cout the address will point to 7
	cout << *valptr << endl;
	cout << valptr-- << endl; // alsow change the address, after cout, the address well point to 4
	cout << *valptr << endl;
	cout << valptr += 2 << endl;
	cout << valptr–vals << endl;

	system("pause");

	return 0;
}

