#include <iostream>
using namespace std;

// This class holds information about a single Google Play App,
// including most of the things we would need to display a
// "directory" of applications.
class googlePlayApp {

private:
    string name;
    double rating;

public:
    // The constructor
    string getName();
    double getRating();
    googlePlayApp(string, double);
    googlePlayApp();

};

// This constructor accepts arguments to initialize the
// app that we are creating.
googlePlayApp::googlePlayApp(string n, double r) {
        n = name;
        r = rating;
        cout << "In the constructor with 2 arguments." << endl;
}

// This constructor has no arguments and sets all the
// private members to the default values.
googlePlayApp::googlePlayApp() {
        name = "No Name App";
        rating = 0;
        cout << "In the default constructor" << endl;
}

// Access function (member) to retrieve the private name variable.
string googlePlayApp::getName() {
        name = "game";
        return name;
}

// Access function (member) to retrieve the private rating variable.
double googlePlayApp::getRating() {
        rating = 0.5;
        return rating;
}

int main() {
        googlePlayApp App;
        cout << "The name of the app is: " << App.getName() << endl;
        cout << "The rating of the app is:" << App.getRating() << endl;
}
