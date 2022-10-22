/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab 6B
    Description: A program utilizing 1D arrays, parallel arrays, and file I/O
    to check for a name in an array and the score for said name.
    Input: User inputs File to be open and name to be searched.
    Output: Prints names & scores both backwards and forwards. Displays
    amount of times name is in file and calculations using the score for the name.
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

    // Main Variable Declaration;
    ifstream inFile;
    string fileName = " ";
    string toFind = " ";
    string names[ARRAY_SIZE] = {};
    double scores[ARRAY_SIZE] = {};
    int namesTracker = 0;
    int scoresTracker = 0;
    // Do loop controls file input
    do
    {
        cout << "Enter a file name\n**";
        getline(cin, fileName);
        inFile.open(fileName);
        // Checking file is open
        if (!inFile.is_open())
        {
            cout << "\nError: Invalid file name.\n";
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!inFile.is_open());

    // Prompt user to look for name
    cout << "\nEnter a name to search\n**";
    getline(cin, toFind);
    cout << endl;

    // Infile names and scores into arrays no error checking needed
    while (!inFile.eof())
    {

        inFile >> names[namesTracker];
        /*Note: Having them fixed & setP when piped in aligns int vs double
        automatically without need to change variable type i.e.
        ints show as ints and doubles show as doubles*/
        inFile >> scores[scoresTracker] >> fixed >> setprecision(2);

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
        namesTracker++;
        scoresTracker++;
    }
    //Closing the File
    inFile.close();
    // Printing names Forwards
    cout << "Names Forward: ";
    for (int i = 0; i < namesTracker; i++)
    {
        cout << names[i];

        if (i < namesTracker - 1)
        {
            cout << ", ";
        }
    }

    // Printing Scores Forwards
    cout << "\nScores Forward: ";
    for (int i = 0; i < scoresTracker; i++)
    {
        cout << scores[i];
        if (i < scoresTracker - 1)
        {
            cout << ", ";
        }
    }
    // Printing Names Backwards
    cout << "\nNames Reverse: ";
    for (int i = namesTracker - 1; i > -1; i--)
    {
        cout << names[i];
        if (i > 0)
        {
            cout << ", ";
        }
    }
    // Printing Scores Backwards
    cout << "\nScores Reverse: ";
    for (int i = scoresTracker - 1; i > -1; i--)
    {

        cout << scores[i];
        if (i > 0)
        {
            cout << ", ";
        }
    }
    cout << endl;

    // Performing Calculations dependent on name
    // Declaration for calculation Variables
    double minimum = 100.0;
    double maximum = 0.0;
    int foundCount = 0;
    double sum = 0.0;
    double average = 0.0;

    // Iterating Arrays together
    // Outer loop works controls flow
    for (int i = 0; i < namesTracker; i++)
    {
        // Checking for toFind in names array
        if (names[i] == toFind)
        {
            sum += scores[i];
            foundCount++;
            /*If loops checks for min and max and overides
            if a smaller or larger value is found*/
            if (scores[i] < minimum)
            {
                minimum = scores[i];
            }
            if (scores[i] > maximum)
            {
                maximum = scores[i];
            }

            continue;
        }
    }

    // If loops prints info if name is found
    if (foundCount)
    {
        average = sum / foundCount;
        cout << foundCount << " results for " << toFind << endl;
        cout << "Minimum: " << fixed << setprecision(2) << minimum << endl;
        cout << "Maximum: " << fixed << setprecision(2) << maximum << endl;
        cout << "Sum:     " << fixed << setprecision(2) << sum << endl;
        cout << "Average: " << fixed << setprecision(2) << average << endl;
    }
    // If loop prints error message if name !found
    if (!foundCount)
    {
        cout << "Error: " << toFind << " is not a student in the list\n";
    }

}
