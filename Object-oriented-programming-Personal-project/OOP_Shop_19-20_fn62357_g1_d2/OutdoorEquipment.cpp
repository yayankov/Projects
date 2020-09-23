#include "OutdoorEquipment.h"
#include <cstring>

OutdoorEquipment::OutdoorEquipment()
{
	setMaterial("");
	setUsePlace("");
	setSize(0);
}

OutdoorEquipment::OutdoorEquipment(const char * _mat, const char * _place, double _size)
{
	setMaterial(_mat);
	setUsePlace(_place);
	setSize(_size);
}

OutdoorEquipment::OutdoorEquipment(const OutdoorEquipment & cpy)
{
	setMaterial(cpy.material);
	setUsePlace(cpy.usePlace);
	setSize(cpy.size);
}

OutdoorEquipment & OutdoorEquipment::operator=(const OutdoorEquipment & cpy)
{
	if (this != &cpy)
	{
		setMaterial(cpy.material);
		setUsePlace(cpy.usePlace);
		setSize(cpy.size);
	}
	return *this;
}

OutdoorEquipment::~OutdoorEquipment()
{
	delete[] material;
	delete[] usePlace;
}

void OutdoorEquipment::setMaterial(const char * _mat)
{
	if (_mat == nullptr) return;
	int Length = strlen(_mat);
	char* temp = new char[Length + 1];
	strcpy(temp, _mat);
	delete[] material;
	material = temp;
}

void OutdoorEquipment::setUsePlace(const char * _place)
{
	if (_place == nullptr) return;
	int Length = strlen(_place);
	char* temp = new char[Length + 1];
	strcpy(temp, _place);
	delete[] usePlace;
	usePlace = temp;
}

void OutdoorEquipment::setSize(double _size)
{
	this->size = _size;
}

const char * OutdoorEquipment::getMaterial() const
{
	return material;
}

const char * OutdoorEquipment::getUsePlace() const
{
	return usePlace;
}

double OutdoorEquipment::getSize() const
{
	return size;
}
