#pragma once
#define _CRT_SECURE_NO_WARNINGS

class StrengthFitnessEquipment
{
	char* exercisePart = nullptr;
	char* color = nullptr;
	double size;

public:
	StrengthFitnessEquipment();
	StrengthFitnessEquipment(const char*, const char*, double);
	StrengthFitnessEquipment(const StrengthFitnessEquipment&);
	StrengthFitnessEquipment& operator=(const StrengthFitnessEquipment&);
	~StrengthFitnessEquipment();

	//setters
	void setExercisePart(const char*);
	void setColor(const char*);
	void setSize(double);

	//getters
	const char* getExercisePart() const;
	const char* getColor() const;
	double getSize() const;
};