/*
          Name: Alvaro A. Cruz, #5005488379, 1005, Labo09A
          Description: Program displays calculations of two user
          inputted numbers given that they are within acceptable range
          Input:User inputs two numbers between certain parameters
          Output: Prints to screen two prompts for user input, along with 
          correct calculations for given inputs.
*/

// PreProcessor Directives
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Function Prototypes
double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
void getDoubleInputs(double &, double &);
void addSubtract(double &, double &);
void multiplyDivide(double &, double &);

// Const Variable Declaration;
const double MINIMUM = 0.5;
const double MAXIMUM = 20.5;

// Intro to main Code
int main()
{
    double input1 = 0.0;
    double input2 = 0.0;
    getDoubleInputs(input1, input2);
    double number1 = input1;
    double number2 = input2;
    addSubtract(input1, input2);
    multiplyDivide(number1, number2);
}

// Function Declaractions
/*
          FUNCTION_IDENTIFIER: Function asks user for integer value(input)
          parameters: String containing Prompt, Two doubles for Max and Minimum respectively
          return value: Function returns integer value(input)
*/
double getDoubleInput(string question, double minimum, double maximum)
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
bool checkFailure(double input, double minimum, double maximum)
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
        if (input > minimum || input < maximum)
        {
            valid = true;
            return valid;
            break;
        }
    } while (true);
}
// Function Declaractions
/*
          FUNCTION_IDENTIFIER: Function calls function to ask user for inputs and checks validity
          parameters: Two doubles for input(s) 
          return value: Void; Non-Returing
*/
void getDoubleInputs(double &input1, double &input2)
{
    string prompt1 = "Enter double between " +
                     to_string(MINIMUM) + " and " +
                     to_string(MAXIMUM) + "\n**";
    string prompt2 = "Enter another double between " +
                     to_string(MINIMUM) + " and " +
                     to_string(MAXIMUM) + "\n**";
    input1 = getDoubleInput(prompt1, MINIMUM, MAXIMUM);
    checkFailure(input1, MINIMUM, MAXIMUM);
    cout << endl;
    input2 = getDoubleInput(prompt2, MINIMUM, MAXIMUM);
    checkFailure(input2, MINIMUM, MAXIMUM);
}
// Function Declaractions
/*
          FUNCTION_IDENTIFIER: Function passes two number by reference
          and then both adds and subtracts them.
          parameters: Two doubles for input(s) 
          return value: Void; Non-Returing, Prints to screen
*/
void addSubtract(double &num1, double &num2)
{
    double number1 = num1;
    double number2 = num2;
    num1 = num1 + num2;
    cout << endl
         << fixed << setprecision(2)
         << number1 << " + " << number2 << " = " << num1 << endl;
    num2 = number1 - num2;
    cout << number1 << " - " << number2 << " = " << num2 << endl;
}
// Function Declaractions
/*
          FUNCTION_IDENTIFIER: Function passes two numbers by reference
          and then both multples and divides them
          parameters: Two doubles for input(s) 
          return value: Void; Non-Returing, Prints to screen
*/
void multiplyDivide(double &num1, double &num2)
{
    double number1 = num1;
    double number2 = num2;
    num1 = num1 * num2;
    cout << fixed << setprecision(2)
         << number1 << " * " << number2 << " = " << num1 << endl;
    num2 = number1 / num2;
    cout << number1 << " / " << number2 << " = " << num2 << endl;
}
