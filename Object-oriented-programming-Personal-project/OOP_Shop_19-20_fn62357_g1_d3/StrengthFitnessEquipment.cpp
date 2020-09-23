#include "StrengthFitnessEquipment.h"
#include <cstring>



StrengthFitnessEquipment::StrengthFitnessEquipment()
{
	type = Category::StrengthFitnessEquipment;
	setExercisePart("");
	setColor("");
	setSize(0);
}

StrengthFitnessEquipment::StrengthFitnessEquipment(const char * _part, const char * _color, double _size)
{
	
	setExercisePart(_part);
	setColor(_color);
	setSize(_size);
}

StrengthFitnessEquipment::StrengthFitnessEquipment(const StrengthFitnessEquipment & cpy)
{
	setExercisePart(cpy.exercisePart);
	setColor(cpy.color);
	setSize(cpy.size);
}

StrengthFitnessEquipment & StrengthFitnessEquipment::operator=(const StrengthFitnessEquipment & cpy)
{
	if (this != &cpy)
	{
		setExercisePart(cpy.exercisePart);
		setColor(cpy.color);
		setSize(cpy.size);
	}
	return *this;
}

StrengthFitnessEquipment::~StrengthFitnessEquipment()
{
	delete[] exercisePart;
	delete[] color;
}

void StrengthFitnessEquipment::setExercisePart(const char * _part)
{
	if (_part == nullptr) return;
	int Length = strlen(_part);
	char* temp = new char[Length + 1];
	strcpy(temp, _part);
	delete[] exercisePart;
	exercisePart = temp;
}

void StrengthFitnessEquipment::setColor(const char * _color)
{
	if (_color == nullptr) return;
	int Length = strlen(_color);
	char* temp = new char[Length + 1];
	strcpy(temp, _color);
	delete[] color;
	color = temp;
}

void StrengthFitnessEquipment::setSize(double _size)
{
	this->size = _size;
}

const char * StrengthFitnessEquipment::getExercisePart() const
{
	return exercisePart;
}

const char * StrengthFitnessEquipment::getColor() const
{
	return color;
}

double StrengthFitnessEquipment::getSize() const
{
	return size;
}
