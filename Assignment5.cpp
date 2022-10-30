/*
    Name: Alvaro Cruz, 5005488379, 1005, ASSIGNMENT 5
    Description: Program takes in file input and outputs files for violations
    creates new files dependent on the day violation occured
    Input: User input: user inputs file name to be open
    Output: Prints number of violations logged to screen.
    Creates files with corresponding violations logged into them.
*/
// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Use Arrays
const int ARRAY_SIZE = 1010;

// Intro to Main Code:
int main()
{

    // Variable Declaration
    ifstream inFile; // Input file stream variable
    string fileName; // Name of file to be opened
    string licensePlate[ARRAY_SIZE] = {};
    string date[ARRAY_SIZE] = {};
    string time[ARRAY_SIZE] = {};
    double weight[ARRAY_SIZE] = {};
    double speed[ARRAY_SIZE] = {};
    int dataTracker = 0;
    ofstream outFile; // Output file stream variable
    // Loop asks user to open a file and checks that it opens
    do
    {
        cout << "Open File: ";
        getline(cin, fileName);
        inFile.open(fileName);
        if (!inFile.is_open())
        {
            cout << "Could not open " << fileName << "\n";
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
    outFile.open("[" + date[0] + "]" + " Report.txt");

    // Loop prints out violations and increases counter per violation

    int violations = 0;

    for (int i = 0; i < dataTracker; i++)
    {
        // Open various files in case of date change closing previous date
        if (date[i] != date[i - 1])
        {
            if (outFile.is_open())
            {
                outFile.close();
            }
            outFile.open("[" + date[i] + "]" + " Report.txt");
        }
        // Conditions for Violaions
        if (weight[i] < 5000 && speed[i] > 45)
        {
            outFile << "[" << time[i] << "] "
                    << licensePlate[i] << endl;
            violations++;
        }
        if (weight[i] >= 5000 && speed[i] > 30)
        {
            outFile << "[" << time[i] << "] "
                    << licensePlate[i] << endl;
            violations++;
        }
    }
    // Closing the Files
    outFile.close();
    inFile.close();
    cout << violations << " violations logged." << endl;
}
