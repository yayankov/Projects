#include "Outdoor.h"

#include<iostream>
using namespace std;

Outdoor::Outdoor(product type) : Product(type), placeForUse("")
{
}

istream& Outdoor::input(istream& in)
{
	Product::input(in);

	cout << "Enter place for use: ";
	in.ignore();
	getline(in, placeForUse);
	
	return in;
}

ostream & Outdoor::print(std::ostream & out) const
{
	Product::print(out);
	out << "\n Place for use: " << placeForUse << endl;
	out <<  "------------------------------------" << endl;
	return out;
}
