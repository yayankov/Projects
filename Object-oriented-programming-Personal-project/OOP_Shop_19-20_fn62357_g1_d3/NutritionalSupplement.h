#pragma once
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

class NutritionalSupplement : public Product
{
	Category type;
	char* expirationDate = nullptr;
	char* ingredients = nullptr;
	double weight;

public:
	NutritionalSupplement();
	NutritionalSupplement(const char * brand, double price,
		int count, const char * _date, const char * _ingredients, double _weight);

	//setters
	void setExpirationDate(const char*);
	void setIngredients(const char*);
	void setWeight(double);

	//getters
	const char* getExpirationDate() const;
	const char* getIngredients() const;
	double getWeight() const;

};