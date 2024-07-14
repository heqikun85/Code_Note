#include <iostream>
#include <vector>//use vector must have

using namespace std;

int main() {
	int Size;
	vector <int> array1{ 1,2,3,4,5,6,7,8,9 };// c++11 for initial very element to an array
	vector <double> array2(5, 1.5);//only can initial one value to element.

	array1.push_back(15);//add a value into the last store address, such if the array have 5 elements, it will be stored in 6.

	Size = array1.size();//get the size
	cout << Size << endl;

	for (int var : array1)//c++11 rules for array.
		cout << var << endl;

	for (double var : array2)
		cout << var << endl;

	vector <int> array3(array1);//c++11 rules for copy an array.
	for (int var : array3)
		cout << var << endl;

	array3.pop_back(); //only remove last element from vector

	for (int var : array3)
		cout << var << endl;

	array1.clear();//remove all contents of vector. remove, not initial.

	for (int var : array1)
		cout << var << endl;

	for (int var : array1)
		cout << var << endl;
	for (int var : array3)
		cout << var << endl;

	cout << array1.at(2) << endl; //Returns the value of the element at position i in the vector
	int max = 0;
	max = array2.capacity(); //Returns the maximum number of elements a vector can store without allocating more memory
	cout << max << endl;
	array1.reverse(); //Reverse the order of the elements in a vector
	for (int var : array1)
		cout << var;
	array2.resize(5, 0);
	for (double var : array2) //Resizes the vector so it contains nelements. If new elements are added, they are initialized to val.
		cout << var;
	array3.swap(array1); //Exchange the contents of two vectors.
	for (int var : array3)
		cout << var << endl;

	while (!array3.empty())
		array3.pop_back();

	while (array1.empty())
		array1.push_back(30);

	system("pause");
	return 0;

}

/*

void build_vector(vector<int> &, const int);
void print_vector(const vector<int> &);
void destroy_vector(vector<int> &);
int get_num_of_elts();
void pop_front(vector<int> &);

int main() {
	int num_of_elts;
	vector<int> vec;

	num_of_elts = get_num_of_elts();
	build_vector(vec, num_of_elts);
	print_vector(vec);
	vec.clear();
	print_vector(vec);

	if (vec.empty())
		cout << "vector is empty\n";
}

int get_num_of_elts() {
	int num_of_elts = 5;
	return num_of_elts;
}

// The vect is passed by reference and changes 
// made here reflect in main() 
void build_vector(vector<int> &vec, const int size) {
	int val;
	for (int i = 0; i < size; i++) {
		cout << "enter number" << i + 1 << ": ";
		cin >> val;
		vec.push_back(val);
	}
}

//The vect is passed by constant reference 
// and cannot be changed by this function. 
void print_vector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " " << vec.at(i) << endl;
}

void destroy_vector(vector<int> &vec) {
	while (!vec.empty())
		vec.pop_back();
}

void pop_front(vector<int> &vec) {
	for (int i = 0; i < (vec.size() - 1); i++)
		vec.at(i) = vec.at(i + 1);
	vec.pop_back();
}

*/
