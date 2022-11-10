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
#include<algorithm>

using namespace std;
// Function Protoypes
void displayLogo();
void openLevel(ifstream &);
vector<vector<char> > readLevel(ifstream &);
vector<vector<char> > replaceBoard(vector<vector<char> >);
void printsBoard(vector<vector<char> >);

// Intro to main code
int main()
{
    // Variable Declaration
    ifstream inFile;             // Input file stream variable
    char guess = ' ';            // Letter to Check
    vector<char> exhaustedGuess; // Vector contains the used guesses
    int incorrectGuess = 5;      // Number of incorrect guess avaliable
    //  Display Game Logo
    displayLogo();
    // Tracks what level is currently playing;
    openLevel(inFile);
    // Vector conatians the level in a gameboard style
    vector<vector<char> > gameBoard;
    gameBoard = readLevel(inFile);
    // This vector contains the answerkey before replacing the gameboard to only # & _
    vector<vector<char> > answerKey = gameBoard;
    // Replacing the gameboard with inital Status; # & _
    gameBoard = replaceBoard(gameBoard);
    printsBoard(gameBoard);


    // Asking user for letter to check
    do
    {
        cout << "\nEnter a letter:\n";
        cin >> guess;
        for (size_t i = 0; i < answerKey.size(); i++)
        {   
            for (size_t j = 0; i < answerKey[i].size(); i++)
            {
                
            cout << answerKey[i][j];
            }
        }
        exhaustedGuess.push_back(guess);
    } while (true);
}
// Prints gameboard

// Function to Print game Logo
void displayLogo()
{
    cout << endl
         << setw(17) << "Welcome to\n\n"
         << setw(11) << "W\n"
         << setw(15) << "C R O S S\n"
         << setw(11) << "R\n"
         << setw(12) << "D\n\n";
}
// Opens file according to Level and returns the level currently on.
void openLevel(ifstream &inFile)
{
    int level;
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
}
// Hopefully this places the vector values in the right place
vector<vector<char> > readLevel(ifstream &inFile)
{
    vector<vector<char> > solutions2D;
    string line;
    while (getline(inFile, line))
    {
        vector<char> vectorRow;
        for (unsigned int i = 0; i < line.length(); i++)
        {
            vectorRow.push_back(line[i]);
        }
        solutions2D.push_back(vectorRow);
    }
    inFile.close();
    return solutions2D;
}
// Makes replacements to the board having it start as # and _ only
vector<vector<char> > replaceBoard(vector<vector<char> > board)
{

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '#' && board[i][j] != ' ')
            {
                board[i][j] = '_';
            }
        }
    }
    return board;
}
// Prints the gameboard
void printsBoard(vector<vector<char> > board)
{
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
