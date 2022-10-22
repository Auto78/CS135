/*
    Name: Alvaro Cruz, 5005488379, 1005, Lab05B
    Description: Program that takes in file input and add numbers from file running total.
    which is then printed to screen. Should file not open properly, error message prints and prompts again.
    Should file input fail error message is printed and contiues until end of file is reached
    Input: User inputs file to be opened. File input is then taken to calculate/print totals
    Output: Prints numbers retrived from file input onto screen alongside total. Prints running total
    at the last line. Prints error message if file isnt opened or file input isn't valid
*/

// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

//Intro to main code
int main()
{

    // Variable Declarations
    int runningTotal = 0;
    string fileName = "";
    ifstream inFile;

    // Prompt user to enter a file name so long as the file isn't properly opened
    do
    {
        cout << "Enter file name\n**";
        getline(cin, fileName);
        cout << endl;
        //Opening the file
        inFile.open(fileName);
        // If statment checks if File succesfully opened outputting error message if it didn't
        if (!inFile.is_open())
        {
            cout << "Error: Invalid file name\n";
            //Clears infile (cin.clear)
            inFile.clear();
            //Ignores infile up until newline is found(cin.ignore)
            inFile.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
        break;
    } while (!inFile.is_open());
    // Prints contents of file onto screen while it hasn't reached the end of the file
    do
    {
        // Variable declartions for file manipulation
        int firstNumber = 0;
        int secondNumber = 0;
        int numberSum = 0;
        // Inputs data from files (i.e. cin)
        inFile >> firstNumber >> secondNumber;
        // Checks for correct input(i.e. cin.fail) prints erorr message if wrong input
        if (inFile.fail())
        {
            cout << "Error in line\n";
            // Clears the input file stream and ignores until endline for next input value
            inFile.clear();
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            // Continues with outer do while loop; Doesn't end program
            continue;
        }
        // updates variables and prints to screen repeats until eof
        numberSum = firstNumber + secondNumber;
        cout << firstNumber << " + " << secondNumber << " = " << numberSum << endl;
        // Adds up all the sums into total and repeats until eof
        runningTotal += numberSum;

    } while (!inFile.eof());

    // Prints running total to screen
    cout << "\nRunning total = " << runningTotal << endl;

    // Close the file
    inFile.close();
}
