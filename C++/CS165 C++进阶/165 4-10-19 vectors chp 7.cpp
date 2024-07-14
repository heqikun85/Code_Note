#include <iostream>
#include <vector>

using namespace std;


void build_vector(vector<int> &, const int);
void print_vector(const vector<int> &);
void destroy_vector(vector<int> &);
int get_num_of_elts();

void pop_front(vector<int> &);

int main()
{
	int num_of_elts;
	vector<int> vec;

	num_of_elts = get_num_of_elts();
	build_vector(vec, num_of_elts);
	
	print_vector(vec);
	cout << endl << endl;
	pop_front(vec);
	print_vector(vec);

	destroy_vector(vec);
	cout << endl << endl;
	pop_front(vec);
	print_vector(vec);
	
	if (vec.empty())
		cout << "Vector is empty\n";


	num_of_elts = get_num_of_elts();
	build_vector(vec, num_of_elts);
	print_vector(vec);
	vec.clear();
	print_vector(vec);

	if (vec.empty())
		cout << "Vector is empty\n";

	system("PAUSE");
	return 0;
}

int get_num_of_elts()
{
	int num_of_elts;

	do
	{
		cout << "How many elements do you want the vector to have (must be at least 1): ";
		cin >> num_of_elts;
	} while (num_of_elts < 1);

	return num_of_elts;

}

void build_vector(vector<int> &vec, const int size)
{
	int val;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number " << i + 1 << ": ";
		cin >> val;
		vec.push_back(val);
	}

}



void print_vector(const vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout <<vec[i] << " " << vec.at(i) << endl;

}

void destroy_vector(vector<int> &vec)
{
	while (!vec.empty())
		vec.pop_back();

}

void pop_front(vector<int> &vec)
{

	if (!vec.empty())
	{
		for (int i = 0; i < (vec.size() - 1); i++)
			vec.at(i) = vec.at(i + 1);

		vec.pop_back();
	}

}