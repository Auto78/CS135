/*
Name: Alvaro Cruz, #5005488379, 1008, Lab10B
Description: Function uses substring, find, files, and structs to gather information,
store into array of struct type, and print information to screen all via functions.
Input: User inputs file to be open
Output: Prints information on screen neatly on a table.
*/

// Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

using namespace std;

// Structs
struct PurchaseType
{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
};

// Function Prototypes
void openFile(ifstream &, string);
void readFile(ifstream &, PurchaseType[]);
void printPurchaseData(PurchaseType[], int);
void printTable();

// constants
const int ARRAY_SIZE = 11;

// Intro to main code
int main()
{
    int fileSize = 10;
    ifstream inFile;
    string prompt = "Enter file name\n**";
    PurchaseType purchases[ARRAY_SIZE];
    openFile(inFile, prompt);
    readFile(inFile, purchases);
    printPurchaseData(purchases, fileSize);
}

/*
        FUNCTION_IDENTIFIER: Ask user for file to open
        parameters: ifstream by reference and string for the prompt
        return value: Non-Returning
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
/*
    FUNCTION_IDENTIFIER: Reads the file 
    parameters: ifstream by reference and arrray of stuct type
    return value: Non-Returning
*/
void readFile(ifstream &inFile, PurchaseType purchases[])
{
    int numberOfRows = 0;

    while (!inFile.eof())
    {
        string tempString = "";
        while (getline(inFile, tempString))
        {
            int locationComma = tempString.find(',');

            purchases[numberOfRows].customerID = tempString.substr(0, locationComma);

            // Product Name
            tempString = tempString.substr(locationComma + 1, tempString.length());
            locationComma = tempString.find(',');
            purchases[numberOfRows].productName = tempString.substr(0, locationComma);

            // Prices
            tempString = tempString.substr(locationComma + 1, tempString.length());
            locationComma = tempString.find(',');
            purchases[numberOfRows].price = stod(tempString.substr(0, locationComma));

            // Quantity
            tempString = tempString.substr(locationComma + 1, tempString.length());
            locationComma = tempString.find(',');
            purchases[numberOfRows].qtyPurchased = stoi(tempString.substr(0, locationComma));

            // tax
            tempString = tempString.substr(locationComma + 1, tempString.length());
            locationComma = tempString.find(',');
            purchases[numberOfRows].taxRate = stod(tempString.substr(0, locationComma));

            numberOfRows++;
        }
    }
    inFile.close();
}

/*
        FUNCTION_IDENTIFIER: Prints all the data to screen
        parameters:array of declared struct type and integer
        return value: Non-Returning
*/
void printPurchaseData(PurchaseType purchases[], int fileSize)
{
    double total = 0.0;
    double sumTotal = 0.0;
    double averageTotal = 0.0;
    int uniqueId = 0;
    printTable();
    for (int i = 0; i < fileSize; i++)
    {
        cout << "|" << setw(12) << purchases[i].customerID << " | ";
        cout << setw(12) << purchases[i].productName << " |";
        cout << fixed << setprecision(2) << setw(6) << purchases[i].price << " | ";
        cout << setw(8) << purchases[i].qtyPurchased << " | ";
        cout << setw(8) << purchases[i].taxRate * 100 << " |";
        total = ((purchases[i].price * purchases[i].qtyPurchased) * (purchases[i].taxRate + 1));
        cout << setw(7) << total << " |\n";
        sumTotal += total;

        if (purchases[i].customerID != purchases[i - 1].customerID)
        {
            uniqueId++;
        }

        averageTotal = sumTotal / fileSize;
    }
    cout << "+-------------+--------------+-------+----------+----------+--------+\n";
    cout << "Unique users:  " << uniqueId << endl;
    cout << "Average total: $" << averageTotal << endl;
}
/*
        FUNCTION_IDENTIFIER: Prints the first half of the table
        parameters: none
        return value: Non-Returning 
*/
void printTable()
{

    cout << "\n+-------------+--------------+-------+----------+----------+--------+\n"
         << "| Customer ID | Product Name | Price | Quantity | Tax Rate | Total  | \n"
         << "+-------------+--------------+-------+----------+----------+--------+\n";
}
