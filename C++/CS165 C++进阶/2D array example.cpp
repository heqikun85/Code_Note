#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
/*
int main(){
	int array[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int array2[5][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int sum = 0;
	int sum2 = 0;

	for (int curr_row = 0; curr_row < 4; curr_row += 3) {
		for (int curr_col = 0; curr_col < 4; curr_col++)
			sum += array[curr_row][curr_col];
	}

	for (int curr_row = 1; curr_row < 3; curr_row++) {
		for (int curr_col = 0; curr_col < 4; curr_col += 3)
			sum += array[curr_row][curr_col];
	}

	for (int curr_row = 0; curr_row < 5; curr_row += 4) {
		for (int curr_col = 0; curr_col < 5; curr_col++)
			sum2 += array2[curr_row][curr_col];
	}

	for (int curr_row = 1; curr_row < 4; curr_row++) {
		for (int curr_col = 0; curr_col < 5; curr_col += 4 )
			sum2 += array2[curr_row][curr_col];
	}

	cout << sum << endl;
	cout << sum2 << endl;
	system("pause");
	return 0;
}
*/
/*
int main() {
	int count = 0;
	string file_line;
	ifstream file_obj;
	file_obj.open("2.txt");
	while(getline(file_obj, file_line)){
		if((count%2)==1)
		cout << file_line;
		count++;
	}
	file_obj.close();
	system("pause");
	return 0;

}*/

int main(){
   cout << (71.626+71.299+72.236)/3;
}
