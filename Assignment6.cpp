/*
          Name: Alvaro A. Cruz, #5005488379, 1005, Labo08B
          Description: Program displays information about a circle
          given a radius within certain range. Implementing various
          self-declared functions.
          Input:User inputs radius of circle
          Output: Displays Circumference, Area, and radius
*/

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;
// Function Protoypes
void displayLogo();
int openLevel(int &, ifstream &);
vector<vector<char> > levelSelection(int, ifstream &);

// Intro to main code
int main()
{
    // Variable Declaration
    ifstream inFile; // Input file stream variable
    int guesses = 5;
    char guess = ' ';
    vector<char> failedGuesses; //Vector contains the incorrectGuesses
    //  Display Game Logo
    displayLogo();
    // Tracks what level is currently playing;
    int level = openLevel(level, inFile);
    // 2D Vector containing solution to crossword
    vector<vector<char> > answerKeyVector2D = levelSelection(level, inFile);
    vector<vector<char> > gameBoard = answerKeyVector2D;
    // Testing Printing the soultion vector

    for (unsigned int i = 0; i < gameBoard.size(); i++)
    {
        for (unsigned int j = 0; j < gameBoard[i].size(); j++)
        {
            (gameBoard.at(i).at(j) != '#') 
            ? cout << left << setw(2) << "_" : cout << left << setw(2) << gameBoard.at(i).at(j);
        }
        cout << endl;
    }

do
{
    cout << "\nEnter a letter:\n";
    cin >> guess;
    for (unsigned int i = 0; i < answerKeyVector2D.size(); i++)
    {
        for (unsigned int j = 0; j < answerKeyVector2D[i].size(); j++)
        {
            if (answerKeyVector2D.at(i).at(j) == guess)
            {   
                cout << left << setw(2) << gameBoard.at(i).at(j);
            }
            if (answerKeyVector2D.at(i).at(j) != guess) {
               failedGuesses.push_back(guess);
              (answerKeyVector2D.at(i).at(j) != '#') ? cout << left << setw(2) << "_" : cout << left << setw(2) << answerKeyVector2D.at(i).at(j);
            }
            
        }
        cout << endl;
    }
    guesses--;

} while (guesses > 0);

    

}
// Function to Print game Logo
void displayLogo()
{
    cout << setw(17) << "Welcome to\n\n"
         << setw(11) << "W\n"
         << setw(13) << "CROSS\n"
         << setw(11) << "R\n"
         << setw(12) << "D\n\n";
}
// Opens file according to Level and returns the level currently on.
int openLevel(int &level, ifstream &inFile)
{
    do
    {
        cout << "Enter level to play:\n";
        cin >> level;
        if (cin.fail() || level < 1)
        {
            cout << "Invalid Entry!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (level > 0)
        {
            switch (level)
            {
            case 1:
                inFile.open("level1.txt");
                break;
            case 2:
                inFile.open("level2.txt");
                break;
            case 3:
                inFile.open("level3.txt");
                break;
            default:
                cout << "Level files could not be found!\n";
                break;
            }
        }
    } while (!inFile.is_open());
    cout << endl;
    return level;
}
// Hopefully this places the vector values in the right place
vector<vector<char> > levelSelection(int level, ifstream &inFile)
{
    vector<vector<char> > solutions2D;
    int height, width = 0;
    if (level == 1)
    {
        // Settings for first level
        for (height = 1; height <= 5; height++)
        {
            // Vector that acts as row
            vector<char> vectorRow;
            char soultions;
            for (width = 1; width <= 10; width++)
            {
                // gather the row and add to vector
                inFile >> soultions;
                vectorRow.push_back(soultions);
            }
            // Add the rows to the solution vector
            solutions2D.push_back(vectorRow);
        }
    }
    if (level == 2)
    {
        // Settings for first level
        for (height = 1; height <= 7; height++)
        {
            // Vector that acts as row
            vector<char> vectorRow;
            char soultions;
            for (width = 1; width <= 6; width++)
            {
                // gather the row and add to vector
                inFile >> soultions;
                vectorRow.push_back(soultions);
            }
            // Add the rows to the solution vector
            solutions2D.push_back(vectorRow);
        }
    }
    if (level == 3)
    {
        // Settings for first level
        for (height = 1; height <= 7; height++)
        {
            // Vector that acts as row
            vector<char> vectorRow;
            char soultions;
            for (width = 1; width <= 9; width++)
            {
                // gather the row and add to vector
                inFile >> soultions;
                vectorRow.push_back(soultions);
            }
            // Add the rows to the solution vector
            solutions2D.push_back(vectorRow);
        }
    }
    return solutions2D;
}
