/*
	Name: Alvaro Cruz, 5005488379, 1005, Lab04B
	Description: Program uses loops to calculate and print the sum of 
	even and odd numbers from user input given an acceptable range. Prints
	an error message if not within range or invalid input
	Input: User inputs a count number between 2-10000
	Output: Prints the sum in the following manner 
		Sum of even numbers: (sum of even numbers)
		Sum of odd numbers:  (sum of odd numbers)
*/

// Preprocessor Directories
#include <iostream>
#include <limits>

using namespace std;

int main(){

//Variable Declaration
	int countNumber = 0;
	int totalEvenNumbers = 0;
	int totalOddNumbers = 0;
	int oddNumbers = 1;

//Input Phase
	//Do Loop for input Repeats upon failure continues upon success
	do
	{
		cout << "Enter a count between 2 and 10000\n**";
		cin >> countNumber;
		cout << endl;

		//Checks input success & Prints error message if fail
		if (cin.fail())
		{
			//Prints Error Message
			cout << "Error: Invalid entry, please retry\n";
			 // Resets the cin.fail state to working
			cin.clear();
			// Cin ignores the MAX limit or until a newline is found
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; //continues with Do loop
		}
		//Checks if count is within acceptable range
		if (countNumber <= 1 || countNumber > 10000)
		{
			//Prints Error Message & clears input for invalid Entry
			cout << "Error: Invalid entry, Please retry\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue; //continues with Do Loop
		}
		break;

//Processing Phase
	} while (true);
	//For loop from 1-Count Number
	for (int evenNumbers = 1; evenNumbers <= countNumber; evenNumbers++)
	{ 
		// Checking if EvenNumbers are even
		if (evenNumbers % 2 == 0) 
		{
			//Adds up evenNumbers into Total
			totalEvenNumbers += evenNumbers;
		}
	}
	//While loop from 1-count number
	while (oddNumbers <= countNumber)
	{	
		//Checking if OddNumbers are odd
		if (oddNumbers % 2 != 0)
		{
			//Add up oddNumbers into Total
			totalOddNumbers += oddNumbers;
		}
		//Increment & repeat until reach countNumber
		oddNumbers++;
	}

//Output Phase
	//Print out results
	cout << "Sum of even numbers: " << totalEvenNumbers << endl;
	cout << "Sum of odd numbers:  " << totalOddNumbers << endl;

}
