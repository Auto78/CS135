/*
	Name: Alvaro Cruz, 5005488379#, 1005, Assignment 7
	Description: Program uses multiple actions to manipulate a SQL
	Input: User inputs credentials to open and input to process commands
	Output: Creates a table, deletes a table,and shows various details given
	certain commands
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <sstream>

using namespace std;

const string USER = "meowmin";
const string PASS = "1w@ntch1cken";

const string COMMAND_PROMPT = ">";
const string COMMAND_DELIMITER = " ";

const string QUIT_CMD = "quit";
const string SHOW_CMD = "show";
const string CREATE_CMD = "create";
const string DELETE_CMD = "delete";

const string TABLE_FILETYPE = ".csv";
const string TABLE_FILE_DIRECTORY = "data/";
const string TABLES_TABLE = "data/tables.csv";

const string SHOW_ARG_1 = "tables";

const string USAGE_MSG = "Usage: ./a.out <username> <password>\n";
const string WELCOME_MSG = "Welcome ";

const string VALID_ARG_MSG = "";
const string QUIT_ARG_CNT_MSG = "QUIT Error: invalid argument count";
const string SHOW_ARG_CNT_MSG = "SHOW Error: invalid argument count";
const string CREATE_ARG_CNT_MSG = "CREATE Error: invalid argument count";
const string DELETE_ARG_CNT_MSG = "DELETE Error: invalid argument count";

const string TABLE_CREATE_SUCCESS_MSG = " table created successfully";
const string TABLE_DELETE_SUCCESS_MSG = " table removed successfully";
const string INVALID_CREDENTIALS_MSG = "Error: invalid credentials\n";
const string INV_CMD_MSG = "Error: invalid command name";
const string SHOW_INV_OPT_MSG = "SHOW Error: invalid option";
const string CREATE_INV_TABLE_NAME_MSG = "CREATE Error: table name should only contain"
										 " alpha numeric characters, '-', or '_'";
const string CREATE_EXISTS_MSG = "CREATE Error: table already exists";
const string CREATE_INV_HEADERS_MSG = "CREATE Error: column names should be separated"
									  " by delimiter and should only contain alpha numeric characters, '-', or '_'";
const string DELETE_UNDELETABLE_MSG = "DELETE Error: table cannot be deleted";
const string DELETE_INV_TABLE_NAME_MSG = "DELETE Error: invalid table name";

void header();
string toLower(string);
void getCredentials(int, char const *[], string &, string &);
bool validateCredentials(string, string);
// sections 2/3 add function prototypes
// YOUR CODE HERE
void commandLoop();
vector<string> getInput();
string validateArguments(vector<string>);
void executeCommand(vector<string>);
// Extra handy-dandy Homemade Functions
bool isValidName(char);
bool isValidAttribute(char);

int main(int argc, char const *argv[])
{
	string user = "", pass = "";

	getCredentials(argc, argv, user, pass);

	if (validateCredentials(user, pass))
	{
		// 1.2 call get header
		// YOUR CODE HERE
		header();

		// 2.1 call the loop to get commands from the user
		// YOUR CODE HERE
		commandLoop();
	}

	return 0;
}

// used for section 1
// prints header
void header()
{
	cout << "+---------------------------------------------------------------------+\n"
		 << "|   __   __  _______  _______  _     _    _______  _______  ___       |\n"
		 << "|  |  |_|  ||       ||       || | _ | |  |       ||       ||   |      |\n"
		 << "|  |       ||    ___||   _   || || || |  |  _____||   _   ||   |      |\n"
		 << "|  |       ||   |___ |  | |  ||       |  | |_____ |  | |  ||   |      |\n"
		 << "|  |       ||    ___||  |_|  ||       |  |_____  ||  |_|  ||   |___   |\n"
		 << "|  | ||_|| ||   |___ |       ||   _   |   _____| ||      | |       |  |\n"
		 << "|  |_|   |_||_______||_______||__| |__|  |_______||____||_||_______|  |\n"
		 << "|                                                               v1.0.0|\n"
		 << "+---------------------------------------------------------------------+\n";
}

// Used for section 2
// lowercases string and returns it
string toLower(string s)
{
	for (char &x : s)
		x = static_cast<char>(tolower(x));
	return s;
}

// Used for section 3
// Prints the csv at the passed file path
bool printTable(string file)
{
	string current = "", rest = "", delimiter = ",";
	int rowCnt = 0;
	ifstream toShow(file);
	getline(toShow, current);
	int colCnt = count(current.begin(), current.end(), delimiter[0]) + 1;
	toShow.seekg(0);
	vector<unsigned int> widths(colCnt, 0);
	while (getline(toShow, rest))
	{
		for (int i = 0; i < colCnt; i++)
		{
			current = rest.substr(0, rest.find(delimiter));
			rest = rest.erase(0, rest.find(delimiter) + 1);
			if (current.size() > widths[i])
				widths[i] = current.size();
		}
		rowCnt++;
	}
	if (rowCnt > 1)
	{
		toShow.clear();
		toShow.seekg(0);
		cout << file.substr(file.find("data/") + 5, file.length() - 9) << " table:\n";
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		getline(toShow, current);
		vector<string> ret;
		string token = "";
		while (current.find(delimiter) != string::npos)
		{
			token = current.substr(0, current.find(delimiter));
			current = current.erase(0, current.find(delimiter) + delimiter.length());
			ret.push_back(token);
		}
		ret.push_back(current);
		cout << setfill(' ') << left;
		for (unsigned int i = 0; i < widths.size(); i++)
			cout << "| " << setw(widths[i]) << ret[i] << " ";
		cout << "|" << endl;
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		while (getline(toShow, current))
		{
			ret.clear();
			while (current.find(delimiter) != string::npos)
			{
				token = current.substr(0, current.find(delimiter));
				current = current.erase(0, current.find(delimiter) + delimiter.length());
				ret.push_back(token);
			}
			ret.push_back(current);
			cout << setfill(' ') << left;
			for (unsigned int i = 0; i < widths.size(); i++)
				cout << "| " << setw(widths[i]) << ret[i] << " ";
			cout << "|" << endl;
		}
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		cout << rowCnt - 1 << " row(s) in set.\n";
		return true;
	}
	return false;
}

//  Fill this function out for section 1.1
void getCredentials(int argc, char const *argv[], string &user, string &pass)
{

	// 1.1 get username and password from cmd args
	// YOUR CODE HERE
	if (argc != 3)
	{
		cout << USAGE_MSG;
		exit(0);
	}
	user = argv[1];
	pass = argv[2];
}

// Fill this function out for section 1.2
bool validateCredentials(string u, string p)
{
	// 1.2 make sure proper user/pass
	// YOUR CODE HERE
	if (u != USER || p != PASS)
	{
		cout << INVALID_CREDENTIALS_MSG;
		return false;
	}
	cout << WELCOME_MSG << USER << endl;
	return true;
}

// 2.1 add getInput() function
// YOUR CODE HERE
vector<string> getInput()
{
	// Getline user input and lowercase it
	string userInput;
	vector<string> arguments;
	cout << COMMAND_PROMPT;
	getline(cin, userInput);
	userInput = toLower(userInput);

	// Using StringStream to split string and pushBack
	// individal sections to vector
	stringstream ss(userInput);
	string updateUserInput;
	while (getline(ss, updateUserInput, ' '))
	{
		arguments.push_back(updateUserInput);
	}
	return arguments;
}

// 2.1 add validateArguments(vector<string>) function
// YOUR CODE HERE
string validateArguments(vector<string> args)
{
	ifstream inFile;
	// Checks args for no input
	if (args.size() == 0)
	{
		return INV_CMD_MSG;
	}

	// Checks for Invalid Commmand
	// Im sure there is a better way of handling this
	if (args[0] != QUIT_CMD && args[0] != CREATE_CMD && args[0] != SHOW_CMD && args[0] != DELETE_CMD)
	{
		return INV_CMD_MSG;
	}

	// Checks if Quit count is wrong
	if (args[0] == QUIT_CMD && args.size() != 1)
	{
		return QUIT_ARG_CNT_MSG;
	}
	// Check if Creates count is wrong
	if (args[0] == CREATE_CMD && args.size() != 3)
	{
		return CREATE_ARG_CNT_MSG;
	}
	// Checks if Show count is wrong
	if (args[0] == SHOW_CMD && args.size() != 2)
	{
		return SHOW_ARG_CNT_MSG;
	}
	// Checks if Delete count is wrong
	if (args[0] == DELETE_CMD && args.size() != 2)
	{
		return DELETE_ARG_CNT_MSG;
	}

	// Checks if Shows 2nd argument is wrong
	if (args[0] == SHOW_CMD && args[1] != SHOW_ARG_1)
	{
		return SHOW_INV_OPT_MSG;
	}

	// Creates Command
	if (args[0] == CREATE_CMD)
	{
		string tableName = args[1];
		string attributeList = args[2];

		// Checks the table Name is valid characters
		for (size_t i = 0; i < tableName.length(); i++)
		{
			if (!isValidName(tableName[i]))
			{
				return CREATE_INV_TABLE_NAME_MSG;
			}
		}
		// Checks if the file is already open
		inFile.open(TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE);
		if (inFile.is_open())
		{
			inFile.close();
			return CREATE_EXISTS_MSG;
		}
		// If starts with comma
		if (attributeList[0] == ',')
		{
			return CREATE_INV_HEADERS_MSG;
		}
		// If ends with comma
		if (attributeList[attributeList.length() - 1] == ',')
		{
			return CREATE_INV_HEADERS_MSG;
		}
		// Loops to check for the characters
		for (size_t i = 1; i < attributeList.length(); i++)
		{
			// Checks for comma errors
			if (attributeList[i] == ',' && attributeList[i - 1] == ',')
			{
				return CREATE_INV_HEADERS_MSG;
			}
			// CHANGE THE IS ALNUM TO YOUR OWN
			if (!isValidAttribute(attributeList[i]))
			{
				return CREATE_INV_HEADERS_MSG;
			}
		}
	}
	// Show command
	if (args[0] == SHOW_CMD)
	{
		return VALID_ARG_MSG;
	}
	// Delete Command
	if (args[0] == DELETE_CMD)
	{
		if (args[1] == "tables")
		{
			return DELETE_UNDELETABLE_MSG;
		}
		// Checks if file is openable otherwise file doesn't exist
		// thus it can not be deleted
		inFile.open(TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE);
		if (inFile.is_open())
		{
			inFile.close();
		}
		else
		{
			return DELETE_INV_TABLE_NAME_MSG;
		}
	}
	// Generic valid argument return
	return VALID_ARG_MSG;
}

// 2.1 add executeCommand(vector<string>) function
// YOUR CODE HERE
void executeCommand(vector<string> args)
{
	ifstream inFile;
	ofstream outFile;
	// Processes the quit command
	if (args.size() == 1 && args[0] == QUIT_CMD)
	{
		exit(0);
	}
	// Process the Create Command
	if (args.size() == 3 && args[0] == CREATE_CMD)
	{
		// Opens corresponding FilePath and prints contents to file
		outFile.open(TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE);
		outFile << args[2];
		outFile.close();
		// Prints corresponding Content to main file
		outFile.open(TABLES_TABLE, ios_base::app);
		outFile << args[1] << endl;
		cout << args[1] << TABLE_CREATE_SUCCESS_MSG << endl;
		outFile.close();
	}
	// Process the Show Command
	if (args[0] == SHOW_CMD)
	{
		printTable(TABLES_TABLE);
	}
	// Process the Delete Command
	if (args[0] == DELETE_CMD)
	{
		// Deletes the File contents
		inFile.open(TABLES_TABLE);

		// Gathers current file contents
		string updatedTablesString;
		vector<string> updatedTablesVector;
		while (getline(inFile, updatedTablesString))
		{
			updatedTablesVector.push_back(updatedTablesString);
		}
		inFile.close();
		outFile.open(TABLES_TABLE);

		// Reprints file without the corresponding content
		for (size_t i = 0; i < updatedTablesVector.size(); i++)
		{
			if (updatedTablesVector[i] != args[1])
			{
				outFile << updatedTablesVector[i] << endl;
			}
		}
		outFile.close();

		// Deletes the filepath of unwanted content
		string filePath = TABLE_FILE_DIRECTORY + args[1] + TABLE_FILETYPE;
		remove(filePath.c_str());
		cout << args[1] << TABLE_DELETE_SUCCESS_MSG << endl;
	}
}

// 2.1 add commandLoop() function
// YOUR CODE HERE
void commandLoop()
{
	do
	{
		vector<string> args = getInput();
		string valid = validateArguments(args);
		// Loop Prints corresponding Error Message
		if (valid != VALID_ARG_MSG)
		{
			cout << valid << endl;
			continue;
		}
		executeCommand(args);
	} while (true);
}

/*
	FUNCTION_IDENTIFIER: Checks char is alphabetic, Numerical, -, or underscore
	parameters: Char
	return value: Returns boolean value True if within acceptable parameters
	else returns a default value False.
*/
bool isValidName(char text)
{
	if (('a' <= text && text <= 'z') || ('0' <= text && text <= '9') || text == '-' || text == '_')
	{
		return true;
	}
	return false;
}
/*
	FUNCTION_IDENTIFIER: Checks char is alphabetic, Numerical, -, _, or comma
	parameters: Char
	return value: Returns boolean value True if within acceptable parameters
	else returns a default value False.
	*/
bool isValidAttribute(char text)
{
	if (('a' <= text && text <= 'z') || ('0' <= text && text <= '9') || text == '-' || text == '_' || text == ',')
	{

		return true;
	}
	return false;
}
/*
	DO NOT REMOVE

	Copyright 2022 Alex St. Aubin. All Rights Reserved.

	Unauthorized reproductions of this handout and any accompanying code
	are strictly forbidden under Nevada State and US Federal law.
*/
