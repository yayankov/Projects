#include "Indoor.h"
#include<iostream>
#include<string>
#include <limits>

using namespace std;

Indoor::Indoor(product type) : Product(type), weight(0)
{
}

istream& Indoor::input(istream& in)
{
	Product::input(in);
	cout << "Enter weight: ";
	while (!(in >> weight)) {
		in.clear();
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	return in;
}

ostream & Indoor::print(std::ostream & out) const
{
	Product::print(out);
	out << "\n Weight: " << weight <<endl << endl;
	out << "------------------------------------" << endl;
	return out;
}
