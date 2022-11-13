/*
          Name: Alvaro A. Cruz, #5005488379, 1005, Assignment 6
          Description: Program plays a game of Crossword(with replayability) given a file containing 
          the crossword. Performs task using a variety of self-made functions and vectors. 
          Input:User inputs "level" to play and guess to be placed on crossword
          Output: Displays current crossword game board and number of incorrect
          guess left.
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
void openLevel(ifstream &);
vector<vector<char> > readLevel(ifstream &);
vector<vector<char> > replaceBoard(vector<vector<char> >);
void printsBoard(vector<vector<char> >);
bool onTheBoard(vector<vector<char> >, char);
bool exhuastedGuesses(vector<char>, char);

// Intro to main code
int main()
{
    // Variable Declaration
    ifstream inFile;
    char guess = ' ';
    int incorrectGuess = 5;
    char playAgain = ' ';
    bool playAgainFlag = false;
    bool gameOver = false;
    vector<vector<char> > answerKey; // Vector will contain solution to crossword
    vector<vector<char> > gameBoard; // Vector contains current gameboard to crossword
    vector<char> exhaustedGuess;    // Vector contains the used guesses

    // OutputPhase

    displayLogo();                       // Display Game Logo
    openLevel(inFile);                   // Open the level to be played;
    gameBoard = readLevel(inFile);       // Input the crossword answer key into the gameboard
    answerKey = gameBoard;               // Store the answerkey before replacing the gameboard to only # & _
    gameBoard = replaceBoard(gameBoard); // Replacing the gameboard to inital Status; # & _
    printsBoard(gameBoard);              // Prints the starting board

    // Outer Do while Performs the main game
    do
    {

        // Checks for Game Over condition
        if (incorrectGuess == 0)
        {
            cout << "play again? (y/n) ";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            // Clear everything if Replaying
            if (playAgain == 'Y')
            {
                cout << endl;
                incorrectGuess = 5;
                exhaustedGuess.clear();
                gameBoard.clear();
                answerKey.clear();
                inFile.clear();
                cin.clear();
                openLevel(inFile);
                gameBoard = readLevel(inFile);
                answerKey = gameBoard;
                gameBoard = replaceBoard(gameBoard);
                printsBoard(gameBoard);
                continue;
            }
            // Print message and end program if Not replaying
            if (playAgain == 'N')
            {
                cout << "\nThank you for playing CrossWord!\n";
                exit(0);
            }
            // Error Message for invalid entry
            if (playAgain != 'Y' || 'N')
            {
                cout << "\nInvalid entry!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        // Checks for Victory Condition
        if (gameBoard == answerKey)
        {
            cout << "Play again? (y/n) ";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            // Clear everything if Replaying
            if (playAgain == 'Y')
            {
                cout << endl;
                incorrectGuess = 5;
                exhaustedGuess.clear();
                gameBoard.clear();
                answerKey.clear();
                inFile.clear();
                cin.clear();
                openLevel(inFile);
                gameBoard = readLevel(inFile);
                answerKey = gameBoard;
                gameBoard = replaceBoard(gameBoard);
                printsBoard(gameBoard);
                continue;
            }
            // Print message and end program if not Replaying
            if (playAgain == 'N')
            {
                cout << "\nThank you for playing CrossWord!\n";
                exit(0);
            }
            // Print error message for invalid entry
            if (playAgain != 'Y' || 'N')
            {
                cout << "\nInvalid entry!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        // If statment Performs game if there is not game over?
        if (gameOver == false)
        {
            // Do-While loop performs the game
            do
            {
                cout << "\nEnter a letter:\n";
                cin >> guess;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                guess = toupper(guess);
                // Checks if letter is an alphabetic
                if (isalpha(guess))
                {
                    bool usedGuess = exhuastedGuesses(exhaustedGuess, guess);
                    bool onBoard = onTheBoard(answerKey, guess);
                    // Places guess on board if it is on the board
                    if (onBoard == true)
                    {
                        for (size_t i = 0; i < answerKey.size(); i++)
                        {
                            for (size_t j = 0; j < answerKey[i].size(); j++)
                            {
                                if (answerKey[i][j] == guess)
                                {
                                    gameBoard.at(i).at(j) = guess;
                                }
                            }
                        }
                        // Prints message if the guess was already used
                        if (usedGuess == true)
                        {
                            cout << "The letter is already guessed, try again!\n";
                        }
                    }
                    // Prints message if the guess wasn't on the board
                    if (onBoard == false)
                    {
                        // If the guess was used, prints message
                        if (usedGuess == true)
                        {
                            cout << "The letter is already guessed, try again!\n";
                        }
                        // If not on the board & guess !used yet print message and decrease guess
                        else
                        {
                            cout << "The letter is not on the board\n";
                            incorrectGuess--;
                        }
                    }
                }
                // Prints current number of guess left
                cout << "Remaining incorrect guesses: "
                     << incorrectGuess << "\n\n";
                // Stores used guess in vector
                exhaustedGuess.push_back(guess);
                // Prints current game board
                printsBoard(gameBoard);
                // Messages for win conditions
                // Prints message if game won
                if (gameBoard == answerKey)
                {
                    cout << "\nCongratulations! you solved the level!\n";
                }
                // Prints message if lost game
                if (incorrectGuess == 0)
                {
                    cout << "\nBetter luck next time!\n";
                }
            } while (false);
        }
    } while (!playAgainFlag);
}

/*
         FUNCTION_IDENTIFIER: Void function displays game logo
         parameters: None, Void function
         return value: Non-Returning; Prints to screen
*/
void displayLogo()
{
    cout << endl
         << setw(17) << "Welcome to\n\n"
         << setw(11) << "W\n"
         << setw(15) << "C R O S S\n"
         << setw(11) << "R\n"
         << setw(12) << "D\n\n";
}
/*
         FUNCTION_IDENTIFIER: Opens "level"(file) to play given user input
         given they are within the correct parameters.
         parameters: Pass by reference, ifstream variable(inFile)
         return value: Non-returning; Opens file being passed
*/
void openLevel(ifstream &inFile)
{
    int level = 0;
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
            inFile.open("level" + to_string(level) + ".txt");
            if (!inFile.is_open())
            {
                cout << "Level files could not be found!\n";
            }
            continue;
        }

    } while (!inFile.is_open());
    cout << endl;
}
/*
         FUNCTION_IDENTIFIER: Function reads the file contents and
         stores them into a 2D Vector, once done closes file.
         parameters: Pass by reference; ifstream(inFile)
         return value: Returns 2D vector with stored information
*/
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
/*
         FUNCTION_IDENTIFIER: Function replaces board with _'s
         parameters: Pass 2D vector
         return value: Returns 2D vector with certain contents
         replaced with _'s
*/
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
/*
         FUNCTION_IDENTIFIER: Function prints given board to the screen
         parameters: 2D vector
         return value: Non-Returning; Prints current board to screen
*/
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
/*
         FUNCTION_IDENTIFIER: Boolean Function checks that char is on the answer key
         returns true if it is else false
         parameters: 2D vector containing answerkey, char containing guess
         return value: Returns true if the guess is found; else returns false
*/
bool onTheBoard(vector<vector<char> > answerKey, char guess)
{
    for (size_t i = 0; i < answerKey.size(); i++)
    {
        for (size_t j = 0; j < answerKey[i].size(); j++)
        {
            if (answerKey[i][j] == guess)
            {
                return true;
            }
        }
    }
    return false;
}
/*
         FUNCTION_IDENTIFIER: Function checks vector to see if
         it contains the current guess being passed
         parameters: 1D vector containing used guesses,
         char containing the current guess to be checked
         return value: Returns true if vector contains guess; Else returns false
*/
bool exhuastedGuesses(vector<char> exhaustedGuess, char guess)
{
    for (size_t i = 0; i < exhaustedGuess.size(); i++)
    {
        if (guess == exhaustedGuess[i])
        {
            return true;
        }
    }
    return false;
}
