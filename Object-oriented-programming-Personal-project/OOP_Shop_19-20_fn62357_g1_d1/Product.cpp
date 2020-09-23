#include "Product.h"
#include <cstring>



Product::Product()
{
	setName("");
	setBrand("");
	setId("");
	setPrice(0);
}

Product::Product(const char * _name, const char * _brand, const char * _id, double _price)
{
	setName(_name);
	setBrand(_brand);
	setId(_id);
	setPrice(_price);
}

Product::Product(const Product& cpy)
{
	setName(cpy.name);
	setBrand(cpy.brand);
	setId(cpy.id);
	setPrice(cpy.price);
}

Product & Product::operator=(const Product & cpy)
{
	if (this != &cpy)
	{
		setName(cpy.name);
		setBrand(cpy.brand);
		setId(cpy.id);
		setPrice(cpy.price);
	}
	return *this;

}

Product::~Product()
{
	delete[] name;
	delete[] brand;
	delete[] id;
}

void Product::setName(const char * _name)
{
	if (_name == nullptr) return;
	int Length = strlen(_name);
	char* temp = new char[Length + 1];
	strcpy(temp, _name);
	delete[] name;
	name = temp;
}

void Product::setBrand(const char * _brand)
{
	if (_brand == nullptr) return;
	int Length = strlen(_brand);
	char* temp = new char[Length + 1];
	strcpy(temp, _brand);
	delete[] brand;
	brand = temp;

}

void Product::setId(const char * _id)
{
	if (_id == nullptr) return;
	int Length = strlen(_id);
	char* temp = new char[Length + 1];
	strcpy(temp, _id);
	delete[] id;
	id = temp;

}

void Product::setPrice(double _price)
{
	price = _price;
}

const char * Product::getName() const
{
	return this->name;
}

const char * Product::getBrand() const
{
	return this->brand;
}

const char * Product::getId() const
{
	return this->id;
}

double Product::getPrice() const
{
	return this->price;
}
