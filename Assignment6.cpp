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
#include <algorithm>

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
    ifstream inFile;             // Input file stream variable
    char guess = ' ';            // Letter to Check
    vector<char> exhaustedGuess; // Vector contains the used guesses
    int incorrectGuess = 5;      // Number of incorrect guess avaliable
    char playAgain = ' ';
    bool playAgainFlag = false;
    bool gameOver = false;
    //  Display Game Logo
    displayLogo();
   // Tracks what level is currently playing;
    openLevel(inFile);
    
    vector<vector<char> > gameBoard;// Vector conatians the level in a gameboard style

    gameBoard = readLevel(inFile);
    
    vector<vector<char> > answerKey = gameBoard;// This vector contains the answerkey before replacing the gameboard to only # & _
    
    gameBoard = replaceBoard(gameBoard);// Replacing the gameboard with inital Status; # & _
    printsBoard(gameBoard);

    // Asking user for letter to check
    // Fix this it Works but need to do error checking
    do
    {
         


        //Checks for ending game 
        if (incorrectGuess == 0)
        {
            gameOver = true;
            cout << "\nBetter luck next time!\n";
            
            if(gameOver == true){
            do
            {
              cout << "play again? (y/n)\n";
            cin >> playAgain;
            playAgain = toupper(playAgain);
                if(playAgain == 'Y')
                {
                    incorrectGuess = 5;
                    exhaustedGuess.clear();
                    gameBoard.clear();
                    inFile.clear();
                    gameBoard = readLevel(inFile);
                    gameBoard = replaceBoard(gameBoard);
                    playAgainFlag = true;
                    break;
                }
                if (playAgain == 'N')
                {
                    cout << "\nThank you for playing CrossWord!\n";
                    exit(0);
                    break;
                }
                if (playAgain != 'Y' || 'N')
                {
                    cout << "Invalid entry!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    continue;
                }  
            } while (true);
            
            
            }
        }
        if (gameBoard == answerKey)
        {
            cout << "\nCongratulations! you solved the level!\n";
            gameOver = true;
            do
            {
               cout << "Play again? (y/n) ";
                cin >> playAgain;
                playAgain = toupper(playAgain);
                if(playAgain == 'Y')
                {
                    incorrectGuess = 5;
                    exhaustedGuess.clear();
                    gameBoard.clear();
                    inFile.clear();
                    gameBoard = readLevel(inFile);
                    gameBoard = replaceBoard(gameBoard);
                    playAgainFlag = true;
                    break;
                }
                if (playAgain == 'N')
                {
                    cout << "Thank you for playing CrossWord!\n";
                    exit(0);
                    break;
                }
                if (playAgain != 'Y' || 'N')
                {
                    cout << "Invalid entry!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    continue;
                } 
            } while (true);
            
            if(gameOver == true){

                 
            }
                
        }

    
        // Main part of the game
    
        do
        {  
            cout << "\nEnter a letter:\n";
            cin >> guess;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            guess = toupper(guess);
            //Checks if letter is an alphebitc and then adds to the loop
            if (isalpha(guess))
            {   bool usedGuess = exhuastedGuesses(exhaustedGuess, guess);
                bool onBoard = onTheBoard(answerKey, guess);

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
                    //Printing stuff if the letter is not on the board
                    if (usedGuess == true)
                    {
                        cout << "The letter is already guessed, try again!\n";
                    }

                }
                //Prints info if its not on the board 
                if (onBoard == false)
                {
                    //Printing stuff if the letter is not on the board
                    if (usedGuess == true)
                    {
                        cout << "The letter is already guessed, try again!\n";
                    }
                    else{
                        cout << "The letter is not on the board\n";
                        incorrectGuess--; 
                    }          
                }    
                //Checks if its been gess then print
            }
            
            cout << "Remaining incorrect guesses: " << incorrectGuess << endl;
            cout << endl;
            exhaustedGuess.push_back(guess);
            printsBoard(gameBoard);

        } while (false);
        
    } while (!playAgainFlag);
    
    
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
        if (level <= 3 && level > 0)
        {
            inFile.open("level" + to_string(level) + ".txt");
        }
        if (level >= 4)
        {
            cout << "Level files could not be found!\n";
            continue;
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
//Checks if letter is on the board;
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
bool exhuastedGuesses(vector<char> exhaustedGuess , char guess)
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