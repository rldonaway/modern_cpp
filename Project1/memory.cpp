#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void WorkingWithMemory() {
	int* p = (int*) malloc(sizeof(int)); // only allocates memory, does not initialize
	*p = 5;
	printf("%d", *p);
	free(p); // do this or you'll get a memory leak when you null out
	// p is now a dangling pointer
	p = NULL;

	int* q = (int*) calloc(1, sizeof(int)); // how many, what size; initializes to 0
	if (q == NULL) {
		printf("Failed to allocate memory\n"); // need to check this
	}
	int* r = (int*) calloc(5, sizeof(int)); // this gives you an array of size 5
	// how to do with malloc: (int*) malloc(5*sizeof(int));

	// can also use the new operator
	r = new int; // will allocate the right amount of memory
	*r = 6;
	delete r; // free up memory
	// r is now a dangling pointer
	r = nullptr;

	// new is superior to malloc
}

void Arrays() {
	int* p = new int[5]; // allocate memory for 5 integers
	for (int i = 0; i < 5; ++i) {
		p[i] = i;
	}
	delete[] p; // free up the memory
	int* q = new int[5]{ 1,2,3,4,5 }; // another way
}

void Strings() {
	char* p = new char[4];
	strcpy_s(p, 4, "C++"); // need to allocate an extra byte for termination
	delete[] p;
}