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
//Switch to doubles Fixed with SetP
#include<iomanip>

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
    int arr[ROW][COLUMN];

    // loop for checking file is open
    do
    {
        cout << "Enter a file name\n**";
        getline(cin, fileName);
        iFile.open(fileName);

        if (!iFile.is_open())
        {
            cout << "\nError invalid file name\n";
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
    // Printing Data from the 2D Array
    // Row to colum based
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COLUMN; c++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Colum to Row based
    for (int c = 0; c < COLUMN; c++)
    {
        for (int r = 0; r < ROW; r++)
        {
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
