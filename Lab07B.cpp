/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab 7B
    Description: Lab working with 2D arrays and File I/O.
    Taking information from a file, storing into a 2D array and printing content to screen.
    Input: User inputs file name to be open
    Output: Displays the information in the file including, name of city, year, highest,
    and lowest temperature alonside average temperature for high and low.
*/

// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

// Declaring Const Variables
const int ROW = 12;
const int COLUMN = 2;
// Intro to main code
int main()
{

    // varibale Declaration
    ifstream inFile;
    string fileName = " ";
    string cityName = " ";
    int year = 0;
    float lowestTemperature = 100;
    float highestTemperature = 0;
    float averageLowestTemperature = 0;
    float averageHighestTemperature = 0;
    float numbers[ROW][COLUMN];
    // Loop for asking File name
    do
    {
        cout << "Enter file name\n**";
        getline(cin, fileName);
        inFile.open(fileName);
        if (!inFile.is_open())
        {
            cout << "\nError: Invalid File Name\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;

    } while (!inFile.is_open());
    // Gather City Name and Year standard inFile
    getline(inFile, cityName, ' ');
    inFile.clear();
    inFile >> year;
    inFile.clear();
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    // Loop for storing into array
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COLUMN; c++)
        {
            inFile >> numbers[r][c];
            // Sets lowest Temperature once found
            if (numbers[r][0] < lowestTemperature)
            {
                lowestTemperature = numbers[r][0];
            }
            // Sets highest Temperature once found
            if (numbers[r][1] > highestTemperature)
            {
                highestTemperature = numbers[r][1];
            }
            //Setting the average High Temperature by adding up the second column
            averageHighestTemperature += numbers[r][1];
        }
        //Setting the average Low Temperature by adding up the first column
        averageLowestTemperature += numbers[r][0];
    }
    // Print out information
    cout << endl << cityName << " " << year << endl;
    cout << fixed << setprecision(2)
         << "Lowest temperature of the year was " << lowestTemperature << "° F.\n"
         << "Highest temperature of the year was " << highestTemperature << "° F.\n"
         << "Average low temperature of the year was " << (averageLowestTemperature / 12) << "° F.\n"
         << "Average high temperature of the year was " << (averageHighestTemperature / 12) << "° F.\n";
}
