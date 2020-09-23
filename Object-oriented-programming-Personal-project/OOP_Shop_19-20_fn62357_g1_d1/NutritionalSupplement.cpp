#include "NutritionalSupplement.h"
#include <cstring>



NutritionalSupplement::NutritionalSupplement()
{
	setType("");
	setIngredients("");
	setWeight(0);
}

NutritionalSupplement::NutritionalSupplement(const char * _type, const char * _ingredients, double _weight)
{
	setType(_type);
	setIngredients(_ingredients);
	setWeight(_weight);
}

NutritionalSupplement::NutritionalSupplement(const NutritionalSupplement& cpy)
{
	setType(cpy.type);
	setIngredients(cpy.ingredients);
	setWeight(cpy.weight);
}

NutritionalSupplement & NutritionalSupplement::operator=(const NutritionalSupplement & cpy)
{
	if (this != &cpy)
	{
		setType(cpy.type);
		setIngredients(cpy.ingredients);
		setWeight(cpy.weight);
	}
	return *this;
}

NutritionalSupplement::~NutritionalSupplement()
{
	delete[] type;
	delete[] ingredients;
}

void NutritionalSupplement::setType(const char * _type)
{
	if (_type == nullptr) return;
	int Length = strlen(_type);
	char* temp = new char[Length + 1];
	strcpy(temp, _type);
	delete[] type;
	type = temp;
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

const char * NutritionalSupplement::getType() const
{
	return this->type;
}

const char * NutritionalSupplement::getIngredients() const
{
	return this->ingredients;
}

double NutritionalSupplement::getWeight() const
{
	return this->weight;
}
