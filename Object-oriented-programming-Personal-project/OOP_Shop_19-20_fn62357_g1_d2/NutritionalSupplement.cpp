#include "NutritionalSupplement.h"
#include <cstring>



NutritionalSupplement::NutritionalSupplement()
{
	setExpirationDate("");
	setIngredients("");
	setWeight(0);
}

NutritionalSupplement::NutritionalSupplement(const char * _date, const char * _ingredients, double _weight)
{
	setExpirationDate(_date);
	setIngredients(_ingredients);
	setWeight(_weight);
}

NutritionalSupplement::NutritionalSupplement(const NutritionalSupplement& cpy)
{
	setExpirationDate(cpy.expirationDate);
	setIngredients(cpy.ingredients);
	setWeight(cpy.weight);
}

NutritionalSupplement & NutritionalSupplement::operator=(const NutritionalSupplement & cpy)
{
	if (this != &cpy)
	{
		setExpirationDate(cpy.expirationDate);
		setIngredients(cpy.ingredients);
		setWeight(cpy.weight);
	}
	return *this;
}

NutritionalSupplement::~NutritionalSupplement()
{
	delete[] expirationDate;
	delete[] ingredients;
}

void NutritionalSupplement::setExpirationDate(const char * _date)
{
	if (_date == nullptr) return;
	int Length = strlen(_date);
	char* temp = new char[Length + 1];
	strcpy(temp, _date);
	delete[] expirationDate;
	expirationDate = temp;
}

void NutritionalSupplement::setIngredients(const char * _ingredients)
{
	if (_ingredients == nullptr) return;
	int Length = strlen(_ingredients);
	char* temp = new char[Length + 1];
	strcpy(temp, _ingredients);
	delete[] ingredients;
	ingredients = temp;
}

void NutritionalSupplement::setWeight(double _weight)
{
	this->weight = _weight;
}

const char * NutritionalSupplement::getExpirationDate() const
{
	return this->expirationDate;
}

const char * NutritionalSupplement::getIngredients() const
{
	return this->ingredients;
}

double NutritionalSupplement::getWeight() const
{
	return this->weight;
}
