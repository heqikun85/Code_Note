#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void getdata(vector<string> &, vector<string> &);
void disteam(vector<string>);
int userChoice(vector<string>, string &);
void result(string, int);

int main() {
	vector<string> teams, winners;
	string name;
	int times;
	
	getdata(teams, winners);
	disteam(teams);
	times = userChoice(winners, name);
	result(name, times);

	system("pause");
	return 0;
}

//I'm not totally understand about note#1 
//(You will also need to pass in a second argument 
//so that inside of the function you can distinguish between teams and winners 
//(for example, so you can open the correct file to read from). 
//The second argument could be a number of different things: 
//a string that stores either the word "teams" or "winners" a boolean
//(e.g., true = teams and false = winners), a char, an integer, etc. Again)
//I just put these two vector in one function, but I don't need argument for bool or char etc.
//It's can reach the goal, but I'm not sure that you want us to do.
void getdata(vector<string> &teams, vector<string> &winners) {
	ifstream iteam, iwinner;
	iteam.open("Teams.txt");
	if (iteam.good()) {
		for (string name; getline(iteam, name);)
			teams.push_back(name);
	}
	iteam.close();
	
	iwinner.open("Winners.txt");
	if (iwinner.good()) {
		for (string name; getline(iwinner, name);)
			winners.push_back(name);
	}
	iwinner.close();
}

void disteam(vector<string> teams){
	cout << "The following teams have won the World Series at least once:\n" << endl;
	for (int i = 0; i < teams.size()-1; i+=3){
		for(int j =0; j<3;j++){
			if(i+j<teams.size())
			cout << left << setw(25) << setfill(' ') << teams.at(i+j);
		}
		cout << "\n";
	}
	    cout << "\n";
}

int userChoice(vector<string> winners, string &name) {
	int temp = 0;
	cout << "Enter the name of one of the teams: ";
	getline(cin, name);
	for (int i = 0; i < winners.size(); i++){
		if (name == winners.at(i))
			temp++;
	}
	return temp;
}

void result(string name, int times) {
	cout << "The " << name << " have won the World Series " << times << " between 1903 and 2012.\n"<< endl;
}