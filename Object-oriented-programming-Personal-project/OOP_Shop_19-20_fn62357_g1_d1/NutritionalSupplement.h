#pragma once
class NutritionalSupplement
{
	char* type = nullptr;
	char* ingredients = nullptr;
	double weight;

public:
	NutritionalSupplement();
	NutritionalSupplement(const char*, const char*, double);
	NutritionalSupplement(const NutritionalSupplement&);
	NutritionalSupplement& operator=(const NutritionalSupplement&);
	~NutritionalSupplement();

	//setters
	void setType(const char*);
	void setIngredients(const char*);
	void setWeight(double);

	//getters
	const char* getType() const;
	const char* getIngredients() const;
	double getWeight() const;

};