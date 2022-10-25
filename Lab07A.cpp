/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab 7A
    Description: Program takes input into a 2D array and displays sums
    Both in Row to Column and Column to Row
    Input: User inputs File Name to be open
    Output: Outputs the values from the file in Rows to Columns and
    Columns to Row. Along with their sums in each respective row/column.
*/

// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;
// Declaring const variables
const int ROW = 7;
const int COLUMN = 10;
// Intro to main code
int main()
{
    // Variable declaration
    ifstream iFile;
    string fileName = " ";
    double arr[ROW][COLUMN];

    // loop for checking file is open
    do
    {
        cout << "Enter a file name\n**";
        getline(cin, fileName);
        iFile.open(fileName);

        if (!iFile.is_open())
        {
            cout << "\nError: Invalid File Name\n";
            iFile.clear();
            iFile.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (!iFile.is_open());
    // Storing Data in the 2D Array
    // Note: having r be row and c be column helps me keep track better
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COLUMN; c++)
        {
            iFile >> arr[r][c];
        }
    }
    cout << "\nROW SUMS:\n";
    // Printing Data from the 2D Array
    // Row to colum based
    double sumRowBased = 0.0;
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COLUMN; c++)
        {

            cout << left << setw(4) << fixed << setprecision(1) << arr[r][c];
            // Places + or = based on the current Column using Ternary
            (c == COLUMN - 1) ? cout << " " : cout << " + ";
            sumRowBased += arr[r][c];
        }
        cout << "= " << sumRowBased;
        // reset sums so its set for next row
        sumRowBased = 0;
        cout << endl;
    }

    cout << endl;
    // Colum to Row based
    double sumColumnBased = 0.0;
    cout << "COLUMN SUMS:\n";
    for (int c = 0; c < COLUMN; c++)
    {
        for (int r = 0; r < ROW; r++)
        {
            cout << left << setw(4) << fixed << setprecision(1) << arr[r][c];
            sumColumnBased += arr[r][c];
            // Places + or = Based on current Row using Ternary
            (r == ROW - 1) ? cout << " " : cout << " + ";
        }
        cout << "= " << sumColumnBased;
        // reset sums so its set for next column
        sumColumnBased = 0;
        cout << endl;
    }
    cout << endl;
}
