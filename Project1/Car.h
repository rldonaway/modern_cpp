#pragma once

class Car {
private:
	float fuel{ 0 }; // default values that apply to any constructor unless overridden
	float speed{ 0 };
	int passengers{ 0 };
	// auto is not allowed here
	static int totalCount;

public:
	Car();
	Car(float amount);
	~Car();

	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count);
	void Dashboard() const;
	static void ShowCount();

};