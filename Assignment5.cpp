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
#include <climits>

using namespace std;

// Use arrays
const int ARRAY_SIZE = INT_MAX;

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
    int weight[ARRAY_SIZE] = {};
    int speed[ARRAY_SIZE] = {};
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
        inFile >> speed[dataTracker];
        // Error Checker accounting for endl at eof
        if (!inFile)
        {
            if (!inFile.eof())
            {
                inFile.clear();
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            continue;
        }
        dataTracker++;
    }
    // Testing
    for (int i = 0; i < dataTracker; i++)
    {
        cout << "Licenses: " << licensePlate[i];
    }
    cout << endl;
    for (int i = 0; i < dataTracker; i++)
    {
        cout << "Dates: " << date[i];
    }
    cout << endl;
    for (int i = 0; i < dataTracker; i++)
    {
        cout << "Times: " << time[i];
    }
    cout << endl;
    for (int i = 0; i < dataTracker; i++)
    {
        cout << "Weights: " << weight[i];
    }
    cout << endl;
    for (int i = 0; i < dataTracker; i++)
    {
        cout << "Speed: " << speed[i];
    }
    cout << endl;
}
