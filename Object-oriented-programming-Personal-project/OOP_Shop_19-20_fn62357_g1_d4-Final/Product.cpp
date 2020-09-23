#include "Product.h"
#include <iostream>
#include<limits>
using namespace std;

Product::Product(Product::product _type) : price(0), count(0)
{
	type = _type;
}

istream& Product::input(istream& in)
{
	cout << "Enter name: ";
	in.ignore();
	getline(in, name);

	cout << "Enter brand: ";
	in >> brand;

	cout << "Enter description: ";
	in.ignore();
	getline(in, description);

	cout << "Enter price: ";
	while (!(in >> price)) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	cout << "Enter count: ";
	while (!(in >> count)) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}

	return in;
}

ostream & Product::print(std::ostream & out) const
{
	out << type << "\n Name: " << name <<
		"\n Brand: " << brand <<
		"\n Description: " << description <<
		"\n Price: " << price <<
		"\n Count: " << count;
	return out;
}

void Product::setCount(int _count)
{
	count = _count;
}

	const int Product::getCount() const
{
	return count;
}

const double Product::getPrice() const
{
	return price;
}

ostream& operator<<(std::ostream& out, const Product::product& type)
{
	if (type == Product::nutritionalSupplement)
	{
		out << " Category: Nutritional Supplementaptop";
	}
	else if (type == Product::equipment)
	{
		out << " Category: Outdoor Equipment";
	}
	else if (type == Product::strengthFitnessEquipment)
	{
		out << " Category: Strength Fitness Equipment";
	}
	else if (type == Product::treadmill)
	{
		out << " Category: Treadmill";
	}
	return out;
}

istream& operator>>(istream& in, Product& product)
{
	return product.input(in);
}
