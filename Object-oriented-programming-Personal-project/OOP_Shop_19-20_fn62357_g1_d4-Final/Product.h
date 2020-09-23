#pragma once
#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	enum product {
		nutritionalSupplement,
		equipment,
		strengthFitnessEquipment,
		treadmill,
		other
	};
	
	friend istream& operator>>(istream&, Product&);
	friend ostream& operator<<(ostream&, const Product::product&);

	Product(product type = other);

	const int getInStock() const { return count; }

	virtual Product* clone() const = 0;
	virtual ostream& print(ostream&) const;

	void setCount(int);
	const int getCount() const;
	const double getPrice() const;

protected:
	product type;
	string name;
	string brand;
	string description;
	double price;
	int count;

	virtual istream& input(istream&);
	
};
 istream& operator>>(istream&, const Product&);
 ostream& operator<<(ostream&, const Product::product&); 