#include "FitnessZone.h"



FitnessZone::FitnessZone()
{
	this->capacity = 0;
}

FitnessZone::FitnessZone(const FitnessZone & cpy)
{
	setCapacity(cpy.capacity);
}

FitnessZone & FitnessZone::operator=(const FitnessZone & cpy)
{
	if (this != & cpy)
	{
		setCapacity(cpy.capacity);
	}
	return *this;
}


FitnessZone::~FitnessZone()
{
}

void FitnessZone::setCapacity(int _capacity)
{
	this->capacity = _capacity;
}

int FitnessZone::getCapacity() const
{
	return this->capacity;
}
