#pragma once
#include "ProductManager.h"
#include "User.h"
#include<string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Store
{   
	ProductManager productManager;
	User user;
public:
	Store();

	void add();
	void addToCart();
	void remove();
	void removeFromCart();
	void change(); 

	void filterByPrice(double, double);

	void printStore() const;
	void printCart() const;
};