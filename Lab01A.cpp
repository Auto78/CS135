/*
Name: Alvaro Cruz, #5005488379, 1008, Lab01
Description: Program that calculates the value of specific
formulas and displays the output
Input: None
Output: Formulas and their respective solutions
*/

//Preprocessor Directives
#include <iostream>
#include <iomanip>
using namespace std;

//Declaring Constants
    const int NUMBER1 = 5;
    const int NUMBER2 = 2;
    const double NUMBER3 = 5.0;
    const double NUMBER4 = 2.0;

//Main Intro to code
int main()
{
//Declaring/Initalzing Variables
    int answer1 = NUMBER1 + NUMBER2;
    int answer2 = NUMBER1 - NUMBER2;
    int answer3 = NUMBER1 * NUMBER2;
    int answer4 = NUMBER1 / NUMBER2;
    int answer5 = NUMBER1 % NUMBER2;
    double answer6 = NUMBER3 / NUMBER4;

 //Output Code
    cout << NUMBER1 << " + " << NUMBER2 << 
    " = " << answer1 << endl;
    cout << NUMBER1 << " - " << NUMBER2 <<
    " = " << answer2 << endl;
    cout << NUMBER1 << " * " << NUMBER2 <<
    " = " << answer3 << endl;
    cout << NUMBER1 << " / " << NUMBER2 << 
    " = " << answer4 << endl;
    cout << NUMBER1 << " % " << NUMBER2 <<
    " = " << answer5 << endl;
    cout << fixed << setprecision(1) << showpoint 
    << NUMBER3 << " / " << NUMBER4 <<
    " = " << answer6 << endl;
}
