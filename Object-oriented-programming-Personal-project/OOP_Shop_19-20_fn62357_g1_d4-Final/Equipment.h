#pragma once
#include "Outdoor.h"
#include<iostream>
using namespace std;
#include<string>


#define _CRT_SECURE_NO_WARNINGS

class Equipment : public Outdoor
{
public:
	Equipment();

	virtual Product* clone() const override { return new Equipment(*this); }

};