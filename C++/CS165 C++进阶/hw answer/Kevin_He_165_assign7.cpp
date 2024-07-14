#include<iostream>
#include<cstdlib>
using namespace std;

// Global constants
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN  = 1;  // The value of the smallest number
const int MAX  = 9;  // The value of the largest number

// Function prototypes
void showResult(int[][COLS]);
void showArray(int[][COLS]);
bool isMagicSquare(int[][COLS]);
bool checkRange(int[][COLS]);
bool checkUnique(int[][COLS]);
bool checkRowSum(int[][COLS]);
bool checkColSum(int[][COLS]);
bool checkDiagSum(int[][COLS]);

int main()
{
   // Create a magic two-dimensional array.
   int magicArray[ROWS][COLS] = { {4, 9, 2},
                                  {3, 5, 7},
                                  {8, 1, 6} };

   // Create a normal two-dimensional array.
   int normalArray[ROWS][COLS] = { {10, 2, 3},
                                   {4, 15, 6},
                                   {7, 8, -8} };

  // NOTE: Feel free to create additional 2D arrays to test

   // Display the normal array.
   showArray(normalArray);

   // Test the normal array and display the result.
   showResult(normalArray);

   // Display the magic array.
   showArray(magicArray);

   // Test the magic array and display the result.
   showResult(magicArray);

   system("PAUSE");
   return 0;
}

// ********************************************************
// The showResult function accepts a two-dimensional int  *
// array as an argument, tests to determine if it is a    *
// Lo Shu Magic Square and displays the result.           *
// ********************************************************
void showResult(int values[][COLS])
{
   // Determine if the array is a Lo Shu Magic Square.
   if (isMagicSquare(values))
   {
      // If so, display a message indicating that the
      // array is a magic square.
      cout << "This is a Lo Shu magic square.\n\n";
   }
   else
   {
      // If not, display a message indicating that the
      // array is not a magic square.
      cout << "This is not a Lo Shu magic square.\n\n";
   }
}

// ********************************************************
// The showArray function accepts a two-dimensional int   *
// array as an argument and displays its contents.        *
// ********************************************************
void showArray(int values[][COLS])
{
   // Step through all the values in the array.
   for (int row = 0; row < ROWS; row++)
   {
      for (int col = 0; col < COLS; col++)
      {
         // Display the values in this row.
         cout << values[row][col] << " ";
      }

      // End the line, so we can display the next row.
      cout << endl;
   }
}

// ********************************************************
// The isMagicSquare function accepts a two-dimensional   *
// int array as an argument, and returns true if the      *
// array meets all the requirements of a magic square.    *
// Otherwise, it returns false.                           *
// ********************************************************
bool isMagicSquare(int values[][COLS])
{
	if (checkRange(values) && checkUnique(values) && checkRowSum(values) && checkColSum(values) && checkDiagSum(values))
		return true;
	else 
		return false;
}

// ********************************************************
// The checkRange function accepts a two-dimensional int  *
// array as an argument, and returns true if the values   *
// are within the specified range (1- 9). Otherwise, it returns  *
// false.                                                 *
// ********************************************************
bool checkRange(int values[][COLS])
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (values[i][j]<MIN || values[i][j]>MAX)
				return false;
			else
				return true;
		}
   }
}

// ********************************************************
// The checkUnique function accepts a two-dimensional int *
// array as an argument, and returns true if the values   *
// in the array are unique. Otherwise, it returns false (if there are duplicates).  *
// ********************************************************
bool checkUnique(int values[][COLS])
{
	int temp = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			for (int x = 0; x < ROWS; x++) {
				for (int y = 0; y < COLS; y++) {
					if (values[i][j] == values[x][y]) {
						temp++;
					}
				}
			}
		}
	}
	if (temp > 9)
		return false;
	else
		return true;
}

// ********************************************************
// The checkRowSum function accepts a two-dimensional     *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's rows are equal.   *
// Otherwise, it returns false.                           *
// ********************************************************
bool checkRowSum(int values[][COLS])
{
	int sum[ROWS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			sum[i] += values[i][j];
		}
	}
	if (sum[0] != sum[1] || sum[0] != sum[2] || sum[1] != sum[2])
		return false;
	else
		return true;
}

// ********************************************************
// The checkColSum function accepts a two-dimensional     *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's columns are       *
// equal. Otherwise, it returns false.                    *
// ********************************************************
bool checkColSum(int values[][COLS])
{
	int sum[ROWS];
	for (int i = 0; i < COLS; i++) {
		for (int j = 0; j < ROWS; j++) {
			sum[i] += values[j][i];
		}
	}
	if (sum[0] != sum[1] || sum[0] != sum[2] || sum[1] != sum[2])
		return false;
	else
		return true;
}

// ********************************************************
// The checkDiagSum function accepts a two-dimensional    *
// int array as an argument, and returns true if the sum  *
// of the values in each of the array's diagonals are     *
// equal. Otherwise, it returns false.                    *
// ********************************************************
bool checkDiagSum(int values[][COLS])
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0,j=0; i < ROWS; i++,j++) {
		sum1 +=values[i][j];
	}
	for (int i = ROWS-1,j = 0; i > 0,j < COLS; i--,j++) {
		sum2 +=values[i][j];
	}

	if (sum1!=sum2)
		return false;
	else
		return true;
}
