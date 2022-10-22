/*
    Name: Alvaro Cruz, 5005488379, 1005, ASSIGNMENT 4
    Description: Program runs a Simple game of Nim verses a computer utilizing loops, Asks user u
    pon succesful run if they wish to replay, if they decide not to the game ends.
    Input: User inputs amount of matches to remove on their turn, if the wish to go first, and if they wish to replay
    Output: Prints current score alongside prompt to remove matches and if user wants to replay or go first
    */

// Preprocessor Directories
#include <iostream>
#include <limits>

using namespace std;

int main()
{

    // Varaiable Declaration
    string goFirst = "0";
    string playAgain = "0";
    int removeMatches = 0;
    int computerRemoveMatches = 0;
    bool turnPlayer = false;
    bool human = true;
    bool computer = false;
    bool gameOver = false;
    bool playAgainFlag = false;
    int matches = 21;

    // Ouput introduction and ask to go first
    cout << "The game of Nim. The player to remove the last match loses.\n";

    // PLAY AGAIN LOOP
    do
    {
        if (gameOver == true)
        {
            cout << "\nWould you like to play again? (Y/N): ";
            cin >> playAgain;
            // Ensures length of response is one character
            if (playAgain.length() != 1)
            {
                cout << "\nPlease, answer Y or N.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Upon succesful input checks to see if it plays again
            // If player plays again resets variables
            if (playAgain == "y")
            {
                matches = 21;
                gameOver = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (playAgain == "Y")
            {
                matches = 21;
                gameOver = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // If player doesn't play again terminate program
            if (playAgain == "n")
            {
                exit(0);
                break;
            }
            if (playAgain == "N")
            {
                exit(0);
                break;
            }
            // If invalid input prints error message and asks again
            if (playAgain != "y" || "Y" || "n" || "N")
            {
                cout << "\nPlease, answer Y or N.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
        // PLAYER SELECTION LOOP
        do
        {
            // Resets play again flag should player want to play again.
            playAgainFlag = false;
            // Ask To Go First Loop

            cout << "\nWould you like to go first? (Y/N): ";
            cin >> goFirst;

            if (goFirst.length() != 1)
            {
                cout << "\nPlease, answer Y or N.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (goFirst == "y")
            {
                turnPlayer = human;
                break;
            }
            if (goFirst == "Y")
            {
                turnPlayer = human;
                break;
            }
            if (goFirst == "n")
            {
                turnPlayer = computer;
                break;
            }
            if (goFirst == "N")
            {
                turnPlayer = computer;
                break;
            }
            if (goFirst != "y" || "Y" || "n" || "N")
            {
                cout << "\nPlease, answer Y or N.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        } while (true);

        // MAIN GAMEPLAY LOOP
        do
        {
            /// HUMAN GAMEPLAY LOOP; will trigger if the turn player is a human and matches remain
            if (turnPlayer == human && matches > 1)
            {
                cout << "\nPlayer turn - matches: ";
                // Loop for printing matches
                for (int i = 1; i <= matches; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (j % 5 == 0)
                        {
                            cout << "|";
                        }
                    }
                    if (i % 5 == 0)
                    {
                        cout << " ";
                    }
                }

                cout << endl;
                // Do While loop will contiune until a valid input is recived
                do
                {
                    cout << "\nRemove (1 - 3):";
                    cin >> removeMatches;

                    // Checking removeMatches is valid and within valid inputs
                    if (cin.fail())
                    {
                        cout << "Please, type 1, 2, or 3 as your response.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    // Checking the input is within acceptable range
                    if (removeMatches < 1)
                    {
                        cout << "Must remove at least one match.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (removeMatches > 3)
                    {
                        cout << "Cannot remove more than three matches.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    // Updates remaining matches after acceptable input is recived

                    matches -= removeMatches;
                    turnPlayer = computer;

                    break;
                } while (true);
                // End game if matches is set to one in this case the Player won
                if (matches == 1)
                {
                    cout << "\nComputer turn - Matches: ";
                    // Loop for printing matches
                    for (int i = 1; i <= matches; i++)
                    {
                        for (int j = 0; j < 5; j++)
                        {
                            if (j % 5 == 0)
                            {
                                cout << "|";
                            }
                        }
                        if (i % 5 == 0)
                        {
                            cout << " ";
                        }
                    }
                    // Once game over is met print final game state
                    gameOver = true;
                    cout << endl;
                    cout << "\nGame over - Player wins.\n";
                    continue;
                }
            }
            // COMPUTER GAMEPLAY LOOP; will trigger if turnplayer is the computer and matches remain
            if (turnPlayer == computer && matches > 1)
            {
                // print current game settings for computer turn
                cout << "\nComputer turn - matches: ";
                // loop for printing matches
                for (int i = 1; i <= matches; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (j % 5 == 0)
                        {
                            cout << "|";
                        }
                    }
                    if (i % 5 == 0)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
                // Logic behind computer removing matches
                if (matches % 4 == 0)
                {
                    computerRemoveMatches = 3;
                }
                else if (matches % 4 == 1 || matches % 4 == 2)
                {
                    computerRemoveMatches = 1;
                }
                else if (matches % 4 == 3)
                {
                    computerRemoveMatches = 2;
                }

                cout << "\nComputer removes " << computerRemoveMatches << "." << endl;
                // Update current matches
                matches -= computerRemoveMatches;

                // Update turnplayer
                turnPlayer = human;
                continue;
            }
            // Once matches reaches 1; Gameover; Declare victory to computer
            if (matches == 1)
            {
                cout << "\nPlayer Turn - Matches: ";
                // Loop for printing matches
                for (int i = 1; i <= matches; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        if (j % 5 == 0)
                        {
                            cout << "|";
                        }
                    }
                    if (i % 5 == 0)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
                gameOver = true;
                cout << "\nGame Over - Computer Wins.\n";
                continue;
            }

            break;
            // Main gameplay loop will continue until game over is acheived
        } while (!gameOver);
    } while (!playAgainFlag);
}
