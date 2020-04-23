#include "Car.h"
#include <iostream>

int Car::totalCount = 0; //static variable

Car::Car()
{
	++totalCount;
	fuel = 0;
	speed = 0;
	passengers = 0;
}

Car::Car(float amount)
{
	++totalCount;
	fuel = amount;
	speed = 0;
	passengers = 0;
}

Car::~Car()
{
	--totalCount;
	std::cout << "~Car" << std::endl;
}

void Car::FillFuel(float amount)
{
	fuel = amount;
}

void Car::Accelerate()
{
	this->speed++; // this-> is implied so don't need it
	this->fuel -= 0.5f;
}

void Car::Brake()
{
	speed = 0;
}

void Car::AddPassengers(int passengers)
{
	this->passengers = passengers;
	Foo(*this); // Foo needs a Car and we are putting in this one
}

void Car::Dashboard() const // this means this method cannot change instance variables; useful for making read-only method like this one
{
	std::cout << "Fuel:" << fuel << std::endl;
	std::cout << "Speed:" << speed << std::endl;
	std::cout << "Passengers:" << passengers << std::endl;
}

void Car::ShowCount()
{
	std::cout << "Total count:" << Car::totalCount << std::endl; // accessing a static variable
}

void Foo(const Car& car) {

}