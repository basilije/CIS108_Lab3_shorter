#include "conio.h"
#include <iostream>
#include "Calculator.h"
#include <string>

using namespace std;

int get_key;
char char_key;
string keys_typed = "";
string first_number;
string second_number;
//char operation;
char *pch;
char char_array[];
size_t pos = 0;
string operation;

int main() 
{
	cout << "> ";
	do 
	{
		get_key = _getch();
		char_key = char(get_key);
	
		switch (char_key)
		{
			case char(13):
				cout << endl;
				// recognize all parts of string typed, split it on first number, operation and second number
				// call some function from Calculator.cpp, every character typed are in "keys_typed"
				operation = '*';
				pos = keys_typed.find(operation);
				first_number = keys_typed.substr(0, pos);
				second_number = keys_typed;
				second_number.erase(0, pos + 1);

				// keys_typed = "string result from the operation in Calculator.cpp";
				// cout << keys_typed;
				
				keys_typed = makeOperation(first_number, "*", second_number);
				cout << keys_typed;
				//cout << first_number << operation << second_number;
				break;

			default:
				// print what we pressed
				cout << char_key;
				keys_typed += char_key;
				break;
		}

	} while (char_key != 'x' && char_key != 'X');

	return 0;
}