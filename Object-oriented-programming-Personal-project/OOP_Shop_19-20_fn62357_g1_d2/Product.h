#pragma once
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
extern unsigned int SKU;

class Product
{
	unsigned int currSKU;
	char* brand = nullptr;
	double price;
	unsigned int count;

	void copy(const Product& p);

public:

	Product();
	Product(const char* brand, const double price, const unsigned int count);
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();

	//getters
	const unsigned int getSKU()const;
	const char* getBrand()const;
	const double getPrice()const;
	const unsigned int getCount()const;

	//setters
	void incrementSKU();
	void setBrand(const char*);
	void setPrice(double);
	void setCount(unsigned int);

	void print() const;


};