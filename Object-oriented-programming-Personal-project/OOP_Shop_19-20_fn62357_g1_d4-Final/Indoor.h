#pragma once
#include<iostream>
#include<string>
#include "Product.h"
using namespace std;

class Indoor : public Product
{
	double weight;

protected:
	Indoor(product type = other);

public:
	virtual istream& input(istream&) override;
	virtual ostream& print(ostream&) const override;
};