#include <iostream>
using namespace std;

int getMode(int *, int);
int *makeArray(int);

int main()
{
	const int SIZE = 9;

	int test[SIZE] = {1,2, 2,3, 3, 4, 5,6};

	int mode;

	mode = getMode(test, SIZE);

	if (mode == -1)
		cout << "The test set has no mode.\n";
	else
		cout << "\nThe mode of the test set is: "
		     << mode << endl;

    system("PAUSE");
	return 0;
}

int getMode(int *array, int size)
{
	int *frequencies = nullptr;
	int value = 0, temp = 0;

	frequencies = makeArray(size);

	for (int i = 0; i < size; i++){
		frequencies[i] = 0;
		for(int j = 0; j < size; j++){
                if(array[i] == array[j])
                frequencies[i]++;
		}
	}

	value = frequencies[0];
	for (int i = 1 ; i < size; i++){
        if (value < frequencies[i]){
            value = frequencies[i];
            temp = i;
            }
	}

	if (frequencies[temp] > 1) {
		delete [] frequencies;
		return array[temp];
	}

	else {
		delete[] frequencies;
		return -1;
	}

	}

int* makeArray(int size)
{
	int *arrptr;
	arrptr = new int[size];

	return arrptr;
}
