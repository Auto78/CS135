/*
Name: Alvaro Cruz, #5005488379, 1008, Lab2A
Description: Program that converts a value from degrees to radians then 
calcutations and displays the sin, cosine, and tangent using cmath functions.
Input: Inital Angle Value in degrees
Output: The converted radian value and trigonometic values for the following
sin ,cosine, and tangent.
*/

//Preprocessor Diricetes
#include <iostream>
#include <cmath>
using namespace std;

//Delcaring Const Varibales
    const double PI = 3.141592;

//Beginning of Main Program
int main() {

//Variable Declaration;
    double angle = 0.0;
    double radians = 0.0;
    double sinValue = 0.0;
    double cosValue = 0.0;
    double tanValue = 0.0;
//Input Phase;
    cout << "Enter an angle value, in degrees\n"
    << "**";
    cin >> angle;
    cout << endl;
    //Converting angles to Radians and Trigonometic Values
    radians = (angle*PI)/180;
    sinValue = sin(radians);
    cosValue = cos(radians);
    tanValue = tan(radians);
//Output Phase;
    //Display Converted Radian Value;
    cout << angle << " degrees = " << radians << " radians\n";
    //Display Trigonmetic Function Values;
    cout << "sin(" << angle << ") = " << sinValue << endl;
    cout << "cos(" << angle << ") = " << cosValue << "\n";
    cout << "tan(" << angle << ") = " << tanValue << "\n";

}
