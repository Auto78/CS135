/*
		  Name: Alvaro A. Cruz, #5005488379, 1005, Labo08A
		  Description: Implements various user defined functions to practice
		  input, output, and creating said functions.
		  Input: User inputs value and symbol given functions.
		  Output: Prints upside-down and righside-up triangle in
		  accordance to inputted value and symbol.
*/
// Preprocessor Directives
#include <iostream>

using namespace std;

// Function prototypes

int getIntegerInput(string, int, int);

char getCharacterInput(string);

void writeUpsideDownTriangle(int, char);

void writeRightsideUpTriangle(int, char);

// Intro to Main Code
int main()
{
	// Minimums/maximums
	const int MIN = 2;
	const int MAX = 20;
	// Prompt for integer input
	string prompt1 = "Enter a count between " +
					 to_string(MIN) + " and " +
					 to_string(MAX) + "\n**";
	// Prompt for character input
	string prompt2 = "\nEnter a character\n**";

	// Get size of triangle
	int size = getIntegerInput(prompt1, MIN, MAX);
	// Get character to use when printing triangle
	char character = getCharacterInput(prompt2);

	// Write both triangles
	writeUpsideDownTriangle(size, character);
	writeRightsideUpTriangle(size, character);
	cout << endl;

	// Terminate the program
	return 0;
}

// Function definitions
/*
		  FUNCTION_IDENTIFIER: Prompts user for value within range.
		  parameters: Pass string for prompt, integers for minimum and maximum range
		  return value: Returns prompted integer within acceptable range
*/
int getIntegerInput(string ask, int lowest, int highest)
{
	int value = 0;
	// Do-While loop controls validates and accepts correct input.
	do
	{
		// Will prompt user while invalid input
		cout << ask;
		cin >> value;
		// If statments ensure correct conditions are met
		if (cin.fail())
		{
			cout << "Error: Invalid entry, please retry\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (value <= lowest || value > highest)
		{
			cout << "Error: Invalid entry, please retry\n";
			continue;
		}
		break;
	} while (true);
	return value;
}
/*
		  FUNCTION_IDENTIFIER: Prompts user for char
		  parameters: Passes string value for prompt
		  return value: Returns accepted char.
*/
char getCharacterInput(string ask2)
{
	char logo = ' ';
	do
	{
		cout << ask2;
		cin >> logo;
		break;
	} while (true);
	return logo;
}
/*
		  FUNCTION_IDENTIFIER: Prints upside-down triangle given a value and symbol.
		  parameters: Integer value called number and char value called logo
		  return value:  No return Value; Prints triangle to screen
*/
void writeUpsideDownTriangle(int number, char logo)
{
	cout << endl;
	// Outer for loop controls spaces in between rows
	for (int i = number; i >= 1; --i)
	{
		// Inner for loop controls whats printed
		for (int j = 1; j <= i; ++j)
		{
			cout << logo;
		}
		cout << endl;
	}
}
/*
		  FUNCTION_IDENTIFIER: Prints Rightside-up triangle given a value and symbol.
		  parameters: Integer value called number2 and char value called symbol
		  return value: No Return Value; Prints trianlge to screen.
*/
void writeRightsideUpTriangle(int number2, char symbol)
{
	// Outer for loop controls spaces in between rows
	for (int i = 1; i <= number2; ++i)
	{
		// Inner for loop controls whats printed
		for (int j = 1; j <= i; ++j)
		{
			cout << symbol;
		}
		cout << endl;
	}
}
