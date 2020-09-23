#include "FitnessEquipment.h"
#include <cstring>



FitnessEquipment::FitnessEquipment()
{
	setCategory("");
	setColor("");
	setSize(0);
}

FitnessEquipment::FitnessEquipment(const char * _category, const char * _color, double _size)
{
	setCategory(_category);
	setColor(_color);
	setSize(_size);
}

FitnessEquipment::FitnessEquipment(const FitnessEquipment & cpy)
{
	setCategory(cpy.category);
	setColor(cpy.color);
	setSize(cpy.size);
}

FitnessEquipment & FitnessEquipment::operator=(const FitnessEquipment & cpy)
{
	if (this != & cpy)
	{
		setCategory(cpy.category);
		setColor(cpy.color);
		setSize(cpy.size);
	}
	return *this;
}

FitnessEquipment::~FitnessEquipment()
{
	delete[] category;
	delete[] color;
}

void FitnessEquipment::setCategory(const char * _category)
{
	if (_category == nullptr) return;
	int Length = strlen(_category);
	char* temp = new char[Length + 1];
	strcpy(temp, _category);
	delete[] category;
	category = temp;
}

void FitnessEquipment::setColor(const char * _color)
{
	if (_color == nullptr) return;
	int Length = strlen(_color);
	char* temp = new char[Length + 1];
	strcpy(temp, _color);
	delete[] color;
	color = temp;
}

void FitnessEquipment::setSize(double _size)
{
	this->size = _size;
}

const char * FitnessEquipment::getCategory() const
{
	return category;
}

const char * FitnessEquipment::getColor() const
{
	return color;
}

double FitnessEquipment::getSize() const
{
	return size;
}
