#include "conio.h"
#include <iostream>
#include "Calculator.h"
#include <string>

using namespace std;

char char_key;
string keys_typed = "";
string second_keys_typed = "";
double first_number;
double second_number;
int active_number = 1;
char operation;

int main() 
{
	cout << "> ";
	do 
	{
		char_key = char(_getch());
	
		switch (char_key)
		{
			case '1': case '2': case'3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case'.':
				cout << char_key;
				if (active_number == 1)
					keys_typed += char_key;
				else
					second_keys_typed += char_key;
				break;

			case '*': case '+': case '-': case '/': case '^':
				if (active_number == 1)
				{
					first_number = stod(keys_typed);
					active_number = 2;
					keys_typed = "";
					second_keys_typed = "";
				}
				cout << char_key;
				operation = char_key;
				break;

			case 's': case 'S':
				memoryStore(first_number);
				break;

			case 'r': case 'R':
				first_number = memoryRecall();
				cout << endl << first_number;
				break;

			case 'm': case 'M':
				memoryClear();
				break;

			case 'i': case 'I':
				first_number = invertSign(stod(keys_typed));
				cout << endl << first_number;				
				break;

			case 'c': case 'C':
				cout << endl << "> ";
				keys_typed = "";
				second_keys_typed = "";
				first_number = 0;
				second_number = 0;
				active_number = 1;
				break;

			case char(13):
				cout << endl;
				if (second_keys_typed != "")
					{ 
						second_number = stod(second_keys_typed);
						switch (operation)
						{
							case '+':
								first_number = addition(first_number, second_number);
								break;
							case '-':
								first_number = subtraction(first_number, second_number);
								break;
							case '*':
								first_number = multiplication(first_number, second_number);
								break;
							case '/':
								first_number = division(first_number, second_number);
								break;
							case '^':
								first_number = powerFunction(first_number, second_number);
								break;
							default:
								break;
						}
					}
				cout << first_number << endl << "> ";
				keys_typed = to_string(first_number);
				second_keys_typed = "";
				active_number = 1;
				break;

			default:
				break;
		}

	} while (char_key != 'x' && char_key != 'X');

	return 0;
}
