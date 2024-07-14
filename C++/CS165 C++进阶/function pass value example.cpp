#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// Public of array quantity
const int Size = 5;

// Function prototypes
void getJudgeData(double *&, int);
void calcScore(double[], int);
double findLowest(double[], int);
double findHighest(double[], int);

int main()
{
	double score[Size];	// To hold the score.

	for(int i =0 ; i < Size ; i++){
        getJudgeData(score, i);
        }

    calcScore(score, Size);

	system("PAUSE");
    return 0;
}

void getJudgeData(double *&score){
    for(int i =0 ; i < Size ; i++){
            cout << "Enter a judge's scores: ";
            cin >> score[i];
            while (score[i]> 10.0 || score[i]<0.0){
                cout << "The score must be between 0.0 and 10.0\n"
                     << "Enter a judge's scores: ";
                cin >> score[i];
            }
    }
}

double findLowest(double score[], int Size){
    double temp = 0;
    for(int i =0 ; i < Size ; i++){
            if(temp < score[i]){
                temp = score[i];
            }
    }
    return temp;
}

double findHighest(double score[], int Size){
    double temp = 10;
    for(int i =0 ; i < Size ; i++){
            if(temp > score[i]){
                temp = score[i];
            }
    }
    return temp;
}

void calcScore(double score[], int Size){
    double sum = 0;
    for(int i =0 ; i < Size ; i++){
            sum += score[i];
}
    sum = (sum - findLowest(score,Size) - findHighest(score,Size))/3.0 ;
    cout << "After dropping the lowest and highest scores, the average score was " << fixed << setprecision(1)<< sum <<endl;

}
