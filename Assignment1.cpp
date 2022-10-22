/*
Name: Alvaro Cruz, #5005488379, 1005, Assignment01
Description: Program calculating cost of school trip to the zoo
Input: User inputs # of People and budget pooled
Output: # of buses needed, tick cost, tax, and money leftover
*/

//Preprocessor Directives
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Declaring Const Variables;
    const double adultTicket = 7.95;
    const float salesTax = 0.0685;

//Intro to main code
int main () {

//Declaring Variables
    int numberOfPeople = 0;
    int numberOfBuses = 0;
    double pooledBudget = 0.0;
    double totalTicketCost = 0.0;
    double leftOverPerPerson = 0.0;
    double tax = 0.0;
    //left over amount rounded to the nearest .01th
    double roundedLeftOver = 0.0;

//Input Phase;
    cout << "How many people are in the class? ";
    cin >> numberOfPeople;
    cout << "How much money is in the pool? $";
    cin >> pooledBudget;

//Processing Phase;
    //Ensure # of buses will be at least 1 for 1 person & 0 for 0
    numberOfBuses = (numberOfPeople + 11)/12.0;
    //Calculating total ticket cost for all people accounted for
    totalTicketCost = numberOfPeople * adultTicket;
    //Casting tax as an int divide 100.0 rounding down to nearest .01th
    tax = static_cast<int>(((totalTicketCost * salesTax)*100))/100.0;
    //calcualting left over money for food per person
    leftOverPerPerson = (pooledBudget - totalTicketCost - tax)/numberOfPeople;
    //Rounding down the left over money for food to the nearest .01th
    roundedLeftOver = static_cast<int>((leftOverPerPerson*100))/100.0;

//Output Phase
    cout << numberOfBuses << " Buses need to be reserved.\n";
    cout << "Tickets will cost $" << totalTicketCost
    << "\nTax will be $" << tax
    << "\nEach person will have $" << roundedLeftOver
    << " for food.\n";   
}
