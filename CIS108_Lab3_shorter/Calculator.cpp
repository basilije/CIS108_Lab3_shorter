#include <iostream>

using namespace std;
double memory;

double addition(double first_number, double second_number)
{
	return first_number + second_number;
}

double subtraction(double first_number, double second_number)
{
	return first_number - second_number;;
}

double multiplication(double first_number, double second_number)
{
	return first_number * second_number;
}

double division(double first_number, double second_number)
{
	return first_number / second_number;
}

double powerFunction(double first_number, double second_number)
{
	return pow(first_number, second_number);;
}

void memoryStore(double input_number)
{
	memory = input_number;
}

double memoryRecall()
{
	return memory;
}

void memoryClear()
{
	memory = 0;
}

double invertSign(double input_number)
{
	return 0.0 - input_number;;
}
