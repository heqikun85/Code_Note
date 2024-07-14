#include <iostream>
#include <string>

using namespace std;

int main(){

    const int Size = 3;
    string rName[Size];
    double rTime[Size];
    int x = 0;
    string first,second,third;

    cout <<"Enter the names of three runners and their finishing times.\n";
    cout <<"I will tell you who came in the first, second, and third.\n";

    for (int i=0 ; i<Size ; i++){
        cout <<"\nName of Runner " << i+1 << ": ";
        getline(cin,rName[i]);
        cout <<"Runner "<< i+1 <<"'s finishing time: ";
        cin >> rTime[i];
        cin.ignore();
    }

    for (int i=0; i<Size; i++){
        if (rTime[i] < 0)
            x = 1;
         }
    if(rTime[0] < rTime[1]){
            if (rTime[1] < rTime[2]){
                first = rName[0];
                second = rName[1];
                third = rName[2];
                }
            else if(rTime[2] < rTime[0]){
                first = rName[2];
                second = rName[0];
                third = rName[1];
                }
            else {
                first = rName[0];
                second = rName[2];
                third = rName[1];
                }
                }
    else if(rTime[1] < rTime[0]){
            if (rTime[0] < rTime[2]){
                first = rName[1];
                second = rName[0];
                third = rName[2];
                }
            else if (rTime[2] < rTime[1]){
                first = rName[2];
                second = rName[1];
                third = rName[0];
                }
            else{
                first = rName[1];
                second = rName[2];
                third = rName[0];
            }
    }

    if (x != 1){
        cout <<"\n" << first << " came in 1st place.\n";
        cout << second << " came in 2st place.\n";
        cout << third << " came in 3st place.\n" << endl;
    }
    else
        cout << "\nEnter positive values only for each runner's time." << endl;

        return 0;
}

