#pragma once
#define _CRT_SECURE_NO_WARNINGS

class NutritionalSupplement
{
	char* expirationDate = nullptr;
	char* ingredients = nullptr;
	double weight;

public:
	NutritionalSupplement();
	NutritionalSupplement(const char*, const char*, double);
	NutritionalSupplement(const NutritionalSupplement&);
	NutritionalSupplement& operator=(const NutritionalSupplement&);
	~NutritionalSupplement();

	//setters
	void setExpirationDate(const char*);
	void setIngredients(const char*);
	void setWeight(double);

	//getters
	const char* getExpirationDate() const;
	const char* getIngredients() const;
	double getWeight() const;

};