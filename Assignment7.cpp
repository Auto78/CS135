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

// DONE
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
	else
	{
		cout << WELCOME_MSG << USER << endl;
		return true;
	}
}

// 2.1 add getInput() function
// YOUR CODE HERE
vector<string> getInput()
{

	string userInput;
	vector<string> arguments;
	cout << COMMAND_PROMPT;
	getline(cin, userInput);
	for (size_t i = 0; i < userInput.length(); i++)
	{
		userInput[i] = tolower(userInput[i]);
	}

	stringstream ss(userInput);
	string UpdateUserInput;
	while (getline(ss, UpdateUserInput, ' '))
	{
		arguments.push_back(UpdateUserInput);
	}
	return arguments;
}

// 2.1 add validateArguments(vector<string>) function
// YOUR CODE HERE
string validateArguments(vector<string> args)
{
	if (args.size() != 1 && args[0] == QUIT_CMD)
	{
		return QUIT_ARG_CNT_MSG;
	}
	if (args[0] != QUIT_CMD)
	{
		return INV_CMD_MSG;
	}
	return VALID_ARG_MSG;
}

// 2.1 add executeCommand(vector<string>) function
// YOUR CODE HERE
void executeCommand(vector<string> args)
{

	if (args.size() == 1 && args[0] == QUIT_CMD)
	{
		exit(0);
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
		if (valid == INV_CMD_MSG)
		{
			cout << valid << endl;
		}
		if (valid == QUIT_ARG_CNT_MSG)
		{
			cout << valid << endl;
		}
		
		executeCommand(args);
	} while (true);
}

/*
	DO NOT REMOVE

	Copyright 2022 Alex St. Aubin. All Rights Reserved.

	Unauthorized reproductions of this handout and any accompanying code
	are strictly forbidden under Nevada State and US Federal law.
*/
