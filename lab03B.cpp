/*
 Name: Alvaro A. Cruz, #5005488379, 1008, Lab#03B
 Description: Program takes in user char input, selects & then prints
    grade range dependent on letter Grade via switch case
 Input: User Input letter Grade in the form of a char
 Output: Displays grade range for valid chars and 
    Error message for invalid inputs
*/

//Preprocessor Directives
#include <iostream>

using namespace std;

//Intro to main code
int main() {

//Varaible Declaration
    char letterGrade = ' ';

//Input Phase
    cout << "Enter a letter grade\n" << "**";
    cin >> letterGrade;

//Processing/Output Phase

    //Switch Case for printing range based on letter grade
    switch (letterGrade){
        //Takes Upper and Lower case letter Grade
        case 'A':
        case 'a':
            //Prints Grade Range dependent on letter Grade
            cout << "\nGrade range is 90 - 100\n";
            break; //Break For Next Case
        case 'B':
        case 'b':
            cout << "\nGrade range is 80 - 89.99\n";
            break;
        case 'C':
        case 'c':
            cout << "\nGrade range is 70 - 79.99\n";
            break;
        case 'D':
        case 'd':
            cout << "\nGrade range is 60 - 69.99\n";
            break;
        case 'F':
        case 'f':
            cout << "\nGrade range is 0 - 59.99\n";
            break;
        //Return Default Error Messsage for invalid Chars
        default:
            cout << "\nError: '" << letterGrade << "' "
            << "is not a valid letter grade\n";
    }
}
