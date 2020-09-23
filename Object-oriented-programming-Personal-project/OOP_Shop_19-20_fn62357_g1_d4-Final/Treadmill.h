#pragma once
#include "Indoor.h"
#include<string>
#include<iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Treadmill : public Indoor
{
public:
	Treadmill();

	virtual Product* clone() const override { return new Treadmill(*this); }

};