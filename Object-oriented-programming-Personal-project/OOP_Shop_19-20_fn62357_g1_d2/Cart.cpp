#include "Cart.h"
#include <iostream>


void Cart::incrementSize()
{
	this->sizeCart++;
}

void Cart::decrementSize()
{
	if (getSize() > 0) this->sizeCart--;
}


void Cart::incrementCap()
{
	if (getCap() == 0) this->cap = 2;
	else this->cap *= 2;
}

Cart::Cart() 
{
	sizeCart = 0;
	cap = 0;
}

Cart::Cart(const Cart & cpy)
{
	sizeCart = cpy.sizeCart;
	cap = cpy.cap;
}

Cart & Cart::operator=(const Cart & cpy)
{
	if (this != &cpy)
	{
		sizeCart = cpy.sizeCart;
		cap = cpy.cap;
	}
	return *this;
}

const int Cart::getCap() const
{
	return this->cap;
}

size_t Cart::getSize() const
{
	return this->sizeCart;
}

void Cart::resize()
{
	incrementCap();
	Product** newProducts = new Product*[getCap()];

	for (size_t i = 0; i < getSize(); i++) newProducts[i] = productsCart[i];

	delete[] productsCart;
	productsCart = newProducts;
}

void Cart::add(const Product & p)
{
	if (getSize() == getCap()) resize();
	incrementSize();

	productsCart[getSize() - 1] = new Product(p);
}

bool Cart::remove(const size_t index)
{
	if (index >= getSize())	return 0;
	else
	{
		delete productsCart[index];
		for (size_t i = index; i < getSize() - 1; i++) productsCart[i] = productsCart[i + 1];
		decrementSize();
		return 1;
	}
}

void Cart::printCart() const
{
	for (size_t i = 0; i < getSize(); i++) productsCart[i]->print();
}

Cart::~Cart()
{
	delete[] productsCart;
}

