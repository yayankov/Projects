#include "Cart.h"
#include <iostream>



Cart::Cart()
{
}

Cart::Cart(const Cart & cpy)
{
	for (int i = 0; i < products.size(); i++)
	{
		this->products[i] = cpy.products[i]->clone();
	}
}

Cart & Cart::operator=(const Cart & cpy)
{
	if (this != &cpy)
	{
		for (size_t i = 0; i < cpy.products.getSize(); i++)
		{
			delete cpy.products[i];
		}

		products.deallocateValues();

		for (int i = 0; i < cpy.products.getSize(); i++)
		{
			products.pushBack(cpy.products[i]->clone());
		}
	}
	return *this;
}

void Cart::addToCart(Cart * p)
{
	products.pushBack(p->clone());

}

Cart::~Cart()
{
	for (int i = 0; i < products.getSize(); i++)
	{
		delete products[i];
	}
	products.deallocateValues();
}

void Cart::addToCart(const Product & p)
{
	products.pushBack(product);
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
