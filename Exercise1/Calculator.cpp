#include <iostream>
#include "Calculator.h"
#include <math.h>

namespace Calculator {
	double memory;

	// make an addition of a two numbers and return the result
	double makeAddition(double first_number, double second_number)
	{
		return first_number + second_number;
	}

	// make a subtraction of a two numbers and return the result
	double makeSubtraction(double first_number, double second_number)
	{
		return first_number - second_number;;
	}

	// make a multiplication of a two numbers and return the result
	double makeMultiplication(double first_number, double second_number)
	{
		return first_number * second_number;
	}

	// make a division of a two numbers and return the result
	double makeDivision(double first_number, double second_number)
	{
		return first_number / second_number;
	}

	// make a power function of a two numbers and return the result
	double makePower(double first_number, double second_number)
	{
		return pow(first_number, second_number);
	}

	// store the number in the variable called "memory"
	void memoryStore(double input_number)
	{
		memory = input_number;
	}

	// return the value of the variable called "memory"
	double memoryRecall()
	{
		return memory;
	}

	// clear the value of the variable called "memory"
	void memoryClear()
	{
		memory = 0;
	}

	// make a invert sign of a number and return the result
	double invertSign(double input_number)
	{
		return 0.0 - input_number;;
	}
}
