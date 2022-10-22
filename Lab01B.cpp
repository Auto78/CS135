/*
          Name: Alvaro Cruz, #5005488379, 1008, Lab #1B
          Description: Program prompting user for value input and performing
          various arithmetic on said input.
          Input: Two Integers and Two Doubles.
          Output: Solutions to addiction, subtraction, Multiplication,
          division, and Modulus functions, using the user input.
*/

//Preprocessor Directives
#include <iostream>
#include <iomanip>

using namespace std;

//Main intro to Code
int main ()
 {
//Variable Declaration/Initalization
    long value1 = 0;
    long value2 = 0;
    double value3 = 0.0;
    double value4 = 0.0;

    int solution1 = 0;
    int solution2 = 0;
    long solution3 = 0;
    int solution4 = 0;
    int solution5 = 0;
    double solution6 = 0.0;

//First Input Phase
    //Gather First Value
    cout << "Enter an integer\n";
    cout << "**";
    cin >> value1;
    cout << endl;

    //Gather Second Value
    cout << "Enter another integer\n";
    cout << "**";
    cin >> value2; 
    cout << endl;

//First Variable Arithmetic
    solution1 = value1 + value2;
    solution2 = value1 - value2;
    solution3 = value1 * value2;
    solution4 = value1 / value2;
    solution5 = value1 % value2;


//First Output Phase
    cout << value1 << " + " << value2 
    << " = " << solution1 << endl;
    cout << value1 << " - " << value2 
    << " = " << solution2 << endl;
    cout << value1 << " * " << value2;
    cout  << " = " << solution3 << endl;
    cout << value1 << " / " << value2
    << " = " << solution4 << endl;
    cout << value1 << " % " << value2 
    << " = " << solution5 << endl;
    cout << endl;

//Second Input Phase
    //Gather Third Value
    cout << "Enter a double\n";
    cout << "**";
    cin >> value3;
    cout << endl;

    //Gather Fourth Value
    cout << "Enter another double\n";
    cout << "**";
    cin >> value4;
    cout << endl;

//Second Variable Arithmetic
    solution6 = value3 / value4;

//TESTING
    cout << value3 << " / " << value4 
    << " = " << solution6 << endl;

}
