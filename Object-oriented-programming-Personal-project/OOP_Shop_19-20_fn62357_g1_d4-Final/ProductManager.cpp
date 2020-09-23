#include "ProductManager.h"
#include<iomanip>
#include<iostream>
#include<string>
#include <limits>

using namespace std;

Product * ProductManager::getNewProduct()
{
	cout << "\nType of products: \n1. Nutritional Supplement\n2. Outdoor Equipment\n3. Strength Fitness Equipment\n4. Treadmill\n" << endl;
	cout << "Enter type of product to add: ";
	int index;
	cin >> index;
	Product* p = nullptr;
	switch(index)
	{
		case 1:
			p = new NutritionalSupplement(); 
			break;
		case 2: 
			p = new Equipment(); 
			break;
		case 3: 
			p = new StrengthFitnessEquipment(); 
			break;
		case 4: 
			p = new Treadmill(); 
			break;
	}
	cout << endl;
	cout << "Enter a new product: " << endl;
	cin >> *p;
	cout << endl;
	return p;
}

ProductManager::ProductManager()
{
}

const int & ProductManager::getNumProducts() const
{
	return products.size();
}

Product * ProductManager::getProduct(const int & pos) const
{
	return products[pos];
}

void ProductManager::add()
{
	Product* product = getNewProduct();
	cout << product;
	if (product != nullptr)
	{
		products.push_back(product);

	}
}

void ProductManager::change()
{
	cout << "Enter number of product to change:";
	int pos;

	while (!(cin >> pos)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	if (pos >= 0 && pos < products.size())
	{
		Product* productToAdd = getNewProduct();
		if (productToAdd != nullptr)
		{
			products[pos] = productToAdd;
		}
	}
	else
	{
		cout << "Wrong position " << endl;
	}
}

void ProductManager::remove()
{
	cout << "Enter number of product to remove:";
	int pos;

	while (!(cin >> pos)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	if (pos >= 0 && pos < products.size())
	{
		products.erase(products.begin() + pos);
	}
	else
	{
		cout << "Wrong position " << endl;
	}
}

void ProductManager::printStore() const
{
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "          Products in shop          " << endl;
	cout << "------------------------------------" << endl;
	if (products.size() > 0)
	{
		int element = 0;
		for (auto& i : products) {
			cout << endl << " Product number: " << element << endl;
			i->print(cout);
			element++;
		}
		cout << endl;
	}
	else {
		cout << "No products to show" << endl;
	}
}

void ProductManager::filterByPrice(double min, double max) const
{
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "         Filtered products          " << endl;
	cout << "------------------------------------" << endl;
	if (products.size() > 0)
	{
		int element = 0;
		for (auto& i : products) {
			if (i->getPrice() >= min && i->getPrice() <= max)
			{
				cout << endl << " Product number: " << element << endl;
				i->print(cout);
				element++;
			}
		}
		cout << endl;
	}
	else {
		cout << "No products to show" << endl;
	}
}
