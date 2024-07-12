#include<iostream>

using namespace std;

void Tower(int, char, char, char);

int main()
{
	int num;
	//let user enter number.
	cout << "Enter a number of disks to play. I'll give necessary moves.\n";
	cin >> num;

    //process the problem.
	Tower(num, 'A', 'B', 'C');

	system("pause");
	return 0;
}

//Tower of Hanoi function
void Tower(int num, char first, char second, char third)
{
	if (num == 1)
		cout << "Move a disk from post " << first << " to post " << second << endl;
	else {
		Tower(num-1, first, third, second);
		cout << "Move a disk from post " << first << " to post " << second << endl;
		Tower(num-1, third, second, first);
	}
}
