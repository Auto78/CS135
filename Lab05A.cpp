/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab05A
    Description: Program that takes in user information and prints amount of stars inputed in a up and down
    pyramid format. Using Do-While, For, and While loops to ensure proper printing.
    Input: User inputs inital "count" between range of 2-20
    Output: Prints number of stars in an upside down and rightside up pryamid.
*/

// Preprocessor Directories
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Intro to main code
int main()
{
    // Variable declaration
    int count = 0;
    int amountOfStars = 0;
    int rowTwo = 0;

    // Do-While loop controls validates and accepts correct input.
    do
    {
        // Will ask for input "count" so long as input is invalid
        cout << "Enter a count between 2 and 20\n"
             << "**";
        cin >> count;
        cout << endl;
        // If statments ensure correct conditions are met
        if (cin.fail())
        {
            cout << "Error: Invalid entry, please retry\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (count <= 1 || count > 20)
        {
            cout << "Error: Invalid entry, please retry\n";
            continue;
        }
        break;
    } while (true);

    // Outer for loop controls the endl(s) until amount of star is 0
    for (amountOfStars = count; amountOfStars > 0; amountOfStars--)
    {
        // Inner loop controls printed stars in each row in accordance with amount of stars
        for (int row = 0; row < amountOfStars; row++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // setting amount of stars to 1
    amountOfStars = 1;
    // Printing stars via while loop
    // Outer While loops controls endl(s) so long as amount of stars is less or equal to count
    while (amountOfStars <= count)
    {
        // Setting a 'Flag for rowTwo that matches inital ammount of stars
        rowTwo = 1;
        // Inner While loop will print "*" in accordance to number in amount of stars
        while (rowTwo <= amountOfStars)
        {
            cout << "*";
            rowTwo++;
        }
        cout << endl;
        amountOfStars++;
    }
}
