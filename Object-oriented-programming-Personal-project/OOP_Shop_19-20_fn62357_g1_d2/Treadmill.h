#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Treadmill
{
	char* function = nullptr;
	double maxSpeed;
	double weight;

public:
	Treadmill();
	Treadmill(const char*, double, double);
	Treadmill(const Treadmill&);
	Treadmill& operator=(const Treadmill&);
	~Treadmill();

	//setters
	void setFunction(const char*);
	void setMaxSpeed(double);
	void setWeight(double);

	//getters
	const char* getFunction() const;
	double getMaxSpeed() const;
	double getWeight() const;
};
