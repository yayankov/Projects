#pragma once
class FitnessZone
{
	int capacity;

public:
	FitnessZone();
	FitnessZone(const FitnessZone&);
	FitnessZone& operator=(const FitnessZone&);
	~FitnessZone();

	//seters
	void setCapacity(int);

	//getters
	int getCapacity() const;
};