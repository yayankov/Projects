#pragma once
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

class Cart
{
	myVector<Product*> products;

public:
	Cart();
	Cart(const Cart & cpy);
	Cart& operator=(const Cart & cpy);

	void addToCart(Cart* p);
	bool removeFromCart(const int pos);
	void printCart() const;

	~Cart();
};