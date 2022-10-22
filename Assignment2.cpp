/*
 Name: Alvaro A. Cruz, #5005488379, 1008, Assignment#2
 Description: Program takes in information for animals and displays processed information
 on a table of contents alongside message.
 Input: User inputs amount of zebras and rabbits and number of months
 Output: Data regarding Zebras and Rabbits after months of growth displayed on a table
*/

//include required libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Define constants here
	//Amount of food baby zebra needs each day
	double BABY_ZEBRA_FOOD = 5.0;
	double ZEBRA_GROWTH_RATE = .05;
	//Amount of food baby rabbit needs each day
	double BABY_RABBIT_FOOD = 0.5;
	double RABBIT_GROWTH_RATE = .10;

int main()
{

//Variable Declaration here
	int numberOfMonths = 0;
	//Updated food supply for one grown zebra
	double grownZebraFood = 0.0;
	//Updated food supply for one grown rabbit
	double grownRabbitFood = 0.0;
	int numberOfZebras = 0;
	int numberOfRabbits = 0;
	//Total food needed to feed all zebras after "n" months
	double totalZebraFood = 0.0;
	//Total food needed to feed all rabbits after "n" months
	double totalRabbitFood = 0.0;
	//Sum of Rabbit and Zebra food together
	double totalFoodRequired = 0.0;
	//Ration of Zebra to Rabbit
	int zebraRabbitRatio = 0;

	//Print Zoo Banner
	cout << "+---------------------------------------------------------------------------+ \n"
		 << "|    UU     UU  NNNN     NN  LL       VV      VV         CCCCCC    SSSSSSSS | \n"
		 << "|   /UU    /UU /NN/NN   /NN /LL      /VV     /VV        CC////CC  SS//////  | \n"
		 << "|   /UU    /UU /NN//NN  /NN /LL      /VV     /VV       CC    //  /SS        | \n"
		 << "|   /UU    /UU /NN //NN /NN /LL      //VV    VV       /CC        /SSSSSSSSS | \n"
		 << "|   /UU    /UU /NN  //NN/NN /LL       //VV  VV        /CC        ////////SS | \n"
		 << "|   /UU    /UU /NN   //NNNN /LL        //VVVV         //CC    CC        /SS | \n"
		 << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL   //VV           //CCCCCC   SSSSSSSS  | \n"
		 << "|    ///////   //      ///  ////////     //              //////   ////////  | \n"
		 << "|                                                                           | \n"
		 << "|             ZZZZZZZZ           OOOOOOO         OOOOOOO                    | \n"
		 << "|                 /ZZ           OO/////OO       OO/////OO                   | \n"
		 << "|                /ZZ           OO     //OO     OO     //OO                  | \n"
		 << "|               /ZZ           /OO      /OO    /OO      /OO                  | \n"
		 << "|              /ZZ            /OO      /OO    /OO      /OO                  | \n"
		 << "|             /ZZ             //OO     OO     //OO     OO                   | \n"
		 << "|           //ZZZZZZZZZZ       //OOOOOOO       //OOOOOOO                    | \n"
		 << "|           ///////////         ///////         ///////                     | \n"
		 << "+---------------------------------------------------------------------------+ \n\n";

    cout << "\n*****************************************************************************" <<endl;
    cout << "             Welcome to the UNLV Zoo - Food Supply Department!" <<endl;
    cout << "*****************************************************************************\n" <<endl;

	//Display constant food/day for Zebra & Rabbit
	cout << "The food/day for a baby zebra is constant (lbs): " << BABY_ZEBRA_FOOD << endl;
	cout << "The food/day for a baby rabbit is constant (lbs): " << BABY_RABBIT_FOOD << endl;

	//Ask the user for the number of months of growth to calculate
	cout << "After growing the number of months:\n**";
	cin >> numberOfMonths;

	//Calculate and report the updated food requirements for zebras and rabbits as well as the zebra to rabbit ratio
	grownZebraFood = BABY_ZEBRA_FOOD * pow((1+ZEBRA_GROWTH_RATE),numberOfMonths);
	grownRabbitFood = BABY_RABBIT_FOOD * pow((1+RABBIT_GROWTH_RATE),numberOfMonths);
	zebraRabbitRatio = grownZebraFood/grownRabbitFood;
	cout << fixed << setprecision(2);
	cout << "The food/day for a bigger zebra is: " << grownZebraFood << endl;
	cout << "The food/day for a bigger rabbit is: " << grownRabbitFood << endl;
	cout << "Zebra eats " << zebraRabbitRatio << " times as much as rabbits" << endl;
	cout << endl;
	//Ask the user for the number of zebras and rabbits to feed
    
	cout << "The number of Zebra:\n**";
	cin >> numberOfZebras;
	cout << "The number of Rabbit:\n**";
	cin >> numberOfRabbits;

	//Update total food for zebra, rabbit, and totals
	totalZebraFood = grownZebraFood * numberOfZebras;
	totalRabbitFood = grownRabbitFood * numberOfRabbits;
	totalFoodRequired = totalZebraFood + totalRabbitFood;

	//Display food Totals
	cout << "For Zebras, total food/day in " << numberOfMonths
		<< " months is: " << totalZebraFood << endl;
	cout << "For Rabbits, total food/day in " << numberOfMonths
		<< " months is: " << totalRabbitFood << endl;
	cout << "Overall, total food/day in " << numberOfMonths 
		<< " months is: " << totalFoodRequired << endl;
	//Print formatted results
    cout << setfill(' ') << fixed << setprecision(2)
	     << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
		 << "|" << setw(40) << "|\n"
		 << "|             UNLV CS Zoo              |\n"
		 << "|         4505 S Maryland Pkwy         |\n"
		 << "|          Las Vegas,NV 89154          |\n"
		 << "|            (702) 895-3011            |\n"
		 << "|                                      |\n"
		 << "|                                      |\n"
		 << "| Baby Zebra(lbs/d):" << setw(18) << BABY_ZEBRA_FOOD << " |\n"
		 << "| Growth Rate(month):" << setw(16) << (ZEBRA_GROWTH_RATE*100) << "% |\n"
		 << "| Baby Rabbit(lbs/d):" << setw(17) << BABY_RABBIT_FOOD << " |\n"
		 << "| Growth Rate(month):" << setw(16) << (RABBIT_GROWTH_RATE*100) << "% |\n"
		 << "|" << setw(40) << "|\n"
		 << "| Growth Month:" << setw(23) << numberOfMonths << " |\n"
		 << "| Grown Zebra(lbs/d):" << setw(17) << grownZebraFood << " |\n"
		 << "| Grown Rabbit(lbs/d):" << setw(16) << grownRabbitFood << " |\n"
		 << "|" << setw(40) << "|\n"
		 << "| Zebra amount:" << setw(23) << numberOfZebras << " |\n"
		 << "| Rabbit amount:" << setw(22) << numberOfRabbits << " |\n"
		 << "| Total Food(lbs/d):" << setfill('*') << setw(18) 
		 << ceil(totalFoodRequired) << " |\n" << setfill(' ')
		 << "|" << setw(40) << "|\n"
         << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"<<endl;

    return 0;
 }
