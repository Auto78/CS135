/*
Name: Alvaro Cruz, #5005488379, 1008, Lab10A
Description: Simple Program to understand Struct Basics:
    Adding user inputted data into corressponding struct elements
    and printing said elements to the screen.
Input: User Inputs students first and last name and grade.
Output: Prints user inputed data on the screen.
*/

// Preprocessor Directives
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Structs
struct studentType
{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};

// Function Protoypes
void getStudentData(studentType &);
void getLetterGrade(studentType &);
void printStudentData(studentType);

// Intro to main code;
int main()
{

    // Instance of Struct
    studentType kid;
    //Functions to gather and print struct data
    getStudentData(kid);
    getLetterGrade(kid);
    printStudentData(kid);
}

// Intro to user Defined Functions

/*
          FUNCTION_IDENTIFIER: Asks user for data and places data into corressponding struct
          parameters: Struct by reference
          return value: Non-Returning: Prints to Screen, Places data in struct
*/
void getStudentData(studentType &kid)
{
    string firstName = " ";
    string lastName = " ";
    int grade = 0;

    cout << "Enter a first name\n**";
    getline(cin, firstName);
    cout << endl;

    cout << "Enter a last name\n**";
    getline(cin, lastName);
    cout << endl;

    do
    {
        cout << "Enter a grade\n**";
        cin >> grade;

        if (cin.fail() || grade < 0 || grade > 4)
        {
            cout << "\nError: Invalid grade\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    } while (true);
    cout << endl;

    kid.firstName = firstName;
    kid.lastName = lastName;
    kid.grade = grade;
}

/*
          FUNCTION_IDENTIFIER: Assignes lettergrade to kid based on grade in struct
          parameters: Struct By Reference
          return value: Non-Returning: Prints to screen
*/
void getLetterGrade(studentType &kid)
{
    switch (kid.grade)
    {
    case 0:
        kid.letterGrade = 'F';
        break;
    case 1:
        kid.letterGrade = 'D';
        break;
    case 2:
        kid.letterGrade = 'C';
        break;
    case 3:
        kid.letterGrade = 'B';
        break;
    case 4:
        kid.letterGrade = 'A';
        break;
    }
}
/*
          FUNCTION_IDENTIFIER: Prints data entered in kid struct
          parameters: Struct 
          return value: Non-returing: Prints to Screen
*/
void printStudentData(studentType kid)
{
    cout << "Data Entered\n"
         << setw(19) << "student.firstname" << setw(5) << "= " << kid.firstName << endl
         << setw(18) << "student.lastname" << setw(6) << "= " << kid.lastName << endl
         << setw(15) << "student.grade" << setw(9) << "= " << kid.grade << endl
         << setw(21) << "student.letterGrade" << " = " << kid.letterGrade << endl;
}
