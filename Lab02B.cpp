/*
Name: Alvaro Cruz, #5005488379, 1005, Lab02B
Description:Program that finds circumference & area of a circle,
given the radius.
Input: User inputs radius of a circle.
Output: Outputs the Radius,Circumference,
and Area values in a table.
*/

//Preprocessor Directives
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Declaring Const Variables;
    const float PI = 3.141592;

//Intro to Main Code;
int main(){
    //Declaring Variables;
    string row = "+--------+---------------+---------+\n";
    string topics = "| radius | circumference | area    |\n"; 
    double radius = 0.0;
    float circumference = 0.0;
    float area = 0.0;
//Input Phase;
    cout << "Enter the radius of a circle\n" << "**";
    cin >> radius;
    cout << endl;
    //Calculating Circumference and Area;
    circumference = 2*PI*radius;
    area = PI*pow(radius,2);
//Output Phase;
    //First Row;
    cout << row;
    //Topic Section;
    cout  << topics;
    //Second Row;
    cout << row;
    //Results Section;
    cout << left << fixed << setprecision(2) 
    << "| " << setw(7) << radius //Radius Section
    << "| " << setw(14) << circumference // Circumference Section
    << "| " << setw(8) << area //Area Section
    << "|\n";
    //Third Row;
    cout << row << endl;
}
