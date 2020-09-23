#include "Store.h"

void Store::addProduct(Product* product)
{
	products.pushBack(product->clone());
}

bool Store::removeProduct(const int index)
{
	if (index < products.getSize() && index >= 0)
	{
		delete products[index];
		products.remove(products.begin() + index);

		return true;
	}
	return false;
}

bool Store::changeProduct( int index, const Product* product)
{
	if (index >= products.getSize()) return 0;
	else
	{
		products.setElement(index, product);
		return 1;
	}
}

void Store::printStore() const
{
	for (int i = 0; i < products.getSize(); i++)
	{
		products[i]->print();
	}
}

Store::Store()
{
}

Store::Store(const Store & s)
{
	for (int i = 0; i < products.getSize(); i++)
	{
		this->products[i] = s.products[i]->clone();
	}
}

Store & Store::operator=(const Store & s)
{
	if (this != &s)
	{
		for (size_t i = 0; i < s.products.getSize(); i++)
		{
			delete s.products[i];
		}

		products.deallocateValues();

		for (int i = 0; i < s.products.getSize(); i++)
		{
			products.pushBack(s.products[i]->clone());
		}
	}
	return *this;
}

Store::~Store()
{
	for (int i = 0; i < products.getSize(); i++)
	{
		delete products[i];
	}
	products.deallocateValues();
}