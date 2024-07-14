#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Function prototypes
void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

int main()
{
	double score1;	// To hold the 1st score.
	double score2;	// To hold the 2nd score.
	double score3;	// To hold the 3rd score.
	double score4;	// To hold the 4th score.
	double score5;	// To hold the 5th score.

	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	calcScore(score1,score2,score3,score4,score5);

	system("PAUSE");
    return 0;
}

void getJudgeData(double &score){
    cout << "Enter a judge's scores: ";
    cin >> score;
    while (score> 10.0 || score<0.0){
        cout << "The score must be between 0.0 and 10.0\n"
             << "Enter a judge's scores: ";
        cin >> score;
        }
}

double findLowest(double score1,double score2,double score3,double score4,double score5){
    double temp = 0;
    if(score1 > score2 && score1 > score3 && score1 > score4 && score1 > score5)
        temp = score1;
    else if (score2 > score1 && score2 > score3 && score2 > score4 && score2 > score5)
        temp = score2;
    else if (score3 > score1 && score3 > score2 && score3 > score4 && score3 > score5)
        temp = score3;
    else if (score4 > score1 && score4 > score3 && score4 > score2 && score2 > score5)
        temp = score4;
    else
        temp = score5;
    return temp;
}

double findHighest(double score1,double score2,double score3,double score4,double score5){
    double temp = 0;
    if(score1 < score2 && score1 < score3 && score1 < score4 && score1 < score5)
        temp = score1;
    else if (score2 < score1 && score2 < score3 && score2 < score4 && score2 < score5)
        temp = score2;
    else if (score3 < score1 && score3 < score2 && score3 < score4 && score3 < score5)
        temp = score3;
    else if (score4 < score1 && score4 < score3 && score4 < score2 && score2 < score5)
        temp = score4;
    else
        temp = score5;
    return temp;
}

void calcScore(double score1,double score2,double score3,double score4,double score5){
    double sum = 0;
    sum = score1+score2+score3+score4+score5;
    sum = sum - findHighest(score1,score2,score3,score4,score5);
    sum = sum - findLowest(score1,score2,score3,score4,score5);
    sum = sum/3.0;
    cout << "\nAfter dropping the lowest and highest scores, the average score was " << fixed << setprecision(1)<< sum <<"\n"<<endl;
}
// IMPLEMENT THE FOUR FUNCTIONS STARTING HERE
