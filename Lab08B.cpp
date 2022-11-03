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

// Intro to Main code
int main()
{
    // varaible Declarations
    string prompt = "Enter a circle radius between 0.500000 and 20.500000 \n**";
    getDoubleInput(prompt, MINIMUM, MAXIMUM);
}

// Function Declaractions
double getDoubleInput(string prompt, double minimum, double maximum)
{
    // Call the checkFailure in order to do the whole cin.fail and within range stuff
    int input = 0;
    do
    {
        cout << prompt;
        cin >> input;
        checkFailure(input, MINIMUM, MAXIMUM);
        break;
    } while (true);
}
bool checkFailure(double input, double minimum, double maximum)
{
    bool passes = false;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong number";
    }
    //Fix this
    (input < minimum || input > maximum) ? (passes = false) && (cout << "Bad Answer\n") : (passes = true) && (cout << "Good answer\n");

    return passes;
}
