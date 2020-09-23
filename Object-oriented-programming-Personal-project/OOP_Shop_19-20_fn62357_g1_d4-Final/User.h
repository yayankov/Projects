#ifndef USER_H
#define USER_H
#include "Cart.h"
#include<string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class User {
private:

	Cart cart;
public:
	User();

	void addToCart(Product *);
	void removeFromCart();
	void printCart() const;

};

#endif