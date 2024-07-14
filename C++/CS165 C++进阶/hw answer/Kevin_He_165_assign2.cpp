#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global constants to represent rock,
// paper, or scissors.
const int ROCK		= 1;
const int PAPER		= 2;
const int SCISSORS	= 3;
const int QUIT      = 4;

// Function Prototypes
int getUserChoice();
int getComputerChoice();
void determineOutcome(int, int);
void displayChoice(int);

int main()
{
	int userChoice;		// To hold the user's choice
	int computerChoice;	// To hold the computer's choice

	// Get the computer's choice.
	computerChoice = getComputerChoice();

	// Get the user's choice.
	userChoice = getUserChoice();

	while (userChoice != QUIT){

		// Display the choices.
		cout << "\nYou selected: ";
		displayChoice(userChoice);
		cout << "The computer selected: ";
		displayChoice(computerChoice);

		// Determine the winner.
		determineOutcome(userChoice, computerChoice);
		cout<<endl;

		// Get the computer's choice.
		computerChoice = getComputerChoice();

		// Get the user's choice.
		userChoice = getUserChoice();
	}

	system("PAUSE");
	return 0;
}

// ********************************************************
// The getComputerChoice function returns the computer's  *
// game choice. It returns 1 for rock (via the ROCK       *
// constant), or 2 for paper (via the PAPER constant),    *
// or 3 for scissors (via the SCISSORS constant).         *
// ********************************************************
int getComputerChoice()
{
    srand(time(0));
    int num;
    num = 1+rand()%(3);

    return num;
}

// ********************************************************
// The getUserChoice function displays a menu allowing    *
// the user to select rock, paper, or scissors. The       *
// function then returns 1 for rock (via the ROCK         *
// constant), or 2 for paper (via the PAPER constant),    *
// or 3 for scissors (via the SCISSORS constant),         *
// or 4 for quit (via the QUIT constant).                 *
// ********************************************************
int getUserChoice()
{
    int num;

    cout << "Game Menu\n";
    cout << "---------\n";
    cout << "1) Rock\n";
    cout << "2) Paper\n";
    cout << "3) Scissors\n";
    cout << "4) Quit\n" << endl;
    cout << "Please enter your Choice: ";
    cin >> num;

    while(num < ROCK || num > QUIT){
            cout << "Invalid selection. Enter 1, 2, 3 or 4: ";
            cin >> num;
    }

    return num;
}

// ********************************************************
// The determineOutcome function accepts the user's game   *
// choice and the computer's game choice as arguments and  *
// displays a message indicating the winner                *
 // or that a tie occurred.                                *
// ********************************************************
void determineOutcome(int user, int computer)
{
	if(user > computer){

        if(computer == ROCK && user == SCISSORS)
            cout << "Computer wins! Rock smashes scissors." <<endl;

        else if (computer == ROCK && user == PAPER)
            cout << "You wins! Paper smashes rock." <<endl;

        else
            cout << "You wins! Scissors smashes paper." <<endl;
	}

	else if(user < computer){

        if (user == ROCK && computer == SCISSORS)
            cout << "You wins! Rock smashes scissors." <<endl;

        else if (user == ROCK && computer == PAPER)
            cout << "Computer wins! Paper smashes rock." <<endl;

        else
            cout << "Computer wins! Scissors smashes paper." <<endl;
	}

	else{
        cout << "Tie. No winner." <<endl;
	}
	}


// ********************************************************
// The displayChoice function accepts an integer argument *
// and displays rock, paper, or scissors.                 *
// ********************************************************
void displayChoice(int choice)
{
        switch(choice){
            case ROCK: cout << "Rock\n";
            break;
            case PAPER: cout << "Paper\n";
            break;
            case SCISSORS: cout << "Scissors\n";
            break;
        }
    }

