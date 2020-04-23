// This is a single line comment

/*
This is a
multi line comment
*/
#include <iostream>
#include "math.h" // gives us Add2 declaration to go with math.cpp definition
#include "assignment1.h"
#include "assignment2.h"

// Prototype or declaration
int Add(int x, int y);
void Assignment1();
void Assignment2();
void Assignment3();

// can also actually define functions here if they are local to this cpp file only
void Print(char ch) {
	for (int i = 0; i < 10; i++) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

int main() {
	Assignment2();
	return 0;
}

/* This assignment is about pointers. */
void Assignment1() {
	using namespace std;

	int aVal = 7;
	int bVal = 4;

	cout << Add(&aVal, &bVal) << endl;

	int sum = 0;
	AddVal(&aVal, &bVal, &sum);
	cout << sum << endl;

	cout << aVal << " " << bVal << endl;
	Swap(&aVal, &bVal);
	cout << aVal << " " << bVal << endl;

	int fact = 0;
	Factorial(&aVal, &fact);
	cout << fact << endl;
}

/* This assignment is about references. */
void Assignment2()
{
	using namespace std;

	int a = 5;
	int b = 2;
	int s = 0;
	int& sumRef = s;
	Add(a, b, sumRef);
	cout << sumRef << endl;

	int& fact = s;
	Factorial(a, fact);
	cout << fact << endl;

	int& aRef = a;
	int& bRef = b;
	cout << aRef << " " << bRef << endl;
	Swap(a, b);
	cout << aRef << " " << bRef << endl;
}

void Assignment3()
{
	// this is okay, modifying value through value:
	int value = 5;
	const int* ptr = &value; // ptr's contents cannot change through ptr
	value = 6; // okay to modify a non-constant int
	// *ptr = 7; // this won't compile because ptr is constant and dereferencing counts as modifying

	int value1 = 5;
	const int* ptr1 = &value1; // ptr's contents cannot change through ptr
	int value2 = 6;
	ptr1 = &value2; // why is this allowed?? because we are not changing the contents at ptr1, just the value of ptr1

	int* const ptr3 = &value1; // okay, the const pointer is initialized to the address of value1
	// ptr3 = &value2; // not okay, once initialized, a const pointer can not be changed.
	int* const ptr4 = &value; // ptr4 will always contain the address of value
	*ptr4 = 6; // allowed, since ptr4 points to a non-const int
	const int* const ptr5 = &value; // neither the int nor the pointer can change

	/* way to remember: const int* means the int is constant, int* const means the pointer is constant */
				   
	//Try to modify x1 & x2 and see the compilation output
	int x = 5;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;
	ref_x1 = 7; // (this does nothing)
	// ref_x2 = 7; (this won't compile)

	//Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
	const int* ptr1 = &x;
	int* const ptr2 = &x;
	const int* const ptr3 = &x;
	ptr1 = &MAX; // why is this allowed? the int MAX is constant but the memory address at ptr1 is not
	// ptr2 = &MAX; // this won't compile because the memory address at ptr2 cannot change

	//Find which declarations are valid. If invalid, correct the declaration
	const int* ptr3 = &MAX; // MAX is a constant and so is ptr3 so there is no problem
	// int* ptr4 = &MAX; // this won't compile because you could set *ptr4 = 8

	const int& r1 = ref_x1; // this is another reference to x1 and x1 is not constant
	// int& r2 = ref_x2; // this won't compile because ref_x2 is a constant reference to x treated as a constant?

	// int*& p_ref1 = ptr1; // this won't work because p_ref1 is not constant and ptr1 is so doing this would allow value1 to be modified
	// const int*& p_ref2 = ptr2; // this won't work because ptr2 has constant contents and only the reference p_ref2 is constant

	// a const object cannot have its *contents* changed
}

void Pointers() {
	using namespace std;
	int x = 10;
	cout << &x << endl; // address of x
	int* ptr = &x;
	// normally the types match, but if you don't care you can have void *ptr = &x;
	cout << ptr << endl;
	*ptr = 5; // dereferenced! now x==5
	cout << x << endl;
	int y = *ptr; // y is now the value at the address of x (5)
	cout << y << endl;
	void* ptr2 = nullptr; // way to initialize a pointer when you don't know the value yet; can't print or dereference
}

void Initialization() {
	int a1; // uninitialized
	int a2 = 0; // initialized (copy)
	int a3(5); // direct initialization

	std::string s1; // uninitialized
	std::string s2("C++"); // direct initialization

	char d1[4]; // uninitialized
	char d2[4] = { '\0' }; // empty (copy)
	char d3[4] = { 'a', 'b', 'c', 'd' }; // aggregate initialization (copy)
	char d4[4] = { "abc" }; // string termination is the 4th entry (copy)

	/* Uniform Initialization */
	int b1{}; // initialized to the default: 0 (value initialization)
	int b3{ 5 }; // direct initialization

	char e1[8]{}; // creates array initialized to defaults in every position
	char e2[6]{ "Hello" }; // direct initialization

	/*
	Uniform initialization benefits:
		1. forces initialization
		2. can use direct initialization for array types
		3. detects narrowing conversions like int i{3.14}
		4. uniform syntax for primitives and objects
	*/
}


void Functions() {
	int x, y;
	std::cin >> x >> y;
	/*
	int result = x + y;
	std::cout << "Result is" << result << std::endl;
	*/
	int result = Add(x, y); // prottype at the top of this file, definition below
	std::cout << Add2(x, y); // prototype in the header file we wrote, definition in cpp file with same name

	Print('#');

	// function overloading
	// void Print(int* x);
	// void Print(const int* x); // okay to overload, this will apply to constants only
	// actually, C++ is creating separate names for the functions (mangling) so that they can be linked
	// this might make the functions not able to be called in C, generate a MAP file to see the names, apply extern C to stop mangling

	void (*pfn) (char) = Print; // this is a pointer to the Print function
	(*pfn)('@'); // invokes Print on '@'
	pfn('+'); // invokes Print on '+'

}

void ForLoops() {
	using namespace std;
	int arr[] { 5,6,7,8,9 };
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	for (const auto& x : arr) { // values in the array can't be changed at runtime, which is usually what you want
		cout << x << " ";
	}

}

int Add(int x, int y) {
	int sum = x + y;
	std::cout << "Sum is:" << sum << std::endl;
	return sum;
}

void BasicIO()
{
	using namespace std; // helps to avoid writing std:: all the time
	cout << "Hello " << "C++" << endl;

	// Scalar types
	int i{ 1 };
	cout << i << endl;

	char ch = 'a';
	bool flag = true;

	float f = 1.283f;
	double d = 521.342;

	// Vector types
	int arr[5] = { 1,2,3,4,5 };

	int arr1[5]{ 1,2,3,4,5 };

	int age;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Your age is: " << age << endl;

	char buff[512];
	cout << "What is your name? ";
	cin >> buff; // not sure how to get it to read the whole string, seems like we don't need both >> buff and getLine
	cout << "Your name is: " << buff;
	cin.getline(buff, 64);
	cout << buff << endl;
}

void CopyConstructors() {
	// Integer i(5); // this is an implementation of an integer wrapper, calling the constructor that takes an int
	// Integer i2(i); // this is the copy constructor, implemented automatically

	int* p1 = new int(5);
	int* p2 = p1; // creates a copy of the memory address of the int 5 (shallow copy)
	// here's a deep copy:
	int* p3 = new int(*p1);

	/*
	Integer::Integer(const Integer &obj) { // have to pass by reference to avoid an infinite loop of copies
		m_pInt = new int(*obj.m_pInt);
	}
	*/

	// Rule of 3 (reasons to create a copy constructor)
	// Implement _all_ of * destructor * copy constructor * copy assignment operator
	// not doing this can lead to memory leaks or a shallow copy
}

// namespaces -- scope types
// using namespace std;
// better: using std::cout;
// fully-qualified name: std::cout << "C++" << std::endl;
namespace Avg {
	float Calc(float x, float y) {
		return (x + y)/2;
	}
}

// this avoids the collision of the two Calc functions
namespace Basic {
	float Calc(float x, float y) {
		return x + y;
	}
}

// can nest namespaces: Something::Basic::Calc
// can create anonymous namespaces that are visit only in the curent context (what's the point?)
