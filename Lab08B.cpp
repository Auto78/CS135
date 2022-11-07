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
#include <limits>
#include <cmath>

using namespace std;

// Function Prototypes
double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
double circumference(double);
double area(double);

// Const variable Declarations
const double PI = 3.14159;
const double MINIMUM = 0.5;
const double MAXIMUM = 20.5;

// Intro to Main code
int main()
{
    // Variable Declarations
    string prompt = "Enter a circle radius between 0.500000 and 20.500000 \n**";
    double radius = getDoubleInput(prompt, MINIMUM, MAXIMUM);
    double circumferenceTwo = circumference(radius);
    double areaTwo = area(radius);

    // Output Phase
    cout << fixed << setprecision(2)
         << "\nRadius: " << radius
         << "\nCircumference: " << circumferenceTwo
         << "\nArea: " << areaTwo << endl;
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
            cout << "\nError: Invalid radius!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
            return valid;
            continue;
        }
        if (input < minimum || input > maximum)
        {
            cout << "\nError: Invalid radius!\n";

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
/*
         FUNCTION_IDENTIFIER: Function Calculates circumference given radius value.
         parameters: Double value for radius
         return value: Returns calculated circumference of circle
*/
double circumference(double value)
{
    double circleCircumference = 2 * PI * value;
    return circleCircumference;
}
/*
         FUNCTION_IDENTIFIER: Calculates Area given radius value
         parameters: double Value for radius
         return value: Returns calculated Area of circle
*/
double area(double value)
{
    double circleArea = PI * pow(value, 2);
    return circleArea;
}