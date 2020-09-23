#pragma once
#include "Outdoor.h"
#include<iostream>
#include<string>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class NutritionalSupplement : public Outdoor
{
public:
	NutritionalSupplement();

	virtual Product* clone() const override { return new NutritionalSupplement(*this); }

};