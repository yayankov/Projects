#pragma once
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

class Cart
{
	Product** productsCart = nullptr;
	size_t sizeCart = 0;
	size_t cap = 0;

	void incrementSize();
	void decrementSize();

	//setters
	void incrementCap();
	void resize();

public:
	Cart();
	Cart(const Cart & cpy);
	Cart& operator=(const Cart & cpy);

	//getters
	const int getCap()const;
	size_t getSize()const;

	void add(const Product& p);
	bool remove(const size_t pos);
	void printCart() const;

	~Cart();
};