#pragma once
#include "Product.h"
#include "Cart.h"
#include "Vector.h"
#define _CRT_SECURE_NO_WARNINGS

class Store
{   
	myVector<Product*> products;

public:
	Store();
	Store(const Store& s);
	Store& operator=(const Store& s);
	~Store();

	void addProduct(Product* product);
	bool removeProduct(const int index);
	bool changeProduct( int, const Product* product);
	void printStore()const;

	~Store();
};