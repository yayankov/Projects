#include "User.h"
#include <iostream>
#include <limits>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

User::User()
{
	cart = Cart();
}

void User::addToCart(Product* product) {
	cart.addToCart(product);
}
void User::removeFromCart() {
	std::cout << "Enter Product number to remove from cart: ";
	int pos; 

	while (!(cin >> pos)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	cart.removeFromCart(pos);
}

void User::printCart() const
{
	cart.printCart();
}
