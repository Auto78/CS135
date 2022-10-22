/*
	Name: Alvaro Cruz, 5005488379, 1005, Lab04A
	Description: Program printing numbers until it reaches the ending number
        by incrementing its value by the given value.
	Input: User inputs starting, ending, and incremental values
	Output: Prints starting number and all numbers up to ending number.
        Unless an invalid entry in which case, Prints error message and ends program.
*/

//Preprocessor Directories 
#include <iostream>
#include <limits>

using namespace std;

//Intro to main Code;
int main(){

//Decalring variables;
    int startingNumber = 0;
    int endingNumber = 0;
    int incrementValue = 0;

//Testing Output Phase;
//Grab the Starting Number
    cout << "Enter a starting number\n**";
    cin >> startingNumber;
    cout << endl;
//If-else statemtent to ensure cin works via cin.fail()
    if(cin.fail()){
    //Display Error message if failed test
	    cout << "Error: invalid entry." << endl;
    //This resets/clears the cin.fail state to working state
	    cin.clear();
    //This ignores cin buffer until either MAX limit or a newline is found
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //Returns 0(false) to program, ending it
         return 0;
    }
//Grab the Ending Number
    cout << "Enter an ending number\n**";
    cin >> endingNumber;
    cout << endl;
//Second If-else statemtent to ensure cin works via cin.fail()
    if(cin.fail()){
	    cout << "Error: invalid entry." << endl;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    } 
    /*Dislpay error message and exit program
    if End number is smaller than start */
    if (endingNumber < startingNumber){
        cout << "Error: end must be greater than start."
        << endl;
        return 0;
    }
//Grab the Incremental Value
    cout << "Enter a value to increment by\n**";
    cin >> incrementValue;
    cout << endl;
//Final If-else statemtent to ensure cin works via cin.fail()
    if(cin.fail()){
	    cout << "Error: invalid entry." << endl;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    }
    //counter variable
    int i = 0;
//OutPutPhase: While loop for printing out numbers;
    /*While flag variable i & starting number are <= to ending number
    Print starting number incrementing it by the incremental value each time*/
    while(i <= endingNumber && startingNumber <= endingNumber){
        cout << startingNumber << " ";
        startingNumber+=incrementValue;
        i++;
    }
    cout << endl;
}
