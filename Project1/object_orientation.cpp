#include "Car.h"

int main() {
	// Car car; // default constructor
	Car car(4); // overloaded constructor

	// car.FillFuel(6);
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();
	car.Accelerate();

	return 0;
}

struct point {
	// all members public
	int x;
	int y;
};