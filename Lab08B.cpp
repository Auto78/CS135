/*
          Name: Alvaro A. Cruz, #5005488379, 1005, Labo08B
          Description:
          Input:
          Output:
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
const double PI = 3.1415;
const double MINIMUM = 0.5;
const double MAXIMUM = 20.5;
bool valid = true;

// Intro to Main code
int main()
{
    // varaible Declarations
    string prompt = "Enter a circle radius between 0.500000 and 20.500000 \n**";

    double radius = getDoubleInput(prompt, MINIMUM, MAXIMUM);
    double circumferenceTwo = circumference(radius);
    double areaTwo = area(radius);
    cout << fixed << setprecision(2)
         << "Radius: " << radius << endl
         << "Circumference: " << circumferenceTwo << endl
         << "Area: " << areaTwo << endl;
}

// Function Declaractions
double getDoubleInput(string question, double minimum, double maximum)
{
    // Call the checkFailure in order to do the whole cin.fail and within range stuff
    double input = 0;
    do
    {
        cout << question;
        cin >> input;
        checkFailure(input, minimum, maximum);
        continue;
    } while (!valid);
    return input;
}
bool checkFailure(double input, double minimum, double maximum)
{
    do
    {
        if (cin.fail() || input < minimum || input > maximum)
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
        else
        {
            valid = true;
            return valid;
            break;
        }
    } while (true);
}
double circumference(double value)
{
    double circleCircumference = 2 * PI * value;
    return circleCircumference;
}
double area(double value)
{
    double circleArea = PI * pow(value, 2);
    return circleArea;
}
