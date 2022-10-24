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
            cout << "Could not open nonexistant\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!inFile.is_open());
    outFile.open("[10-09-22]Report.txt");

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

    // Loop prints out violations and increases counter per violation
    // Open various files in case of date change closing previous date
    int violations = 0;
    for (int i = 0; i < dataTracker; i++)
    {
        if (date[i] == "10-09-2022")
        {

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
            continue;
        }
    }
    // Closing file for violations occuring on 10/09/22
    outFile.close();

    // Opening the File for violations occuring on 10/10/22
    outFile.open("[10-10-2022]Report.txt");
    // Printing the violations for 10/10/22
    for (int i = 0; i < dataTracker; i++)
    {
        if (date[i] == "10-10-2022")
        {

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
            continue;
        }
    }
    //DO THE SAME FOR DATE 10/11/22
    
    // Closing the Files
    outFile.close();
    inFile.close();
    cout << violations << " Violations logged." << endl;
}
