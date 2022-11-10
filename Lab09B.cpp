/*
          Name: Alvaro A. Cruz, #5005488379, 1005, Lab09B
          Description: Program displays various applications of
          overloaded functions, printing information to screen.
          Input:User inputs two integers and two strings
          Output: Displays addidtion and muliplication of both
          the integers and the strings.
*/

// Preprocessor Directives
#include <iostream>
#include <limits>

using namespace std;

// Fucntion Prototypes
int add(int, int);
string add(string, string);
int multiply(int, int);
string multiply(string, int);
void getDoubleInputs(int &, int &);
double getDoubleInput(string, int, int);
bool checkFailure(int, int, int);

// const variables
const int MINIMUM = 1;
const int MAXIMUM = 50;

// Intro to main code
int main()
{

    // Variable Declaration
    int number1 = 0;
    int number2 = 0;
    string firstString = " ";
    string secondString = " ";

    //Input Phase
    getDoubleInputs(number1, number2);
    cout << "\nEnter a string\n**";
    cin >> firstString;
    cout << "\nEnter another string\n**";
    cin >> secondString;
    cout << endl;

    //Output Phase
    cout << number1 << " + " << number2 << " = "
         << add(number1, number2) << endl
         << firstString << " + " << secondString << " = "
         << add(firstString, secondString) << endl
         << number1 << " * " << number2 << " = "
         << multiply(number1, number2) << endl
         << firstString << " * " << number1 << " ="
         << multiply(firstString, number1) << endl
         << secondString << " * " << number2 << " ="
         << multiply(secondString, number2) << endl;
}
// Function Declaractions
/*
          FUNCTION_IDENTIFIER: Function asks user for integer value(input)
          parameters: String containing Prompt, Two doubles for Max and Minimum respectively
          return value: Function returns integer value(input)
*/
double getDoubleInput(string question, int minimum, int maximum)
{
    bool valid = true;
    double input = 0;
    do
    {
        cout << question;
        cin >> input;
        valid = checkFailure(input, minimum, maximum);

    } while (!valid);
    return input;
}
/*
         FUNCTION_IDENTIFIER: Function checks user input is within acceptable range
         and doesn't fail cin.
         parameters: Three double values; user input, minimum, and maximum
         value for acceptable range.
         return value: Function returns boolean value dependent user input.
         If invalid, returns false Else returns true;
*/
bool checkFailure(int input, int minimum, int maximum)
{
    bool valid = true;
    do
    {
        if (cin.fail())
        {
            cout << "\nError: Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
            return valid;
            continue;
        }
        if (input < minimum || input > maximum)
        {
            cout << "\nError: Invalid input!\n";

            valid = false;
            return valid;
            continue;
        }
        if (input >= minimum || input <= maximum)
        {
            valid = true;
            return valid;
            break;
        }
    } while (true);
}
/*
          FUNCTION_IDENTIFIER: Function calls function to ask user for inputs and checks validity
          parameters: Two doubles for input(s)
          return value: Void; Non-Returing
*/
void getDoubleInputs(int &input1, int &input2)
{
    string prompt1 = "Enter an integer between " +
                     to_string(MINIMUM) + " and " +
                     to_string(MAXIMUM) + "\n**";
    string prompt2 = "Enter another integer between " +
                     to_string(MINIMUM) + " and " +
                     to_string(MAXIMUM) + "\n**";
    input1 = getDoubleInput(prompt1, MINIMUM, MAXIMUM);
    checkFailure(input1, MINIMUM, MAXIMUM);
    cout << endl;
    input2 = getDoubleInput(prompt2, MINIMUM, MAXIMUM);
    checkFailure(input2, MINIMUM, MAXIMUM);
}
/*
          FUNCTION_IDENTIFIER: Function sums two integer variables
          parameters: Two formal integer parameters
          return value: Returns the Sum of the two parameters
*/
int add(int num1, int num2)
{
    return num1 + num2;
}
/*
          FUNCTION_IDENTIFIER: Function concatenates two string variables
          parameters: Two formal string parameters
          return value: Returns the concatented string
*/
string add(string str1, string str2)
{

    return str1 + str2;
}
/*
          FUNCTION_IDENTIFIER: Function multiples two integer variables
          parameters: Two formal integer parameters
          return value: Returns the product of the two parameters
*/
int multiply(int num1, int num2)
{
    return num1 * num2;
}
/*
          FUNCTION_IDENTIFIER: Function "multiplies" a string variable
          given an integer.
          parameters: Two formal paramters, one string, one integer
          return value: Returns the concatented("multipled") string
*/
string multiply(string str1, int num1)
{
    int i = num1;
    string newString = " ";
    while (i--)
    {
        newString += str1;
    }
    return newString;
}
