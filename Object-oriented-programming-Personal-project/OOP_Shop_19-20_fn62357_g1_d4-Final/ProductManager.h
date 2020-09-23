#pragma once
#include<string>
#include<vector>
#include "Product.h"
#include "NutritionalSupplement.h"
#include "Treadmill.h"
#include "Equipment.h"
#include "StrengthFitnessEquipment.h"
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class ProductManager
{
	vector<Product*> products;
	
	Product* getNewProduct();
public:
	ProductManager();

	const int& getNumProducts() const;
	Product* getProduct(const int& pos) const;

	void add();
	void change();
	void remove();

	void printStore() const;
	void filterByPrice(double min, double max) const;
};