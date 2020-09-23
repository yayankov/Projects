#include "Store.h"
#include <limits>

void Store::addToCart()
{
	productManager.printStore();
	cout << "Enter Product number from the list to add in cart: ";
	int pos;

	while (!(cin >> pos)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}

	if (pos >= 0 && pos < productManager.getNumProducts())
	{
		Product* productToAdd = productManager.getProduct(pos)->clone();
		user.addToCart(productToAdd);
	}
}

Store::Store()
{
	productManager = ProductManager();
	user = User();
}

void Store::add()
{
	productManager.add();
}

void Store::remove()
{
	productManager.printStore();
	productManager.remove();
}

void Store::removeFromCart()
{
	user.printCart();
	user.removeFromCart();
}

void Store::change()
{
	productManager.printStore();

	productManager.change();
}

void Store::filterByPrice(double min, double max)
{
	productManager.filterByPrice(min, max);
}

void Store::printStore() const
{
	productManager.printStore();
}

void Store::printCart() const
{
	user.printCart();
}
