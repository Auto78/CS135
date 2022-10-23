/*
    Name: Alvaro Cruz, 5005488379, 1005, ASSIGNMENT 5
    Description:
    Input: User input:
    Output:
*/
// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// I think I could use arrays but its not needed so attempt without and see how it goes 10/22

// Intro to Main Code:
int main()
{

    // Variable Declaration
    ifstream inFile;  // Input file stream variable
    ofstream outFile; // Output file stream variable
    string fileName;  // Name of file to be opened
    string licensePlate = " ";
    string date = " ";
    string time = " ";
    int weight = 0;
    int speed = 0;

//Loop asks user to open a file and checks that it opens
    do
    {
        cout << "Open File: ";
        getline(cin, fileName);
        inFile.open(fileName);
        if (!inFile.is_open())
        {
            cout << "Could not open nonexistant\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!inFile.is_open());
    //Simple testing to see that the file opened
    if (inFile.is_open())
    {
        cout << "you opened a file " << fileName;
        cout << endl;
    }
    
    
}
