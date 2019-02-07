#include <iostream>
#include <string>
#include "conio.h"
#include "Calculator.h"

using namespace std;

double first_number_for_the_operation, second_number_for_the_operation;
string keys_before_the_operation_typed, keys_after_the_operation_typed;
int active_number;
char operation_in_progress, key_pressed;

// reset all variables to the default value
void resetVariables()
{
	keys_before_the_operation_typed = "";
	keys_after_the_operation_typed = "";
	first_number_for_the_operation = 0;
	second_number_for_the_operation = 0;
	active_number = 1;

}



int main() 
{
	cout << "> ";
	resetVariables();

	do 
	{

		key_pressed = toupper(char(_getch())); // get the key pressed, convert it to char and to upper case of the key pressed
	
		switch (key_pressed)
		{
			// if the digit or dot is pressed
			case '1': case '2': case'3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case'.':
				cout << key_pressed;
				if (active_number == 1)
					keys_before_the_operation_typed += key_pressed;
				else
					keys_after_the_operation_typed += key_pressed;
				break;
			
			// if some of the operation key is pressed
			case '*': case '+': case '-': case '/': case '^':
				if (active_number == 1)
				{
					first_number_for_the_operation = stod(keys_before_the_operation_typed);
					active_number = 2;
					keys_before_the_operation_typed = "";
					keys_after_the_operation_typed = "";
				}
				cout << key_pressed;
				operation_in_progress = key_pressed;
				break;

			// if "Enter" is pressed
			case char(13):
				cout << endl;
				if (keys_after_the_operation_typed != "")
					{ 
						second_number_for_the_operation = stod(keys_after_the_operation_typed); // get the keys after operation key pressed as second number

						// do a neccessary operation that depends of a key that is earlier pressed as a operation key, and put the result in first number double variable
						switch (operation_in_progress)
						{
							case '+':
								first_number_for_the_operation = makeAddition(first_number_for_the_operation, second_number_for_the_operation);
								break;
							case '-':
								first_number_for_the_operation = makeSubtraction(first_number_for_the_operation, second_number_for_the_operation);
								break;
							case '*':
								first_number_for_the_operation = makeMultiplication(first_number_for_the_operation, second_number_for_the_operation);
								break;
							case '/':
								first_number_for_the_operation = makeDivision(first_number_for_the_operation, second_number_for_the_operation);
								break;
							case '^':
								first_number_for_the_operation = makePower(first_number_for_the_operation, second_number_for_the_operation);
								break;
							default:
								break;
						}
					}
				cout << first_number_for_the_operation << endl << "> "; // print the result
				keys_before_the_operation_typed = to_string(first_number_for_the_operation); // put first number back in the string before the operation
				keys_after_the_operation_typed = ""; // clear the 'after the operation' string 
				active_number = 1; // set active number as first
				break;

			// if "S" is pressed
			case 'S':
				memoryStore(first_number_for_the_operation); // call the function for storing the number in the memory
				break;

			// if "R" is pressed
			case 'R':
				first_number_for_the_operation = memoryRecall(); // get the number from the memory
				cout << endl << first_number_for_the_operation; // and use it as a first number for the next operation
				break;

			// if "M" is pressed
			case 'M':
				memoryClear(); // clear the memory
				break;

			// if "I" is pressed
			case 'I':
				first_number_for_the_operation = invertSign(stod(keys_before_the_operation_typed)); // get the number from the key sequence, call the function that will invert it
				cout << endl << first_number_for_the_operation; // and use it as a first number
				break;

			// if "C" is pressed
			case 'C':
				cout << endl << "> "; // print the default char in a new row;
				resetVariables(); // reset all variables
				break;


			default:
				break;
		}

	} while (key_pressed != 'X');

	return 0;
}