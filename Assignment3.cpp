/*
	Name: Alvaro Cruz, 5005488379, 1005, ASSIGNMENT 3
	Description: Program that takes in user information and prints data to maintain,lose, &, gain weight.
	Input: User input; age, weight, height, gender(m/f), & activity level
	Output: Prints average calories to maintain, lose, & gain weight to screen alongside message
*/

// Preprocessor Directories
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main()
{

	// variable Declarartion
	int age = 0;
	int weight = 0;
	int height = 0;
	int activityLevel = 0;
	char gender = ' ';
	float bmr = 0.0;
	float amr = 0.0;
	float activityFactor = 0.0;


	// Output Of thingy
	cout << endl
		 << ".@  @, (&           .(%(.               *#(,              .   \n"
		 << "(@  @( &@      .@@@@@@@@@@@@@#     @@@@@@@@@@@@@#        @@@. \n"
		 << "(@  @( &@    /@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@    .@@@@@,\n"
		 << "(@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
		 << "(@@@@@@@@   @@@@@@@@@@@@@@@@  .@@@@@@@@@@@@@@@@@@@@@(  .@@@@@,\n"
		 << " @@@@@@@#   @@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@/  .@@@@@,\n"
		 << "    @@.     &@@@@@@@@@@@.   @@   @@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
		 << "    @@.                   @@@@@   @@@@                 .@@@@@,\n"
		 << "    @@.       #@@@@@@@@@@@@@@@@@   &#  .@@@@@@@@@@     .@@@@@,\n"
		 << "    @@.         @@@@@@@@@@@@@@@@@.    %@@@@@@@@@#         ,@@,\n"
		 << "    @@.           @@@@@@@@@@@@@@@@,  @@@@@@@@@%           ,@@.\n"
		 << "    @@.             %@@@@@@@@@@@@@@@@@@@@@@@.             ,@@,\n"
		 << "    @@.                %@@@@@@@@@@@@@@@@@,                ,@@,\n"
		 << "    @@.                    &@@@@@@@@@,                    ,@@,\n"
		 << "    @@.                     &@@@@@,                       ,@@,\n"
		 << endl
		 << "             Welcome to the Calorie Calculator App\n";

	// Input Phase
	// Age Section
	cout << "To get started, enter your age in years:\n";
	cin >> age;
	// Testing cin.fail() validity for age
	if (cin.fail())
	{
		cout << "Invalid Age!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}
	// Error Message if Age isn't within acceptable Limts
	if (age < 10 || age > 79)
	{
		cout << "Age must be between 10 and 79 years!\n";
		exit(0);
	}

	// Weight Section
	cout << "Enter weight in lbs:\n";
	cin >> weight;
	// Testing cin.fail() validity for weight
	if (cin.fail())
	{
		cout << "Invalid weight!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}
	// Error message if weight isn't within acceptable limts
	if (weight < 50 || weight > 400)
	{
		cout << "Weight must be between 50 lbs and 400 lbs!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}

	// Height section
	cout << "Enter height in inches:\n";
	cin >> height;
	// Testing cin.fail() validity for height
	if (cin.fail())
	{
		cout << "Invalid height!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}
	// Error message if height isn't within acceptable limits
	if (height < 40 || height > 90)
	{
		cout << "Heigh must be between 40\" and 90\"!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}

	// Gender Section
	cout << "Enter 'M' for male or 'F' for female:\n";
	cin >> gender;
	// Switch Case to Test and Accept valid inputs
	switch (gender)
	{
	// Set BMR given male or Female
	case 'm':
	case 'M':
		bmr = 65 + (6.2 * weight) + (12.7 * height) - (6.8 * age);
		break;
	case 'f':
	case 'F':
		bmr = 655 + (4.3 * weight) + (4.3 * height) - (4.7 * age);
		break;
		// Print error message and terminate program upon invalid entry
	default:
		cout << "Invalid entry!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
	}

	// Activity Level Section
	cout << "Select activity level:\n"
		 << "1. Inactive: little to no exercise.\n"
		 << "2. Lightly active: Exercising 1 - 3 days/week\n"
		 << "3. Moderately active: Exercising 3 - 5 days/week\n"
		 << "4. Active: Exercising 6 - 7 days/week\n"
		 << "5. Very active: Exercising hard 6 - 7 days/week\n";
	cin >> activityLevel;

	// Switch Case for Setting AMR given Activity level
	switch (activityLevel)
	{
	case 1:
		activityFactor = 1.2;
		break;
	case 2:
		activityFactor = 1.375;
		break;
	case 3:
		activityFactor = 1.55;
		break;
	case 4:
		activityFactor = 1.725;
		break;
	case 5:
		activityFactor = 1.9;
		break;
	default:
	cout << "Invalid activity level!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		exit(0);
		break;
	}
	// Calculation Variable Declarations
	amr = bmr * activityFactor;
	float caloriesToGainOrLose = amr * 20 / 100;
	float weightLossAmr = amr - caloriesToGainOrLose;
	float weightGainAmr = amr + caloriesToGainOrLose;
	// Outphase
	cout << "To maintain your current weight, you need "
		 << "to consume an average of " << round(amr) << " calories/day.\n";
	cout << "To lose weight, you need to consume an average of "
		 << round(weightLossAmr) << " calories/day.\n";
	cout << "To gain weight, you need to consume an average of "
		 << round(weightGainAmr) << " calories/day.\n"
		 << endl;
	cout << "*Disclaimer: always consult your doctor before "
		 << "committing to a diet plan\n";

	return 0;
}
