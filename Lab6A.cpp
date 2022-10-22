/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab 06A
    Description: Program that prompts user to open a file, repeats upon invaild input and
    then takes in file input into an array and prints elements to screen
    alongside statistics performed with said elements.
    Input: User inputs File to be open
    Output: Prints elements in array forward and backwards.
    Prints the min, max, sum, and average of elements in the array.
*/

// PreProcessor Directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Declaring Const Variables
const int ARRAY_SIZE = 100;
// Intro to main code
int main()
{

    // Variable Declaration;
    ifstream inFile;
    string fileName = " ";
    double numbers[ARRAY_SIZE] = {};
    int fileNumberOfElements = 0;
    double sum = 0.0;
    double average = 0.0;
    double maximum = numbers[0];
    
    // Loop for receving File Name
    do
    {
        cout << "Enter a file name\n**";
        getline(cin, fileName);
        inFile.open(fileName);

        // Checking if File opened
        if (!inFile.is_open())
        {
            cout << "\nError: Invalid file name.\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!inFile.is_open());
    // Input file values into the array while !EoF
    while (!inFile.eof())
    {
        inFile >> numbers[fileNumberOfElements];
        // Output error for bad input accounting for endl
        if (!inFile)
        {
            if (!inFile.eof())
            {
                inFile.clear();
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nError: Invalid input in file.";
            }
            continue;
        }

        fileNumberOfElements++;
    }
    // Close the File
    inFile.close();
    cout << endl
         << endl;
    // Printing Number of Elements
    cout << "Amount of Elements Read In: " << fileNumberOfElements << endl;
    // Printing Elements Forwards
    cout << "Forwards: ";
    for (int i = 0; i < fileNumberOfElements; i++)
    {
        cout << fixed << setprecision(2) << numbers[i];
        if (i < fileNumberOfElements - 1)
        {
            cout << ", ";
        }
    }
    // Printing Elements Backwards
    cout << endl;
    cout << "Backwards: ";
    for (int i = fileNumberOfElements - 1; i > -1; i--)
    {
        cout << fixed << setprecision(2) << numbers[i];
        if (i > 0)
        {
            cout << ", ";
        }

        }

    cout << endl;

    // Calculating the Sum, Maximum, Minimum
    double minimum = numbers[0];

    for (int i = 0; i < fileNumberOfElements; i++)
    {
        sum += numbers[i];
        // If at any point [i] is bigger than max or smaller then min
        //  Override min and max with array at the point [i]
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    cout << "Minimum: " << fixed << setprecision(2) << minimum << endl;
    cout << "Maximum: " << fixed << setprecision(2) << maximum << endl;
    cout << "Sum: " << fixed << setprecision(2) << sum << endl;

    // Calculating and Printing The Average
    average = sum / fileNumberOfElements;
    cout << "Average: " << fixed << setprecision(2) << average << endl;
}
