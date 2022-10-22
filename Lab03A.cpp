/*
 Name: Alvaro A. Cruz, #5005488379, 1008, Lab#03A
 Description: Program takes in user input and selects & then prints
    the highest value via a If-Else Statement.
 Input: User Input 2 floating numbers & 2 Strings
 Output: Displays values inputted onto the screen along with
    statment stating which is the larger of the two
*/
//Preprocessor Directives
#include <iostream>

using namespace std;

//Intro to Main Code
int main() {

//Variable Declaration
    double firstNumber = 0.0;
    double secondNumber =0.0;
    string firstString = "";
    string secondString = "";

//1st Input Phase | For user inputted floats
    cout << "Enter a floating point number\n" << "**";
    cin >> firstNumber;
    cout << "\nEnter another floating point number\n" << "**";
    cin >> secondNumber;

//1st Output Phase | For Number
    cout << "\nYou entered " << firstNumber
    << " and " << secondNumber << endl;

//1st Processing Phase | If-Else Statement for Number Selection
        //Selecting & Printing out 1st Number if Largest
    if (firstNumber > secondNumber){
        cout << "The largest is " << firstNumber 
        << endl << endl;
        //Selecting & Printing 2nd Number if its Larger
    } else if (secondNumber > firstNumber){
        cout << "The largest is " << secondNumber 
        << endl << endl;
        //When equal Prints out either number
    } else if (firstNumber == secondNumber){
        cout << "The largest is " << firstNumber
        << endl << endl;
    }

//2nd Input Phase | For String(s)
    cout << "Enter a string\n" << "**";
    cin >> firstString;
    cout << "\nEnter a second string\n" << "**";
    cin >> secondString;

//2nd Output Phase | For string(s)
    cout << "\nYou entered " << "\"" << firstString 
    << "\"" << " and " << "\"" << secondString 
    << "\"\n";

//2nd Processing Phase| If-else statment for string selction
        //Selects & Prints 1st string if it has highest value
    if (firstString > secondString){
        cout << "The largest is " << "\""
        << firstString << "\"\n";
        //Selects & Prints 2nd String if it has highest value
    } else if (secondString > firstString){
        cout << "The largest is " << "\""
        << secondString << "\"\n";
        //Selects & Prints 1st String if String have equal value
    } else if (firstString == secondString){
        cout << "The largest is " << "\""
        << firstString << "\"\n";
    }

}
