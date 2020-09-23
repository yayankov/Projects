#pragma once
#include "Product.h"
#include "Cart.h"
#define _CRT_SECURE_NO_WARNINGS

class Store
{   
	Product** products = nullptr;
	size_t size = 0;
	size_t cap = 0;

	void incrementSize();
	void decrementSize();

	//setters
	void incrementCap();
	void resize();

public:
	//getters
	const int getCap()const;
	size_t getSize()const;

	void addProduct(const Product&);
	bool removeProduct(const size_t index);
	bool changeProduct(unsigned int, const Product&);
	void printStore()const;

	~Store();
};