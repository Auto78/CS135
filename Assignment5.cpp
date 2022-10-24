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

// Use arrays
const int ARRAY_SIZE = 1010;

// Intro to Main Code:
int main()
{

    // Variable Declaration
    ifstream inFile;  // Input file stream variable
    ofstream outFile; // Output file stream variable
    string fileName;  // Name of file to be opened
    string licensePlate[ARRAY_SIZE] = {};
    string date[ARRAY_SIZE] = {};
    string time[ARRAY_SIZE] = {};
    double weight[ARRAY_SIZE] = {};
    double speed[ARRAY_SIZE] = {};
    int dataTracker = 0;

    // Loop asks user to open a file and checks that it opens
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

    // While loop takes in input until EoF
    while (!inFile.eof())
    {
        getline(inFile, licensePlate[dataTracker], ',');
        getline(inFile, date[dataTracker], ',');
        getline(inFile, time[dataTracker], ',');
        inFile >> weight[dataTracker];
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(), ',');

        inFile >> speed[dataTracker];
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        dataTracker++;
    }
    // Closing Files after input gathered
    inFile.close();
    // Checking that Speeds and Weights don't violate laws
    /*FIX VIOLATION TO CORRECT OUPUT 
    Change couts to outFile*/
    int violations = 0;
    for (int i = 0; i < dataTracker; i++)
    {

        if (weight[i] < 5000 && speed[i] > 45)
        {
            cout << "[" << time[i] << "] "
            << licensePlate[i] << endl;
            violations += 1;
        }
    }
    cout << endl;
    cout << violations << " Violations logged." << endl;
    
}
