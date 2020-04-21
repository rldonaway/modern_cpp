#include "assignment2.h"

void Add(int a, int b, int& result)
{
	result = a + b;
}

void Factorial(int a, int& result)
{
	result = 1;
	for (int i = a; i > 1; i--) {
		result *= i;
	}
}

/* This is the best way to handle input/output parameters. */
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
