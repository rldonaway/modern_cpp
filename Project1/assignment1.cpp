int Add(int* a, int* b) {
	int aVal = *a;
	int bVal = *b;
	return aVal + bVal;
}

void AddVal(int* a, int* b, int* result) {
	int aVal = *a;
	int bVal = *b;
	int sum = aVal + bVal;
	*result = sum;
}

void Swap(int* a, int* b) {
	int aVal = *a;
	int bVal = *b;
	*a = bVal;
	*b = aVal;
}

void Factorial(int* a, int* result) {
	int factorial = 1;
	for (int i = *a; i > 0; i--) {
		factorial *= i;
	}
	*result = factorial;
}