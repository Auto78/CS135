/*
Name: Alvaro Cruz, #5005488379, 1008, Lab10B
Description:
Input:
Output:
*/

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Function Prototypes
void openFile(ifstream &, string);
void readFile(ifstream&, PurchaseType[]);
void printPurchaseData(PurchaseType[], int);

// Structs
struct PurchaseType
{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
};

// Intro to main code
int main()
{
    ifstream inFile;
    string prompt = "Enter a file name\n**";
    openFile(inFile, prompt);
}

/*
          FUNCTION_IDENTIFIER: Function prompts user for file name
          and then opens the file.
          parameters: ifstream and string for the prompt
          return value: Void: Non-Returning
*/

void openFile(ifstream &inFile, string prompt)
{
    string fileName;
    do
    {
        cout << prompt;
        getline(cin, fileName);
        inFile.open(fileName);
        if (!inFile.is_open())
        {
            cout << "\nError: Invalid File\n";
            continue;
        }
        break;
    } while (true);
}
