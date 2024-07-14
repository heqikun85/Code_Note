#include <iostream>
#include <cstdlib>
using namespace std;

void getData(char *, int);
void getResult(char *, char *, int *,int);
void showResult(int *);

int correct = 0;
int incorrect = 0;

int main(){
    const int Size = 20;
    char crtAns[Size]={'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B'};
    char sduAns[Size];
	int *worAns = new int [incorrect];

    getData(sduAns, Size);
    getResult(crtAns, sduAns, worAns, Size);
    showResult(worAns);

    system("Pause");
    return 0;
}

void getData(char *sduAns, int Size){

    cout << "Please enter the student's answers for each of the questions."
         << "\nPress Enter after typing each answer."
         << "\nPlease enter only an A,B,C,or D for each question." <<endl;

    for (int i=0; i < Size; i++){
        cout << "Question "<< i+1 << ": ";
        cin >> sduAns[i];
    }
    cout <<endl;
}

int getIncrt(int incorrect, char *crtAns, char *sduAns, int Size) {


	return incorrect;
}

void getResult(char *crtAns, char *sduAns, int *worAns,int Size){
     for (int i=0; i < Size; i++){
        if(crtAns[i] == sduAns[i])
            correct++;
		else {
			worAns[incorrect] = i + 1;
			incorrect++;
		}
	 }
}

void showResult(int *worAns){
    if(correct >= 15){
        cout <<"\nThe student passed the exam.\n"
             <<"\nCorrect Answers: " << correct
             <<"\nIncorrect Answers: " << incorrect
             <<"\n\nQuestion that were answered incorrectly: \n";
        for(int i=0; i < incorrect; i++)
            cout << worAns[i] << endl;
        cout <<"----------------------------------"<<endl;
    }
    else{
        cout <<"The student failed the exam.\n"
             <<"\nCorrect Answers: " << correct
             <<"\nIncorrect Answers: " << incorrect
             <<"\n\nQuestion that were answered incorrectly: \n";
        for(int i=0; i < incorrect; i++)
            cout << worAns[i] << endl;
        cout <<"----------------------------------"<<endl;
    }
}
