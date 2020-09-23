#include "Cart.h"
#include <iostream>
using namespace std;


Cart::Cart()
{
} 

void Cart::addToCart( Product* p)
{
		productsCart.push_back(p);
		int newCount = p->getCount() - 1;
		p->setCount(newCount);
}

void Cart::removeFromCart(const int& index)
{
	if (index >= productsCart.size() && index < 0)	
		cout << "The product is not available" << endl;
	else
	{
		productsCart.erase(productsCart.begin() + index);
	}
}

void Cart::printCart() const
{
	cout << endl;
	cout << "------------------------------------" << endl;
	cout << "          Products in cart          " << endl;
	cout << "------------------------------------" << endl;
	if (productsCart.size() > 0)
	{
		int element = 0;
		for (auto& i : productsCart) {
			cout << endl << " Product Numer: " << element << endl;
			i->print(cout);
			element++;
		}
		cout << endl;
	}
	else {
		cout << "No products to show" << endl;
	}
}
