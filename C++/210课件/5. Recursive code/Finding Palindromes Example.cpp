#include <iostream>
using namespace std;

bool isPalindrome(string candidateString, int start, int end, int recursionLevel)
{
    cout << "in isPalindrome, recursion level " << recursionLevel << endl;
    if ((end-start)<=1)
    {
        cout << "in isPalindrome, recursion level " << recursionLevel << " returning 1" << endl;
        return true;
    }
    else
    {
        if (candidateString[start]==candidateString[end-1])
        {
            bool returnValue = isPalindrome(candidateString,start+1,end-1,recursionLevel+1);
            cout << "in isPalindrome, recursion level " << recursionLevel << " returning " << returnValue << endl;
            return returnValue;
        }
        else
        {
            cout << "in isPalindrome, recursion level " << recursionLevel << " returning 0" << endl;
            return false;
        }
    }
}

int main()
{
    string exampleString = "aac2bc5ed3de5cb2caa";
    cout << "[main] Recursive function to determine if " << exampleString << " is a palindrome.\n";
    cout << "[main] The string is a palindrome? " << endl << isPalindrome(exampleString,0,exampleString.size(),0);
    return 0;
}
