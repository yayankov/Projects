#pragma once
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

class OutdoorEquipment: public Product
{
	Category type;
	char* material = nullptr;
	char* usePlace = nullptr;
	double size;

public:
	OutdoorEquipment();
	OutdoorEquipment(const char*, const char*, double);
	OutdoorEquipment(const OutdoorEquipment&);
	OutdoorEquipment& operator=(const OutdoorEquipment&);
	~OutdoorEquipment();

	//setters
	void setMaterial(const char*);
	void setUsePlace(const char*);
	void setSize(double);

	//getters
	const char* getMaterial() const;
	const char* getUsePlace() const;
	double getSize() const;
};