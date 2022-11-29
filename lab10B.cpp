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
    
}
