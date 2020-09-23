#include "Treadmill.h"
#include <cstring>

Treadmill::Treadmill()
{
	type = Category::Treadmill;
	setFunction("");
	setMaxSpeed(0);
	setWeight(0);
}

Treadmill::Treadmill(const char * _function, double _speed, double _weight)
{
	setFunction(_function);
	setMaxSpeed(_speed);
	setWeight(_weight);
}

Treadmill::Treadmill(const Treadmill & cpy)
{
	setFunction(cpy.function);
	setMaxSpeed(cpy.maxSpeed);
	setWeight(cpy.weight);
}

Treadmill & Treadmill::operator=(const Treadmill & cpy)
{
	if (this != &cpy)
	{
		setFunction(cpy.function);
		setMaxSpeed(cpy.maxSpeed);
		setWeight(cpy.weight);
	}
	return *this;
}

Treadmill::~Treadmill()
{
	delete[] function;
}

void Treadmill::setFunction(const char * _function)
{
	if (_function == nullptr) return;
	int Length = strlen(_function);
	char* temp = new char[Length + 1];
	strcpy(temp, _function);
	delete[] function;
	function = temp;
}

void Treadmill::setMaxSpeed(double _speed)
{
	this->maxSpeed = _speed;
}

void Treadmill::setWeight(double _weight)
{
	this->weight = _weight;
}

const char * Treadmill::getFunction() const
{
	return function;
}

double Treadmill::getMaxSpeed() const
{
	return maxSpeed;
}

double Treadmill::getWeight() const
{
	return weight;
}
