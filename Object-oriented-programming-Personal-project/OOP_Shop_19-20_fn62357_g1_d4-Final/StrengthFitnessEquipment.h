#pragma once
#include "Indoor.h"
#include<string>
#include<iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class StrengthFitnessEquipment : public Indoor
{
public:
	StrengthFitnessEquipment();

	virtual Product* clone() const override { return new StrengthFitnessEquipment(*this); }

};