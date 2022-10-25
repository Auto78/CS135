/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab 7A
    Description:
    Input:
    Output:
*/

// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;
// Declaring const variables

// Intro to main code
int main()
{

    // Variable declaration
    ifstream inFile;
    string fileName = " ";

    // loop for checking file is open
    do
    {
        cout << "Enter a file name\n**";
        getline(cin, fileName);
        inFile.open(fileName);

        if (!inFile.is_open())
        {
            cout << "\nError invalid file name\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!inFile.is_open());
}
