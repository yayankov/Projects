#pragma once
class FitnessEquipment
{
	char* category = nullptr;
	char* color = nullptr;
	double size;

public:
	FitnessEquipment();
	FitnessEquipment(const char*, const char*, double);
	FitnessEquipment(const FitnessEquipment&);
	FitnessEquipment& operator=(const FitnessEquipment&);
	~FitnessEquipment();

	//setters
	void setCategory(const char*);
	void setColor(const char*);
	void setSize(double);

	//getters
	const char* getCategory() const;
	const char* getColor() const;
	double getSize() const;
};