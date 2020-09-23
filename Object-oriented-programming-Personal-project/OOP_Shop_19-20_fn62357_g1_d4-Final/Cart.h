#pragma once
#include "Product.h"
#include<vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class Cart
{
	vector<Product*> productsCart;

public:
	Cart();

	void addToCart( Product *);
	void removeFromCart(const int&);

	void printCart() const;
};