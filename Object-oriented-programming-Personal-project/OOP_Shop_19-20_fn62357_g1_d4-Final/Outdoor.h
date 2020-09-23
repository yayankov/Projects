#pragma once
#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include<string>
#include "Product.h"

class Outdoor : public Product
{
	string placeForUse;

protected:
	Outdoor(product type = other);

public:

	virtual istream& input(istream&) override;
	virtual ostream& print(std::ostream&) const override;
};

#endif